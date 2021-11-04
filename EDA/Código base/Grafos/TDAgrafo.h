#include <stdio.h>
#include <stdlib.h>
#include "TDAlista.h"

/*------------- estructura de datos -------------*/

typedef struct{
	int vertices;
	int** adyacencias;
}TDAgrafo;


/*----------------- operaciones -----------------*/
/*
Entradas: vertices(int)
Salida: grafo
Objetivo: crea grafo de n vértices y m aristas
*/
TDAgrafo* crearGrafoVacio(int vertices) {
	TDAgrafo* grafo = (TDAgrafo*)malloc(sizeof(TDAgrafo));
	grafo->vertices = vertices;
	grafo->adyacencias = (int**)malloc(vertices * sizeof(int*));
	int i,j;
	for (i = 0; i < vertices; i++){
		grafo->adyacencias[i] = (int*)malloc(vertices * sizeof(int));
		for(j = 0;j<vertices;j++){
			grafo->adyacencias[i][j]=0;
		}
	}
	return grafo;
}

/*
Entradas: grafo, vetA(int), vertB(int)
Salida: 1 (son adyacentes)| 0 (no son adyacentes)
Objetivo: verifica si dos vértices son adyacentes
*/
int adyacenciaNodos(TDAgrafo * grafo, int vertA, int vertB) {
	if (grafo->adyacencias[vertA - 1][vertB - 1] == 1){
		return 1;
	}
	return 0;
}

/*
Entradas: grafo
Salida: -
Objetivo: imprime los elementos de matriz de adyacencia
*/
void imprimirMatrizAdyacencia(TDAgrafo* grafo) {
	int i, j;
	for (i = 0; i < grafo->vertices; i++) {
		for (j = 0; j < grafo->vertices; j++) {
			printf("%d ", grafo->adyacencias[i][j]);
		}
		printf("\n");
	}
}


TDAgrafo* leerGrafoNoDirigido(char *nombreArchivo) {
	int numVertices, numAristas;
	int i, verticeInicial, verticeFinal;
	FILE* archivo = fopen(nombreArchivo,"r+");

	if (archivo == NULL){
     	printf("\nError de apertura del archivo. \n\n");
     	return NULL;
   	}
   	else{
   		fscanf(archivo,"%d %d",&numVertices,&numAristas);
   		printf("numVertices: %d -- numAristas: %d\n",numVertices,numAristas);

   		TDAgrafo* grafo=crearGrafoVacio(numVertices);

   		for (i=0;i<numAristas;i++){
	   		fscanf(archivo,"%d %d",&verticeInicial,&verticeFinal);
       		grafo->adyacencias[verticeInicial-1][verticeFinal-1]=1;
       		grafo->adyacencias[verticeFinal-1][verticeInicial-1]=1;
       	}
       	fclose (archivo); 
   		return grafo;
     }
}

/*
Entradas: nombreArchivo(char)
Salida: grafo
Objetivo: lectura de archivo que tiene información gráfo
*/
TDAgrafo* leerGrafo(char *nombreArchivo){
	FILE*arch;		   //para abrir archivo
	arch = fopen(nombreArchivo,"r");
	int n, aristas;
	int i,j,k;
	fscanf(arch, "%d %d", &n,&aristas); //Cantidad de nodos y aristas
	TDAgrafo *grafo=crearGrafoVacio(n);
	//dependiendo de las lineas de archivo , pone 1 para grafo no dirigido
	for(k=0;k<aristas;k++){
		fscanf(arch,"%d %d",&i, &j);
		grafo->adyacencias[i-1][j-1] = 1;
		grafo->adyacencias[j-1][i-1] = 1; // No considerar si es dirigido
	}
	fclose(arch);
	return  grafo;	
}

/*
Entradas: grafo, vértice
Salida: lista
Objetivo: obtener adyacentes de un vértice
*/
TDAlista* obtenerAdyacentes(TDAgrafo* grafo, int vertice){
	TDAlista* lista = crearListaVacia();
	
	//Una opción (forma realziada por la profe)
	/*
	for(int i=0;i < grafo->vertices;i++){
		if(adyacenciaNodos(grafo,vertice,i)){
			insertarInicio(lista,i+1);
		}
	}
	*/
	
	//Otra opción, ambas hacen lo mismo
	for(int i=0;i < grafo->vertices;i++){
		if(grafo->adyacencias[vertice-1][i]!=0){
			insertarInicio(lista,i+1);
		}
	}
	return lista;
}

/*
Entradas: grafo, secuencia
Salida: 1 (es camino) |0 (no es camino)
Objetivo: verificar si es camino
*/
int esCamino(TDAgrafo* grafo, TDAlista* secuencia){
	if (!esListaVacia(secuencia)){
		nodo *aux = secuencia->inicio;
		while(aux->siguiente != NULL){
			if( !adyacenciaNodos(grafo, aux->dato, aux->siguiente->dato)){
				return 0;
			}
			aux = aux->siguiente;
		}
	}
	return 1;
}

/*
Entradas: grafo, secuencia
Salida: 1(es ciclo) |0 (no es ciclo)
Objetivo: verificar si es ciclo
*/
int esCiclo(TDAgrafo* grafo, TDAlista* secuencia){
	int nodoInicial;
	int nodoFinal;
	//Se verifica que la secuencia no se encuentre vácia
	if(!esListaVacia(secuencia)){
		nodo *aux = secuencia->inicio;
		nodoInicial = aux->dato;
		//Se recorre para ver si nodo final es igual al nodo inicial
		while(aux->siguiente != NULL){
			aux = aux-> siguiente;
		}
		nodoFinal = aux->dato;
		if(nodoInicial != nodoFinal){
			return 0;
		}
		else if(!esCamino(grafo,secuencia)){
			return 0;
		}
	}
	return 1;
}

