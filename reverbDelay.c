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
    short flagFirstPass; 

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
    if (buffer->indiceBuffer >= buffer->delaySamples || buffer->flagFirstPass == 1) 
    {
        buffer->flagFirstPass = 1; 
        buffer->indiceBuffer %= buffer->delaySamples; 
        short popat = dequeue(buffer);
        append(add(mult(mult(x, wet), s1), mult(popat, g)), buffer); 
        return add(mult(x, dry), popat); 


    }
    else
    {
        append(mult(mult(x, wet), s1), buffer); 
        return mult(x, dry); 
    }
}





int main()
{
    FILE *input = fopen("intrare.dat", "r+b");
    FILE *outputMoorer = fopen("iesireReverberating1.dat", "w+b"); //experimentam cu coada
    short x, temp;
    printf("befor while\n");
    int i = 0;

    while(fscanf(input, "%hd", &x) != EOF)
    {
        fprintf(outputMoorer, "%hd ", reverberatingDelay(x, WORD16(0.2), WORD16(0.7), WORD16(0.8), 90, &buffer));

    }

    fclose(input);
    fclose(outputMoorer);
    return 0;

}
