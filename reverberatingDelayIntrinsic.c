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



short reverberating_delay(short x, Word16 dry, Word16 wet, Word16 g, short delay_ms)
{
    //observatie: tudor, nu uita sa scalezi cu formula aia cu s din platforma
	delay_samples = 44.1 * delay_ms;
	if (indiceBuffer >= delay_samples || flagFirstPass == 1) //daca s a umplut bufferul
	{
		flagFirstPass = 1; //ca sa intre in ifu asta de acuma inainte
		indiceBuffer %= delay_samples; //ca sa nu depaseasca short; nu afectaza restu de cod
		//scoatem primul esantion din coada
		short popat = dequeue();
		append(L_add(mult(x, wet), mult(popat,g))); //apendam in buffer elementul
		return L_add(mult(x, dry), popat); //returnam elementul proaspat scos
										//din buf, adunat cu semnalul
										//dry aferent
		
			
	}
	else
	{
		append(mult(x , wet)); //primele m esantioane le bagam ne alterate
		return mult(x, dry); //intoarcem primul  esantion curat
	}
}

Word16 AllpassFilter(Word16 x, Word16 g, Word16 delay_ms){
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
	FILE *output = fopen("iesireIntrinsic.dat", "w+b"); //experimentam cu coada
	FILE *outputAll = fopen("iesireAllpass.dat", "w+b");
	Word16 x, retval;
	
	while(fscanf(input, "%hd", &x) != EOF)
	{
        retval = AllpassFilter(x, WORD16(0.6), 80); 
		fprintf(outputAll, "%d ", retval);
		retval =  reverberating_delay(x, WORD16(0.6), WORD16(0.7), WORD16(0.8), 80); 
		fprintf(output, "%d ", retval);
	}
	

	
	fclose(input);
	fclose(output);
	fclose(outputAll);
	return 0;
	
}
