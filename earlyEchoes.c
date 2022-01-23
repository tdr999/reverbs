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

Word16 intarzieri[4];
Word16 echoes_delay[4] = {30, 50 , 80, 90};

Word16 dry = WORD16(0.6);
Word16 wet[4] = {WORD16(0.2), WORD16(0.4), WORD16(0.6), WORD16(0.8)};	
Word16 scale = WORD16(1 / (0.6 + 0.2 + 0.4 + 0.6 + 0.8));

bufferObject buffer;

void append(short a, bufferObject *buffer)
{
    buffer->BUFFER[buffer->indiceBuffer % buffer->delaySamples] = a; //din cauza asta crapa
    buffer->indiceBuffer++;
}

short dequeue(bufferObject *buffer)
{
    return buffer->BUFFER[buffer->indiceBuffer % buffer->delaySamples]; 
}

void MStoSample(Word16 delay[4]){
	int i=0;
	for(i=0;i<4;i++){
		intarzieri[i] = 44.1 * delay[i];
		}
}


Word16 early_echoes(Word16 x, bufferObject *buffer){

    buffer->delaySamples = intarzieri[3]; 
    buffer->indiceBuffer %= intarzieri[3]; 
    append(mult(x,scale), buffer);    
    
    int i, suma = 0;
    for (i = 0; i < 4; i++){
        if (buffer->indiceBuffer - intarzieri[i]<0){
            suma = add(suma, mult(buffer->BUFFER[buffer->indiceBuffer  + intarzieri[3] - intarzieri[i]], wet[i])); 
        } 
        else { 
            suma = add(suma, mult(buffer->BUFFER[buffer->indiceBuffer - intarzieri[i]], wet[i])); 
        }
    } 
	
	Word16 out = add(mult(mult(dry, x),scale), suma);
	return out;
	}

int main()
{
    FILE *input = fopen("intrare.dat", "r+b");
    FILE *outputEchoes = fopen("iesireEchoes.dat", "w+b"); 
    short x, temp;
    int i = 0;
    printf("befor while\n");
	
	MStoSample(echoes_delay);
	
    while(fscanf(input, "%hd", &x) != EOF)
    {	
        fprintf(outputEchoes, "%hd ", early_echoes(x, &buffer));

    }
    
    while(i< 44.1*echoes_delay[3]){
    	fprintf(outputEchoes, "%hd ", early_echoes(0, &buffer));
		i++;
	}

    fclose(input);
    fclose(outputEchoes);
    return 0;

}

