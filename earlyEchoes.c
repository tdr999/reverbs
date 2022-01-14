#include <stdio.h>
#include <math.h>
#include "prototype.h"
#include "prototype.c"
//pierdut precizie dar trecut tou pe 16 biti mai usor de lucrat

short lenBuffer = 4000;

typedef struct buf{
    short BUFFER[4000];
    short indiceBuffer;
    short delaySamples;
} bufferObject;


bufferObject bufferA, bufferB, bufferC, bufferD;;

void append(short a, bufferObject *buffer)
{
    buffer->BUFFER[buffer->indiceBuffer % buffer->delaySamples] = a; //din cauza asta crapa
    buffer->indiceBuffer++;
}

short dequeue(bufferObject *buffer)
{
    return buffer->BUFFER[buffer->indiceBuffer % buffer->delaySamples]; 
}



Word16 early_echoes(Word16 x, Word16 dry, Word16 wet[], Word16 scale, Word16 delay_ms[], bufferObject *bufferA,  bufferObject *bufferB, bufferObject *bufferC, bufferObject *bufferD){
	bufferA->delaySamples = 44.1 * delay_ms[0];
	bufferB->delaySamples = 44.1 * (delay_ms[1]-delay_ms[2]);
	bufferC->delaySamples = 44.1 * (delay_ms[2]-delay_ms[1]-delay_ms[0]);
	bufferD->delaySamples = 44.1 * (delay_ms[3]-delay_ms[2]-delay_ms[1]-delay_ms[0]);
	
	short toAdd[4];
		
		bufferA->indiceBuffer %= bufferA->delaySamples;
		short popat = dequeue(bufferA);
		append(mult(x, scale), bufferA);
		toAdd[0] = add(mult(mult(x, scale), dry), mult(popat, wet[0]));
		append(popat, bufferB);
		
		if(bufferB->indiceBuffer <= bufferB->delaySamples)
			return toAdd[0];
	
		else if (bufferB->indiceBuffer >= bufferB->delaySamples){
	
			bufferB->indiceBuffer %= bufferB->delaySamples;
			popat = dequeue(bufferB);
			append(popat, bufferC);
			toAdd[1] = add(toAdd[0], mult(popat, wet[1]));
			
			if(bufferC->indiceBuffer <= bufferC->delaySamples)
				return toAdd[1];
			
			else if (bufferC->indiceBuffer >= bufferC->delaySamples){
				
				bufferC->indiceBuffer %= bufferC->delaySamples;
				popat = dequeue(bufferC);
				append(popat, bufferD);
				toAdd[2] = add(toAdd[1], mult(popat, wet[2]));
			
				if(bufferD->indiceBuffer <= bufferD->delaySamples)
					return toAdd[2];
				
				else if (bufferD->indiceBuffer >= bufferD->delaySamples){

				bufferD->indiceBuffer %= bufferD->delaySamples;
				popat = dequeue(bufferD);
				toAdd[3] = add(toAdd[2], mult(popat, wet[3]));
			
				return toAdd[3];   
				}
			}
		}
	}


int main()
{
    FILE *input = fopen("intrare.dat", "r+b");
    FILE *outputEchoes = fopen("iesireEchoes.dat", "w+b"); 
    short x, temp;
    int i = 0;
    printf("befor while\n");
    
    Word16 echoes_wet[4] = {WORD16(0.2), WORD16(0.4), WORD16(0.6), WORD16(0.8)};
	Word16 echoes_delay[4] = {50, 80 , 100, 160};
	
	Word16 scale = WORD16(1 / (0.2+0.4+0.6+0.8));
    
    while(fscanf(input, "%hd", &x) != EOF)
    {
        fprintf(outputEchoes, "%hd ", early_echoes(x, WORD16(0.6) , echoes_wet, scale, echoes_delay, &bufferA, &bufferB, &bufferC, &bufferD));

    }
    
    while(i< 44.1*echoes_delay[3]){
    	fprintf(outputEchoes, "%hd ", early_echoes(0, WORD16(0.6) , echoes_wet, scale, echoes_delay, &bufferA, &bufferB, &bufferC, &bufferD));
		i++;
	}

    fclose(input);
    fclose(outputEchoes);
    return 0;

}
