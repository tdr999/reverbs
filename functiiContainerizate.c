/*generalizat functiile de reverb si astea */

#include <stdio.h>
#include <math.h>
#include "prototype.h"
#include "prototype.c"


short lenBuffer = 4000;
//ne trebuie 4 buffere separate pentru cele 4 linii paralele

typedef struct buf{
    int BUFFER[4000];
    short indiceBuffer;
    short delaySamples;
    short flagFirstPass; 

} bufferObject;


bufferObject buffer1, buffer2, bufferA, bufferB, bufferC, bufferD;

//implementarea bufferului ca o coada

void append(short a, bufferObject *buffer)
{
	buffer->BUFFER[buffer->indiceBuffer % buffer->delaySamples] = a;
    	buffer->indiceBuffer++;
}

short dequeue(bufferObject *buffer)
{
	return buffer->BUFFER[buffer->indiceBuffer % buffer->delaySamples]; 
}


Word16 simple_delay(Word16 x, Word16 dry, Word16 wet, Word16 scale ,Word16 delay_ms, bufferObject *buffer){
	buffer->delaySamples = 44.1*delay_ms;
	if (buffer->indiceBuffer >= buffer->delaySamples || buffer->flagFirstPass == 1){
		buffer->flagFirstPass = 1;
		buffer->indiceBuffer %= buffer->delaySamples;
		short popat = dequeue(buffer);
		append(mult(x, scale), buffer);
		return add(mult(mult(x, scale), dry), mult(popat, wet));
	}
	else{
		append(mult(x, scale), buffer);
		return mult(mult(x, scale), dry);
	}
}

Word16 early_echoes(Word16 x, Word16 dry, Word16 wet[], Word16 scale, Word16 delay_ms[], bufferObject *bufferA,  bufferObject *bufferB, bufferObject *bufferC, bufferObject *bufferD){
	bufferA->delaySamples = 44.1 * delay_ms[0];
	bufferB->delaySamples = 44.1 * (delay_ms[1]-delay_ms[2]);
	bufferC->delaySamples = 44.1 * (delay_ms[2]-delay_ms[1]-delay_ms[0]);
	bufferD->delaySamples = 44.1 * (delay_ms[3]-delay_ms[2]-delay_ms[1]-delay_ms[0]);
	
	short toAdd[4];
		
	if (bufferA->indiceBuffer >= bufferA->delaySamples || bufferA->flagFirstPass == 1){
		bufferA->flagFirstPass = 1;
		bufferA->indiceBuffer %= bufferA->delaySamples;
		short popat = dequeue(bufferA);
		append(mult(x, scale), bufferA);
		toAdd[0] = add(mult(mult(x, scale), dry), mult(popat, wet[0]));
		append(popat, bufferB);
		
		if(bufferB->indiceBuffer <= bufferB->delaySamples)
			return toAdd[0];
	
		else if (bufferB->indiceBuffer >= bufferB->delaySamples || bufferB->flagFirstPass == 1){
			bufferB->flagFirstPass = 1;
			bufferB->indiceBuffer %= bufferB->delaySamples;
			popat = dequeue(bufferB);
			append(popat, bufferC);
			toAdd[1] = add(toAdd[0], mult(popat, wet[1]));
			
			if(bufferC->indiceBuffer <= bufferC->delaySamples)
				return toAdd[1];
			
			else if (bufferC->indiceBuffer >= bufferC->delaySamples || bufferC->flagFirstPass == 1){
				bufferC->flagFirstPass = 1;
				bufferC->indiceBuffer %= bufferC->delaySamples;
				popat = dequeue(bufferC);
				append(popat, bufferD);
				toAdd[2] = add(toAdd[1], mult(popat, wet[2]));
			
				if(bufferD->indiceBuffer <= bufferD->delaySamples)
					return toAdd[2];
				
				else if (bufferD->indiceBuffer >= bufferD->delaySamples || bufferD->flagFirstPass == 1){
				bufferD->flagFirstPass = 1;
				bufferD->indiceBuffer %= bufferD->delaySamples;
				popat = dequeue(bufferD);
				toAdd[3] = add(toAdd[2], mult(popat, wet[3]));
			
				return toAdd[3];   
				}
			}
		}
	}
	else{
		append(mult(x, scale), bufferA);
		return mult(mult(x, scale), dry);
	}
}

