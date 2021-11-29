#include <stdio.h>
#include <math.h>


//word16
//la un calcul  atent, sc10 are suficienta memorie cat sa tina un buffer maxim
//de 4500 de esantioane de 16 bit (inseamna 9kilobytes, el are 10k ram)
//in rest, daca citim esantion cu esantion si scriem esantion cu esantion, ar 
//trebui sa avem memorie suficient


//sa incercam totusi un buffer mai mic


short lenBuffer = 4000;
short BUFFER[4000];
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



short reverberating_delay(short x, float dry, float wet, float g, short delay_ms)
{
    //observatie: tudor, nu uita sa scalezi cu formula aia cu s din platforma
	delay_samples = 44.1 * delay_ms;
	if (indiceBuffer >= delay_samples || flagFirstPass == 1) //daca s a umplut bufferu
	{
		flagFirstPass = 1; //ca sa intre in ifu asta de acuma nainte
		indiceBuffer %= delay_samples; //ca sa nu depaseasca short; nu afectaza restu de cod
		//scoatem primul esantion din coada
		short popat = dequeue();
		append((short)(x * wet + popat * g)); //apendam in buffer elementul
		return (short)(x * dry + popat); //returnam elementul proaspat scos
										//din buf, adunat cu semnalul
										//dry aferent
		
			
	}
	else
	{
		append((short)(x * wet)); //primele m esantioane le bagam ne alterate
		return (short)(x * dry); //intoarcem primul  esantion curat
	}
}



int main()
{
	FILE *input = fopen("intrare.dat", "r+b");
	FILE *output = fopen("iesireFastQueue.dat", "w+b"); //experimentam cu coada
	short x, sex;
	
	while(fscanf(input, "%hd", &x) != EOF)
	{
        sex =  (short)(reverberating_delay(x, 0.6, 0.7, 0.8, 80)); //de scos mizeria asta
		fprintf(output, "%hd ", sex);

	}

	
	fclose(input);
	fclose(output);
	return 0;
	
}
