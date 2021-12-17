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


bufferObject buffer1, buffer2;

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
	short x;
	
	while(fscanf(input, "%hd", &x) != EOF)
	{
		fprintf(outputReverberating, "%hd ", reverberatingDelay(x, WORD16(0.6), WORD16(0.4), WORD16(0.8), 80, &buffer1)); //de scos mizeria asta
        fprintf(outputAllPass, "%hd ", AllpassFilter(x, WORD16(0.6) , 80, &buffer2)); 

	}
    	
	fclose(input);
	fclose(outputReverberating);
    fclose(outputAllPass);
	return 0;
	
}
