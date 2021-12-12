#include <stdio.h>
#include <math.h>
#include "prototype.h"
#include "prototype.c"

//word16
//la un calcul  atent, sc10 are suficienta memorie cat sa tina un buffer maxim
//de 4500 de esantioane de 16 bit (inseamna 9kilobytes, el are 10k ram)
//in rest, daca citim esantion cu esantion si scriem esantion cu esantion, ar 
//trebui sa avem memorie suficient


//sa incercam totusi un buffer mai mic


short lenBuffer = 4000;
int BUFFER[4000];
short indiceBuffer = 0;
short delay_samples = 0;
short flagFirstPass = 0; //vom folosi dupa ce se umple buffeerul prima data


//implementarea bufferului ca o coada

void append(short a)
{
	BUFFER[indiceBuffer % delay_samples] = a;
    	indiceBuffer++;
}

short dequeue()
{
	return BUFFER[indiceBuffer % delay_samples]; 
}



int reverberating_delay(short x, short dry, short wet, short g, short delay_ms)
{
    //observatie: tudor, nu uita sa scalezi cu formula aia cu s din platforma
	delay_samples = 44.1 * delay_ms;
	short s1 = sub(WORD16(0.999), g);
	if (indiceBuffer >= delay_samples || flagFirstPass == 1) //daca s a umplut bufferu
	{
		flagFirstPass = 1; //ca sa intre in ifu asta de acuma nainte
		indiceBuffer %= delay_samples; //ca sa nu depaseasca short; nu afectaza restu de cod
		//scoatem primul esantion din coada
		short popat = dequeue();
		append(L_add(mult(mult(x, wet), s1), mult(popat, g))); //apendam in buffer elementul
		return add(mult(x, dry), popat); //returnam elementul proaspat scos
										//din buf, adunat cu semnalul
										//dry aferent
		
			
	}
	else
	{
		append(mult(mult(x, wet), s1)); //primele m esantioane le bagam ne alterate
		return mult(x, dry); //intoarcem primul  esantion curat
	}
}





int AllpassFilter(Word16 x, Word16 g, Word16 delay_ms){ //facut int ptr ca in conversia implicita de la short la int nu se pierde nimica srry vlad
	delay_samples = 44.1 * delay_ms;
	
	if(indiceBuffer>= delay_samples || flagFirstPass == 1){
		flagFirstPass = 1;
		indiceBuffer %= delay_samples;
		short popat = dequeue();
		
		append(L_add(x, mult(popat,g)));
		return L_add(mult(x,(-g)),popat);
	}
	else{
		append(x);
		return mult(x,(-g));
	}
}




int main()
{
	FILE *input = fopen("intrare.dat", "r+b");
	FILE *outputReverberating = fopen("iesireReverberating.dat", "w+b"); //experimentam cu coada
    FILE *outputAllPass = fopen("iesireAllPass.dat", "w+b");
	short x;
	
	while(fscanf(input, "%hd", &x) != EOF)
	{
		fprintf(outputReverberating, "%hd ", reverberating_delay(x, WORD16(0.6), WORD16(0.4), WORD16(0.8), 80)); //de scos mizeria asta
	}
    indiceBuffer = 0; // reset buffer 
    rewind(input); //trebe resetat si pointeru din functia de citire ca sa citim iar
    while(fscanf(input, "%hd", &x) != EOF)
	{
       	fprintf(outputAllPass, "%hd ", AllpassFilter(x, WORD16(0.6) , 80)); 
	}

	
	fclose(input);
	fclose(outputReverberating);
    fclose(outputAllPass);
	return 0;
	
}
