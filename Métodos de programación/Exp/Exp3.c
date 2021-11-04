//Experiencia 3

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>

int * suma(int * primerNumero, int cantDigitos1, int * segundoNumero, int cantDigitos2, int * cantidadDigitosResultado);

int * suma(int * primerNumero, int cantDigitos1, int * segundoNumero, int cantDigitos2, int * cantidadDigitosResultado){
/*Escriba su código aquí*/

    //En el caso que el segundo número sea más largo
	if (cantDigitos1<=cantDigitos2){
        int i,largoNumero,largoNumero2,j;
        //Se crea un array dinamico para guardar el resultado de la suma
        int * numeroCeros = (int *) malloc(sizeof(int)*cantDigitos2);
        //Se llena de 0 el array
        for (i=0;i<cantDigitos2;i++){
            numeroCeros[i]=0;
        }
        largoNumero = cantDigitos1;
        largoNumero2 = cantDigitos2;
        //Se llena de 0 lo que queda de número, nivelandolo con el otro uwu
        for (i=0;i<cantDigitos1;i++){
            numeroCeros[largoNumero2-1] = primerNumero[largoNumero-1];
            largoNumero-=1;
            largoNumero2-=1;
        }
        //Se cambia el array antiguo del primer número por el que contiene 0
        primerNumero = numeroCeros;
        int cantidadNumeros,suma,posicion,resto;
        cantidadNumeros = cantDigitos2;
        posicion = cantidadNumeros;
        int resultado[cantidadNumeros+1];
        //se llena de 0 el array que contedrá el resultado
        for(i=0; i<cantidadNumeros+1;i++){
            resultado[i] = 0;
        }
        //Se realiza la suma
        for(i=0; i<cantidadNumeros;i++){
            suma = segundoNumero[posicion-1]+primerNumero[posicion-1];
            if(suma < 10){
                resultado[posicion] = suma;
            }
            else if(suma >= 10){
                resto = suma%10;
                resultado[posicion] = resto;
                segundoNumero[posicion-2] = segundoNumero[posicion-2]+1;
            }
            posicion-=1;
        }
        //Se muestra por pantalla el resultado
        for(i=0; i<cantidadNumeros+1;i++){
            printf("%d",resultado[i]);
        }
        printf("\n");
    }
else if (cantDigitos1>cantDigitos2){
        int i,largoNumero,largoNumero2,j;
        //Se crea un array dinamico para guardar el resultado de la suma
        int * numeroCeros = (int *) malloc(sizeof(int)*cantDigitos1);
        //Se llena de 0 el array
        for (i=0;i<cantDigitos1;i++){
            numeroCeros[i]=0;
        }
        largoNumero = cantDigitos1;
        largoNumero2 = cantDigitos2;
        //Se llena de 0 lo que queda de número, nivelandolo con el otro uwu
        for (i=0;i<cantDigitos2;i++){
            numeroCeros[largoNumero-1] = segundoNumero[largoNumero2-1];
            largoNumero-=1;
            largoNumero2-=1;
        }
        //Se cambia el array antiguo del primer número por el que contiene 0
        segundoNumero = numeroCeros;
        int cantidadNumeros,suma,posicion,resto;
        cantidadNumeros = cantDigitos1;
        posicion = cantidadNumeros;
        int resultado[cantidadNumeros+1];
        //se llena de 0 el array que contedrá el resultado
        for(i=0; i<cantidadNumeros+1;i++){
            resultado[i] = 0;
        }
        //Se realiza la suma
        for(i=0; i<cantidadNumeros;i++){
            suma = primerNumero[posicion-1]+segundoNumero[posicion-1];
            if(suma < 10){
                resultado[posicion] = suma;
            }
            else if(suma >= 10){
                resto = suma%10;
                resultado[posicion] = resto;
                primerNumero[posicion-2] = primerNumero[posicion-2]+1;
            }
            posicion-=1;
            
        }
        //Se muestra por pantalla el resultado
        for(i=0; i<cantidadNumeros+1;i++){
            printf("%d",resultado[i]);
        }
        printf("\n");
    }
    //*cantidadDigitosResultado = cantDigitos1+1;
    return 0;
}/*Fin de su código aquí*/


int main(){
	
	srand(time(NULL));
	//Se generan números aleatorios y se almacenan
	int cantDigitos1 = rand()%101 + 1;
	int cantDigitos2 = rand()%101 + 1;
	int *  primerNumero = (int *) malloc(sizeof(int)*cantDigitos1);
	int *  segundoNumero = (int *) malloc(sizeof(int)*cantDigitos2);
	//printf("%d %d\n",cantDigitos1,cantDigitos2);
	int i;
	for (i=0;i<cantDigitos1;i++){
		primerNumero[i]= rand()%9 + 1;
	}
	for (i=0;i<cantDigitos2;i++){
		segundoNumero[i]= rand()%9 + 1;
	}
	printf("  ");
	
	for (i=0;i<cantDigitos1;i++){
		printf("%d",primerNumero[i]);
	}
	printf("\n");
	printf("+ ");

	for (i=0;i<cantDigitos2;i++){
		printf("%d",segundoNumero[i]);
	}
	printf("\n");
	printf("________________________________________________________________________\n");
	int cantidadDigitosResultado = 0;
	
	int * resultadoSuma = suma(primerNumero, cantDigitos1, segundoNumero, cantDigitos2, &cantidadDigitosResultado);
	for (i=0;i<cantidadDigitosResultado;i++){
		printf("%d",resultadoSuma[i]);
	}
	printf("\n");
	free(primerNumero);
	free(segundoNumero);
	free(resultadoSuma);
	
	return 0;
}