int reverberatingDelay(short x, short dry, short wet, short g, short delay_ms, bufferObject *buffer)
{
    //observatie: tudor, nu uita sa scalezi cu formula aia cu s din platforma
	buffer->delaySamples = 44.1 * delay_ms;
	short s1 = sub(WORD16(0.999), g);
	if (buffer->indiceBuffer >= buffer->delaySamples || buffer->flagFirstPass == 1) //daca s a umplut bufferu
	{
		buffer->flagFirstPass = 1; //ca sa intre in ifu asta de acuma nainte
		buffer->indiceBuffer %= buffer->delaySamples; //ca sa nu depaseasca short; nu afectaza restu de cod
		//scoatem primul esantion din coada
		short popat = dequeue(buffer);
		append(L_add(mult(mult(x, wet), s1), mult(popat, g)), buffer); //apendam in buffer elementul
		return add(mult(x, dry), popat); //returnam elementul proaspat scos
										//din buf, adunat cu semnalul
										//dry aferent
		
			
	}
	else
	{
		append(mult(mult(x, wet), s1), buffer); //primele m esantioane le bagam ne alterate
		return mult(x, dry); //intoarcem primul  esantion curat
	}
}


int AllpassFilter(Word16 x, Word16 g, Word16 delay_ms, bufferObject *buffer){ //facut int ptr ca in conversia implicita de la short la int nu se pierde nimica srry vlad
	buffer->delaySamples = 44.1 * delay_ms;
	
	if(buffer->indiceBuffer >= buffer->delaySamples || buffer->flagFirstPass == 1){
		buffer->flagFirstPass = 1;
		buffer->indiceBuffer %= buffer->delaySamples;
		short popat = dequeue(buffer);
		
		append(L_add(x, mult(popat,g)), buffer);
		return L_add(mult(add(x, mult(popat, g)), -g) , popat); //functia corecta de transfer VLAD
	}
	else{
		append(x, buffer);
		return mult(x,(-g));
	}
}




int main()
{
	FILE *input = fopen("intrare.dat", "r+b");
	FILE *outputReverberating = fopen("revSchroeder.dat", "w+b"); //experimentam cu coada
    FILE *outputAllPass = fopen("allSchroeder.dat", "w+b");
    FILE *outputSimple = fopen("iesireSimple.dat", "w+b");
    FILE *outputEchoes = fopen("iesireEchoes.dat", "w+b");
	short x;
	
	Word16 echoes_wet[4] = {WORD16(0.2), WORD16(0.4), WORD16(0.6), WORD16(0.8)};
	Word16 echoes_delay[4] = {50, 80 , 100, 160};	
	
	while(fscanf(input, "%hd", &x) != EOF)
	{
		fprintf(outputReverberating, "%hd ", reverberatingDelay(x, WORD16(0.6), WORD16(0.4), WORD16(0.8), 80, &buffer1)); //de scos mizeria asta
        fprintf(outputAllPass, "%hd ", AllpassFilter(x, WORD16(0.6) , 80, &buffer2)); 

	}
	rewind(input);
	while(fscanf(input, "%hd", &x) != EOF)
	{
       	fprintf(outputSimple, "%hd ", simple_delay(x, WORD16(0.6) , WORD16(0.4), WORD16(1), 80, &buffer2)); 
	}
	rewind(input);
	while(fscanf(input, "%hd", &x) != EOF)
	{
       	fprintf(outputEchoes, "%hd ", early_echoes(x, WORD16(0.6) , echoes_wet, WORD16(1), echoes_delay, &bufferA, &bufferB, &bufferC, &bufferD)); 
	}
    	
	fclose(input);
	fclose(outputReverberating);
    fclose(outputAllPass);
    fclose(outputEchoes);
	return 0;
	
}
