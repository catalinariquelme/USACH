#include <stdio.h>
#include <stdlib.h>
#include <time.h>



//Objetivo: Comparar 2 arreglos compuestos por int's y crear una nueva con los elementos de las dos anteriores ordenados de menor a mayor.
//Entrada: Un int * (Primer arreglo compuesto por ints a comparar), int (Tamaño del primer arreglo), int * (Segundo arreglo compuesto por ints a comparar), int (Tamaño del segundo arreglo).
//Salida: Un int * (Arreglo ordenado de menor a mayor compuesto por los dos ingresados).
int * mezclar(int * izquierda,int lIzquierda,int * derecha,int lDerecha){

	int * ordenado = (int *)malloc(sizeof(int)*(lIzquierda+lDerecha));
	int i, posicionIz = 0;
	int posicionDe = 0;
	for (i=0;i < lIzquierda+lDerecha;++i){
		if (posicionIz == lIzquierda){
			ordenado[i] = derecha[posicionDe];
			posicionDe++;
		}else if(posicionDe == lDerecha){
			ordenado[i] = izquierda[posicionIz];
			posicionIz++;
		}else if (izquierda[posicionIz] < derecha[posicionDe]){
			ordenado[i] = izquierda[posicionIz];
			posicionIz++;
		}else{
			ordenado[i] = derecha[posicionDe];
			posicionDe++;
		}
	}
	free(izquierda);
	free(derecha);
	return ordenado;
}

//Objetivo: Ordenar de menor a mayor un arreglo compuesto por numeros int.
//Entrada: Un int * (Siendo este el arreglo que se ordenara) y un int (Largo del arreglo anterior).
//Salida: Un int * (Un arrelgo compuesto por numeros enteros ordenados de menor a mayor).
int * mergesort(int * arreglo, int largo){
	if (largo <=1){
		return arreglo;
	}else{
		int largoIzquierda = largo/2;
		int largoDerecha = largo - largoIzquierda;
		int * arrayIzquierda = (int *)malloc(sizeof(int)*(largoIzquierda));
		int i;
		for (i = 0; i < largoIzquierda;i++){
			arrayIzquierda[i] = arreglo[i];
		}
		int * arrayDerecha = (int *)malloc(sizeof(int)*(largoDerecha));
		for (i = 0;i < largoDerecha;i++){
			arrayDerecha[i] = arreglo[i+largoIzquierda];
		}

		free(arreglo);
		int * arregloOrdenado = (int *)malloc(sizeof(int)*(largo));
		arregloOrdenado = mezclar(mergesort(arrayIzquierda,largoIzquierda),largoIzquierda,mergesort(arrayDerecha,largoDerecha),largoDerecha);
		return arregloOrdenado;

	}

}

//Objetivo: Determinar si se encuentra un numero dentro de un array.
//Entrada: int * (El arreglo en donde se buscara un numero), int (Inicio del arreglo), int (Donde finaliza el arreglo), int (Numero a buscar).
//Salida: Un int (-1 de estar el numero dentro de la lista, el numero a buscar si es que no esta).
int buscadorNumero (int * arreglo,int inicio ,int final, int buscar){
	int mitad = (final-inicio) / 2; // calculamos la mitad del arreglo

	if (inicio == final){
		if (arreglo[inicio] == buscar){//de encontrarse el numero
			return -1;
		}
		return buscar;//de no encontrarse
	}else if (arreglo[inicio + mitad] == buscar){//Si la "mitad" es el numero que queremos encontrar, se retorna -1
		return -1;
	}else{
		if (arreglo[inicio+mitad] > buscar){//Proceso de busqueda en donde el numero a la "mitad" es mayor que el numero que estamos buscando
			return buscadorNumero(arreglo, inicio, final/2 ,buscar);
		}else{//Cuando el numero que buscamos es mayor al que tenemos en la "mitad" del arreglo
			return buscadorNumero(arreglo,final/2 + 1,final,buscar);
		}
	}
}

//Objetivo: Determinar el entero positivo más pequeño que falte dentro de un array compuesto por numeros enteros positivos.
//Entrada: Un int * (El arreglo en el cual se buscará el entero positivo más pequeño), int (Donde inicia el arreglo), int (Donde finaliza el arreglo), int (Numero entero positivo a buscar).
//Salida: Un int (El numero entero positivo más pequeño que falte dentro del arreglo).
int busquedaNumeroFaltante(int * arreglo,int inicio,int final, int buscar){
	int numeroEncontrar;

	numeroEncontrar = buscadorNumero(arreglo,inicio,final,buscar);
	if (numeroEncontrar == buscar){//de NO encontrarse el numero buscado se retorna el numero no encontrado
		return numeroEncontrar;
	}else{//de encontrarse en el arreglo se aumenta en 1 el numero a buscar y se realiza una busqueda binaria.
		return busquedaNumeroFaltante(arreglo,inicio,final,buscar + 1);
	}
}

int MAX = 20; // cambiar este número para variar el largo máximo del arreglo


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

	int * arregloOrdenado = mergesort(arreglo,largo); // se ordena la lista y se agrega el resultado del arreglo ordenado en un array 
	printf("\n");
	printf("\n");
	printf("El array ordenado es:");
	for (i = 0;i < largo; i++)//se imprime el arreglo ordenado separado cada elemento con 2 espacios
		printf("%d  ", arregloOrdenado[i]);
	int numeroFaltante;
	printf("\n");
	printf("\n");
	free(arreglo);

	numeroFaltante = busquedaNumeroFaltante(arregloOrdenado,0,largo-1,1);//Se busca el numero entero positivo 

	printf("\nEl numero entero positivo más pequenio es: %d",numeroFaltante);

	free(arregloOrdenado);
	
	return 0;
}



