#include <stdio.h>
#include <stdlib.h>
#include "TDAgrafo.h"


int main(){
	TDAgrafo* grafo;
	grafo=leerGrafoNoDirigido("Grafito.in");

	printf("Matriz de adyacencia: \n");
	imprimirMatrizAdyacencia(grafo);
	printf("----------\n");
	/*
	int vertA = 1;
	int vertB = 3;
	if (adyacenciaNodos(grafo,vertA,vertB)) {
	 	printf("Los vertices %d y %d son adyacentes\n", vertA, vertB);
	}
	else{
	  	printf("Los vertices %d y %d no son adyacentes\n", vertA, vertB);
	}
	*/
	TDAlista *ady = obtenerAdyacentes(grafo,1);
	recorrerLista(ady);
	return 0;
}



