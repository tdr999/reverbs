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
    buffer->BUFFER[buffer->indiceBuffer % buffer->delaySamples] = a; 
    buffer->indiceBuffer++;
}

short dequeue(bufferObject *buffer)
{
    return buffer->BUFFER[buffer->indiceBuffer % buffer->delaySamples]; 
}


short AllpassFilter(Word16 x, Word16 g, Word16 delay_ms, bufferObject *buffer){ 
    buffer->delaySamples = 44.1 * delay_ms; //calculam numarul de samples
    buffer->indiceBuffer %= buffer->delaySamples; //resetam indicele buffer
    short popat = dequeue(buffer);
    append(add(x, mult(popat,g)), buffer); //adaugam in buffer
    return add(mult(add(x, mult(popat, g)), -g) , popat); //implementarea diagramei
}




int main()
{
    FILE *input = fopen("intrare.dat", "r+b");
    FILE *outputMoorer = fopen("iesireAllpassPadding.dat", "w+b"); //experimentam cu coada
    short x, temp, delay = 90;
    printf("befor while\n");
    int i = 0;
    while(fscanf(input, "%hd", &x) != EOF)
    {
        fprintf(outputMoorer, "%hd ", AllpassFilter(x, WORD16(0.7), delay,  &buffer));

    }
    while(i < delay * 44.1) // golim coada
    {
        fprintf(outputMoorer, "%hd ", AllpassFilter(0, WORD16(0.7), delay,  &buffer));
        i++;

    }

    fclose(input);
    fclose(outputMoorer);
    return 0;

}
