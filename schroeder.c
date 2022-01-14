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


bufferObject buffer1, buffer2, buffer3, buffer4, buffer5, buffer6; // declaram bufferele de care avem nevoie


void append(short a, bufferObject *buffer)
{
    buffer->BUFFER[buffer->indiceBuffer % buffer->delaySamples] = a;
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





short AllpassFilter(Word16 x, Word16 g, Word16 delay_ms, bufferObject *buffer){ //facut int ptr ca in conversia implicita de la short la int nu se pierde nimica srry vlad
    buffer->delaySamples = 44.1 * delay_ms;
    buffer->indiceBuffer %= buffer->delaySamples;
    short popat = dequeue(buffer);
    append(add(x, mult(popat,g)), buffer);
    return add(mult(add(x, mult(popat, g)), -g) , popat); //functia corecta de transfer VLAD
}




short schroeder(short x, Word16 dry){
    //injumatatire sa nu depasim
    x = shr(x, 1); 
    short copieX = shr(x, 1); // pentru cele 4 linii
    short temp = 0;
    temp = add(temp, reverberatingDelay(copieX, WORD16(0), WORD16(0.999), WORD16(0.5), 35, &buffer1));
    temp = add(temp, reverberatingDelay(copieX, WORD16(0), WORD16(0.999), WORD16(0.5), 40, &buffer2));
    temp = add(temp, reverberatingDelay(copieX, WORD16(0), WORD16(0.999), WORD16(0.5), 45, &buffer3));
    temp = add(temp, reverberatingDelay(copieX, WORD16(0), WORD16(0.999), WORD16(0.5), 50, &buffer4));
    temp = AllpassFilter(temp, WORD16(0.7), 5, &buffer5); 
    // fa functie de resetat bufere pentru reutilizare si eficientizare memorie 

    temp = AllpassFilter(temp, WORD16(0.7), 2, &buffer6);
    temp = add(temp, mult(dry, x));
    return temp;
}




int main()
{
    FILE *input = fopen("intrare.dat", "r+b");
    FILE *outputSchroeder = fopen("iesireSchroeder.dat", "w+b"); //experimentam cu coada
    short x;

    while(fscanf(input, "%hd", &x) != EOF)
    {
        fprintf(outputSchroeder, "%hd ", schroeder(x, WORD16(0.5)));

    }

    fclose(input);
    fclose(outputSchroeder);
    return 0;

}
