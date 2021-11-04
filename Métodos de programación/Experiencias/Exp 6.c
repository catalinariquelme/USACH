#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int MAX = 1000; // cambiar este número para variar el largo máximo del arreglo


int * crearArray(int largo){
	int i;
	int * arreglo = (int*)malloc(sizeof(int)*largo);
	for (i = 0; i < largo; ++i)
		arreglo[i] = rand()% (MAX/2) + 1;
	return arreglo;
}

int main(){
	srand(time(NULL));
	int largo = rand()% MAX + 1;;
	int * arreglo =  crearArray(largo);
	printf("\n ARREGLO (largo: %d): \n", largo);
	int i;
	for (i = 0; i < largo; ++i)
		printf("%d - ", arreglo[i]);
	
	/*
	El arreglo se llama "arreglo" 
	y su largo está guardado en la variable "largo"
	*/
	/*********** Llame a su función y muestre el resultado aquí ***************/
	
	
	
	/**************************/
	free(arreglo); 
	return 0;
}



