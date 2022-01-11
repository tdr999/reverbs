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



short reverberatingDelay(short x, short dry, short wet, short g, short delay_ms, bufferObject *buffer)
{
    buffer->delaySamples = 44.1 * delay_ms;
    short s1 = sub(WORD16(0.999), g);
    buffer->indiceBuffer %= buffer->delaySamples; 
    short popat = dequeue(buffer);
    append(add(mult(mult(x, wet), s1), mult(popat, g)), buffer); 
    return add(mult(x, dry), popat); 
}





int main()
{
    FILE *input = fopen("intrare.dat", "r+b");
    FILE *outputMoorer = fopen("iesireRevLung.dat", "w+b"); //experimentam cu coada
    short x, temp;
    printf("befor while\n");
    int i = 0;

    while(fscanf(input, "%hd", &x) != EOF)
    {
        fprintf(outputMoorer, "%hd ", reverberatingDelay(x, WORD16(0.2), WORD16(0.7), WORD16(0.8), 90, &buffer));

    }
   while(i < buffer.indiceBuffer){
       fprintf(outputMoorer, "%hd ", buffer.BUFFER[i]);
       i++;

   }

    fclose(input);
    fclose(outputMoorer);
    return 0;

}
