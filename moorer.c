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


short ponderi[] = {   
    WORD16(0.841), WORD16(0.504), WORD16(0.490),
    WORD16(0.379), WORD16(0.380), WORD16(0.346),
    WORD16( 0.289) , WORD16(0.272) , WORD16( 0.192) ,
    WORD16( 0.193) , WORD16( 0.217) , WORD16( 0.181) ,
    WORD16( 0.180) , WORD16( 0.181) , WORD16( 0.176),
    WORD16(0.142) ,  WORD16(0.167) ,  WORD16(0.134    ) 
};//dau cam 5


short intarzieri[] = {   190,  949,  993, 
    1183, 1192, 1315, 
    2021, 2140, 2524, 
    2590, 2625, 2700, 
    3119, 3123, 3202, 
    3268, 3321, 3515 
};//acest vector reprezinta intarzierile cumulate la fiecare indice, dat fiind ca e un filtru fir tapat







short flagFirstPassReflexii[18];




bufferObject bufferRI, buffer1, buffer2, buffer3, buffer4, buffer5, buffer6, buffer7;

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





short AllpassFilter(Word16 x, Word16 g, Word16 delay_ms, bufferObject *buffer){ 
    buffer->delaySamples = 44.1 * delay_ms;

    if(buffer->indiceBuffer >= buffer->delaySamples || buffer->flagFirstPass == 1){
        buffer->flagFirstPass = 1;
        buffer->indiceBuffer %= buffer->delaySamples;
        short popat = dequeue(buffer);

        append(add(x, mult(popat,g)), buffer);
        return add(mult(add(x, mult(popat, g)), -g) , popat); //functia corecta de transfer VLAD
    }
    else{
        append(x, buffer);
        return mult(x,(-g));
    }
}




short flagFirstReset = 0;
short ri(short x, bufferObject *buffer){
    buffer->delaySamples = intarzieri[17];
    append(x, buffer);
    if(flagFirstPassReflexii[17] == 0){
        if (buffer->indiceBuffer == intarzieri[0]){
            flagFirstPassReflexii[0] = 1;
            printf("primu facut 1\n");

        }


        if (buffer->indiceBuffer == intarzieri[1])
            flagFirstPassReflexii[1] = 1;
        if (buffer->indiceBuffer == intarzieri[2])
            flagFirstPassReflexii[2] = 1;
        if (buffer->indiceBuffer == intarzieri[3])
            flagFirstPassReflexii[3] = 1;
        if (buffer->indiceBuffer == intarzieri[4])
            flagFirstPassReflexii[4] = 1;
        if (buffer->indiceBuffer == intarzieri[5])
            flagFirstPassReflexii[5] = 1;
        if (buffer->indiceBuffer == intarzieri[6])
            flagFirstPassReflexii[6] = 1;
        if (buffer->indiceBuffer == intarzieri[7])
            flagFirstPassReflexii[7] = 1;
        if (buffer->indiceBuffer == intarzieri[8])
            flagFirstPassReflexii[8] = 1;
        if (buffer->indiceBuffer == intarzieri[9])
            flagFirstPassReflexii[9] = 1;
        if (buffer->indiceBuffer == intarzieri[10])
            flagFirstPassReflexii[10] = 1;
        if (buffer->indiceBuffer == intarzieri[11])
            flagFirstPassReflexii[11] = 1;
        if (buffer->indiceBuffer == intarzieri[12])
            flagFirstPassReflexii[12] = 1;
        if (buffer->indiceBuffer == intarzieri[13])
            flagFirstPassReflexii[13] = 1;
        if (buffer->indiceBuffer == intarzieri[14])
            flagFirstPassReflexii[14] = 1;
        if (buffer->indiceBuffer == intarzieri[15])
            flagFirstPassReflexii[15] = 1;
        if (buffer->indiceBuffer == intarzieri[16])
            flagFirstPassReflexii[16] = 1;
        if (buffer->indiceBuffer == intarzieri[17]){
            flagFirstPassReflexii[17] = 1; 
            printf("de 17 facut1\n");
            flagFirstReset = 1;
        }
    }


    int i, suma = 0;
    for (i = 0; i < 18; i++){
        if (flagFirstPassReflexii[i] == 1 && (buffer->indiceBuffer - intarzieri[i] < 0) ){
            suma = add(suma, mult(buffer->BUFFER[buffer->indiceBuffer  + intarzieri[17] - intarzieri[i]], ponderi[i])); //m am gandit foarte mult la formula asta. indiceCurent+Lungimetotala-intarziere[i]
        }
        else if (flagFirstPassReflexii[i] == 1 ){
            suma = add(suma, mult(buffer->BUFFER[buffer->indiceBuffer - intarzieri[i]], ponderi[i])); //m am gandit foarte mult la formula asta. indiceCurent+Lungimetotala-intarziere[i]
        }

    } 
    buffer->indiceBuffer %= intarzieri[17]; //resetam indicele si ca sa nu depaseasca si ca sa lista circulara


    return suma;


    //initla reflexions da o eroare de scalare fata de python dar in rest se suprapun perfect semnalele, de asemenea o diferenta de cateva sau un esantion esantioane da nu ma prind de ce

}




short moorer(short x, short reglSemnal, short reglReflexii, short reglReverb){
    short reflexiiInit, copieReflexiiInit, iesireComburi = 0, reverbFinal, y;
    float gainComburi = 0.8;
    reflexiiInit = ri(x, &bufferRI);
    copieReflexiiInit = shr(reflexiiInit, 3); //scalare for good measure
    //vom aproxima in milisecunde esantioanele din moorer, pentru ca functia noastra ia milisecunde nu esantioane
    iesireComburi = add(iesireComburi, reverberatingDelay(copieReflexiiInit, 0, WORD16(1), WORD16(gainComburi), 40, &buffer1));
    iesireComburi = add(iesireComburi, reverberatingDelay(copieReflexiiInit, 0, WORD16(1), WORD16(gainComburi), 44, &buffer2));
    iesireComburi = add(iesireComburi, reverberatingDelay(copieReflexiiInit, 0, WORD16(1), WORD16(gainComburi), 48, &buffer3));
    iesireComburi = add(iesireComburi, reverberatingDelay(copieReflexiiInit, 0, WORD16(1), WORD16(gainComburi), 52, &buffer4));
    iesireComburi = add(iesireComburi, reverberatingDelay(copieReflexiiInit, 0, WORD16(1), WORD16(gainComburi), 56, &buffer5));
    iesireComburi = add(iesireComburi, reverberatingDelay(copieReflexiiInit, 0, WORD16(1), WORD16(gainComburi), 60, &buffer6));
    reverbFinal = AllpassFilter(iesireComburi, WORD16(0.8), 7,&buffer7);
    y = add( add( mult(x, reglSemnal), mult(reglReflexii, reflexiiInit)), mult(reglReverb, reverbFinal));

    return y;
}




int main()
{
    FILE *input = fopen("intrare.dat", "r+b");
    FILE *outputMoorer = fopen("iesireMoorer.dat", "w+b"); //experimentam cu coada
    short x, temp;
    printf("befor while\n");

    while(fscanf(input, "%hd", &x) != EOF)
    {
        fprintf(outputMoorer, "%hd ", moorer(x, WORD16(0.5), WORD16(0.5), WORD16(0.5)));

    }
    printf("intarzier de 17 %d\n", intarzieri[17]);

    fclose(input);
    fclose(outputMoorer);
    return 0;

}
