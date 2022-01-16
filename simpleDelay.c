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



Word16 simpleDelay(Word16 x, Word16 dry, Word16 wet, Word16 scale ,Word16 delay_ms, bufferObject *buffer){
	buffer->delaySamples = 44.1*delay_ms;

	buffer->indiceBuffer %= buffer->delaySamples;
	short popat = dequeue(buffer);
		
	append(mult(x, scale), buffer);
	return add(mult(mult(x, scale), dry), mult(popat, wet));
}



int main()
{
	int delay = 90;
    FILE *input = fopen("intrare.dat", "r+b");
    FILE *outputSimple = fopen("iesireSimple.dat", "w+b"); //experimentam cu coada
    short x, temp;
    printf("befor while\n");
    int i=0;
    
    while(fscanf(input, "%hd", &x) != EOF)
    {
        fprintf(outputSimple, "%hd ", simpleDelay(x, WORD16(0.2), WORD16(0.7), WORD16(1), delay, &buffer));
		
    }
    
    buffer.indiceBuffer = 3999;
    while(buffer.indiceBuffer != -1){
    	//printf("%d ", buffer.indiceBuffer);
    	short pop = dequeue(&buffer); 
    	printf("%hd ", pop);
    	fprintf(outputSimple, "%hd ",pop);
    	buffer.indiceBuffer--;
	}

    fclose(input);
    fclose(outputSimple);
    return 0;

}
