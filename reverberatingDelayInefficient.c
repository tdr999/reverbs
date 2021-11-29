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

//implementarea bufferului ca o coada

void append(short a)
{
	BUFFER[indiceBuffer++] = a;
}

short dequeue()
{
	short temp = BUFFER[0], i ;
    for (i = 0; i < indiceBuffer - 1; i++){ BUFFER[i] = BUFFER[i+1];}	
	indiceBuffer--;
	return temp;
}



short reverberating_delay(short x, float dry, float wet, float g, short delay_ms)
{
	short delay_samples = 44.1 * delay_ms;
//	printf("in rev delay INDICE BUFFER %hd delay samples %d delay ms %d \n", indiceBuffer, delay_samples, delay_ms);
//	printf("wet %f dry %f g %f \n", wet, dry, g);	
	if (indiceBuffer == delay_samples) //daca s a umplut bufferu
	{
		//scoatem primul esantion din coada
		short popat = dequeue();
		append((short)(x * wet + popat * g)); //apendam in buffer elementul
//		printf("scris x * dry + popat %hd * %f + %hd ", x,dry,popat);
//        printf("apendat x * wet + popat * g %hd * %f + %hd * %f\n", x, wet, popat, g);
		return (short)(x * dry + popat); //returnam elementul proaspat scos
										//din buf, adunat cu semnalul
										//dry aferent
		
			
	}
	else
	{
		append((short)(x * wet)); //primele m esantioane le bagam ne alterate
//		printf("scris  x * dry %hd * %f ", x, dry);
//        printf("apendat X * wet %hd * %f\n:", x, wet);
		return (short)(x * dry); //intoarcem primul  esantion curat
	}
}



int main()
{
	FILE *input = fopen("intrare.dat", "r+b");
	FILE *output = fopen("iesireIneff.dat", "w+b");
	short x, sex;
	
	while(fscanf(input, "%hd", &x) != EOF)
	{
	//	printf("%hd ", reverberating_delay(x, 8, 0.8, 0.8, 85 ));
        sex =  (short)(reverberating_delay(x, 0.6, 0.7, 0.8, 80));
		fprintf(output, "%hd ", sex);
      //  printf("indice buffer %hd  val de pe primu loc %hd scrisa %hd \n ", indiceBuffer, BUFFER[0], sex);

	}
	
	
	fclose(input);
	fclose(output);
	return 0;
	
}
