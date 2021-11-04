/*
Programa que aplica tres formas conocidas de ordenamiento:
- QuickSort
- MergeSort
- BubbleSort
*/
#include <stdio.h>
#include <stdlib.h>

#include <time.h>//Para trabajar con semillas distintas en el random

/*
Función que copia un arreglo y entrega un arreglo nuevo
Entrada:
	- Arreglo a copiar (Arreglo de enteros)
	- Tamaño de arreglo a copiar (número entero)
Salida:
	- Arreglo copiado (arreglo de enteros)
*/
int* copiarArreglo(int* arregloOriginal, int cantElementos){
	int* arregloCopia = (int*)malloc(sizeof(int)*cantElementos);
	int i = 0;
	for(;i<cantElementos;++i){
		arregloCopia[i]=arregloOriginal[i];
	}
	return arregloCopia;
}

/*
Función que agrega un elemento al final de un arreglo
Entrada:
	- Arreglo donde agregar el elemento (Arreglo de enteros)
	- Tamaño del arreglo donde agregar el elemento (número entero)
	- Elemento a agregar (número entero)
Salida:
	- Arreglo con el elemento agregado (arreglo de enteros)
*/
int* agregarElemento(int* arreglo,int tamanio,int elemento){
	//Genero un arreglo de n+1 elementos
	int * nuevoArreglo = (int*)malloc(sizeof(int)*(tamanio+1));
	int i = 0;
	while(i<tamanio){
		nuevoArreglo[i] = arreglo[i];
		i++;
	}
	nuevoArreglo[tamanio] = elemento;
	free(arreglo);
	return nuevoArreglo;
}

/*
Función que agrega un elemento al final de un arreglo
Entrada:
Salida:
*/
int* concatenar(int* menores, int cantMenores, int pivote, int* mayores, int cantMayores){
	//printf("cantMayores = %d  -  cantMenores = %d\n", cantMayores,cantMenores);
	int* arregloFinal = (int*)malloc(sizeof(int)*(cantMenores+cantMayores+1));
	int i=0;
	while(i<cantMenores){
		arregloFinal[i] = menores[i];
		i++;
		//printf("Copiado Menores: %d = %d\n",arregloFinal[i],menores[i]);
	}
	//printf("Copiando Pivote\n");
	arregloFinal[cantMenores] = pivote;
	//printf("Copiado: %d = %d \n",arregloFinal[cantMenores],pivote);
	i=0;
	while(i<cantMayores){
		arregloFinal[cantMenores+1+i] = mayores[i];
		i++;
		//printf("Copiado: %d = %d\n",arregloFinal[cantMenores+1+i],mayores[i]);
	}
	free(menores);
	free(mayores);
	return arregloFinal;
}

/*
Función que ordena un arreglo de menor a mayor
Entrada:
	- Arreglo a ordenar (Arreglo de enteros)
	- Tamaño de arreglo a ordenar (número entero)
Salida:
	- Arreglo ordenado (arreglo de enteros)
*/
int* bubbleSort(int* arreglo, int cantElementos){
	int i,j,aux;
	i =0;
	while(i<cantElementos){
		j = i+1;
		while(j<cantElementos){
			if(arreglo[i]>arreglo[j]){
				aux = arreglo[i];
				arreglo[i] = arreglo[j];
				arreglo[j] = aux;
			}
			j++;
		}
		i++;
	}
	return arreglo;
}

/*
Función que ordena un arreglo de menor a mayor
Entrada:
	- Arreglo a ordenar (Arreglo de enteros)
	- Tamaño de arreglo a ordenar (número entero)
Salida:
	- Arreglo ordenado (arreglo de enteros)
*/
int* quickSort(int* arreglo, int cantElementos){
	/*printf("Entrando al QS con %d elementos: ",cantElementos);
	for (int i = 0; i < cantElementos; ++i){
		printf("%d - ", arreglo[i]);
	}
	printf("\n");
	*/
	if(cantElementos == 0 || cantElementos == 1){
		return arreglo;
	}
	else if(cantElementos == 2){
		if(arreglo[0]<arreglo[1]){
			return arreglo;
		}
		else{
			int aux = arreglo[0];
			arreglo[0] = arreglo[1];
			arreglo[1] = aux;
			return arreglo;// --> NO HABIA PUESTO ESTE RETURN!!!!
		}
	}else{
		//printf("Se tienen más de dos elementos dentro del arreglo, se pivotea.\n");
		int pivote = arreglo[0];
		int cantMenores = 0;
		int cantMayores = 0;
		int* menores = (int*)malloc(sizeof(int)*cantMenores);
		int* mayores = (int*)malloc(sizeof(int)*cantMayores);
		int i = 1;
		for (; i < cantElementos; ++i){
			if(arreglo[i]<pivote){
				menores = agregarElemento(menores,cantMenores,arreglo[i]);
				cantMenores++;
			}else{
				mayores = agregarElemento(mayores,cantMayores,arreglo[i]);
				cantMayores++;
			}
		}
		int * menoresOrdenados = quickSort(menores, cantMenores);
		int * mayoresOrdenados = quickSort(mayores, cantMayores);
		return concatenar(menoresOrdenados, cantMenores, pivote, mayoresOrdenados, cantMayores);
	}
}


int main(){
	srand(time(NULL));
	int cantDigitos = rand()%50 + 1;

	int* arreglo = (int*)malloc(sizeof(int)*cantDigitos);
	int i=0;
	for(;i<cantDigitos;i++){
		arreglo[i] = rand()%100;
	}

	int* arregloBubbleSort = copiarArreglo(arreglo,cantDigitos);
	int* arregloMergeSort = copiarArreglo(arreglo,cantDigitos);
	int* arregloQuickSort = copiarArreglo(arreglo,cantDigitos);

	arregloBubbleSort = bubbleSort(arregloBubbleSort,cantDigitos);
	arregloQuickSort = quickSort(arregloQuickSort,cantDigitos);


	printf("Cantidad de elementos: %d\n", cantDigitos);
	for (i = 0; i < cantDigitos; ++i){
		printf("arreglo[%d] = %d - arregloBubbleSort[%d] = %d - arregloQuickSort[%d] = %d\n",i,arreglo[i],i,arregloBubbleSort[i],i,arregloQuickSort[i]);
	}
	printf("Fin del programa");

	free(arreglo);
	free(arregloBubbleSort);
	free(arregloMergeSort);
	free(arregloQuickSort);
	return 0;
}
