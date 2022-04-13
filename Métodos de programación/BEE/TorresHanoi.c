/*****************************************************************************************************
Programa que resuelve el problema de las torres de Hanoi utilizando BEE
La idea es que cada torre es representada como un arreglo, de esta forma, si el problema fuera
mover 4 discos, las torres serían:
- Inicial: {{4,3,2,1},{0,0,0,0},{0,0,0,0}}
- Final: 	{{0,0,0,0},{4,3,2,1},{0,0,0,0}}
			{{0,0,0,0},{0,0,0,0},{4,3,2,1}}
Las reglas son:
	- Cada torre está ordenada de mayor a menor y 0's
Las transiciones son representadas por dos números enteros, que indican la torre de inicio y la
torre final, de esta forma el número 21 indica que se mueve el disco desde la torre 2 a la 1.
Se considera que siempre se mueve un solo dísco, a la posición más baja donde se encuentre un 0
en el disco de destino, siempre y cuando el estado anterior sea mayor qué el valor que se mueve.
Las transiciones que se tienen son:
	- Mover de la torre 1 a la 2: Transición 12.
		- Estado Inicial:
			- {{A1,B1,C1,D1},{A2,B2,C2,D2},{A3,B3,C3,D3}}
				Si D1 != 0; se mueve D1, entonces:
					Si A2 == 0, entonces:
						{{A1,B1,C1,0},{D1,0,0,0},{A3,B3,C3,D3}}
					Si B2 == 0, entonces:
						{{A1,B1,C1,0},{A2,D1,0,0},{A3,B3,C3,D3}}
					Si C2 == 0, entonces:
						{{A1,B1,C1,0},{A2,B2,D1,0},{A3,B3,C3,D3}}
					Si D2 == 0, entonces:
						{{A1,B1,C1,0},{A2,B2,C2,D1},{A3,B3,C3,D3}}
				Si C1 != 0; se mueve D1, entonces:
					Si A2 == 0, entonces:
						{{A1,B1,0,0},{C1,0,0,0},{A3,B3,C3,D3}}
					Si B2 == 0, entonces:
						{{A1,B1,0,0},{A2,C1,0,0},{A3,B3,C3,D3}}
					Si C2 == 0, entonces:
						{{A1,B1,0,0},{A2,B2,C1,0},{A3,B3,C3,D3}}
					Si D2 == 0, entonces:
						{{A1,B1,0,0},{A2,B2,C2,C1},{A3,B3,C3,D3}}
				Si B1 != 0; se mueve D1, entonces:
					Si A2 == 0, entonces:
						{{A1,0,0,0},{B1,0,0,0},{A3,B3,C3,D3}}
					Si B2 == 0, entonces:
						{{A1,0,0,0},{A2,B1,0,0},{A3,B3,C3,D3}}
					Si C2 == 0, entonces:
						{{A1,0,0,0},{A2,B2,B1,0},{A3,B3,C3,D3}}
					Si D2 == 0, entonces:
						{{A1,0,0,0},{A2,B2,C2,B1},{A3,B3,C3,D3}}
				Si A1 != 0; se mueve D1, entonces:
					Si A2 == 0, entonces:
						{{0,0,0,0},{A1,0,0,0},{A3,B3,C3,D3}}
					Si B2 == 0, entonces:
						{{0,0,0,0},{A2,A1,0,0},{A3,B3,C3,D3}}
					Si C2 == 0, entonces:
						{{0,0,0,0},{A2,B2,A1,0},{A3,B3,C3,D3}}
					Si D2 == 0, entonces:
						{{0,0,0,0},{A2,B2,C2,A1},{A3,B3,C3,D3}}
	- Mover de la torre 1 a la 3: Transición 13, Siguiendo lo mismo indicado anteriormente
	- Mover de la torre 2 a la 1: Transición 21, Siguiendo lo mismo indicado anteriormente
	- Mover de la torre 2 a la 3: Transición 23, Siguiendo lo mismo indicado anteriormente
	- Mover de la torre 3 a la 1: Transición 31, Siguiendo lo mismo indicado anteriormente
	- Mover de la torre 3 a la 2: Transición 32, Siguiendo lo mismo indicado anteriormente

Autor: Docencia Métodos de Programación 1-2020
Fecha: 1-2020
Versión: 1.0
Actualizado: 01/07/2020
************************************************************************************************/


#include <stdio.h>
#include <stdlib.h>

/*
Estructura de estado de las torres de Hanoi
El estado es la situación actual de cada una de las torres.
*/
struct Estado{
	int tamanioTorres;
	int * torre1;
	int * torre2;
	int * torre3;

	int id;
	int estadoAnterior;
	int accion;
};
typedef struct Estado Estado;


/******************************************************************************************
Otras funciones auxiliares
******************************************************************************************/
/*
Función que me indica si la estructura de la torre de hanoi ya se ha evaluado anteriormente
0: El estado buscado no está
1: El estado buscado si está
*/
int estaEstado(Estado estadoBuscado, Estado* conjunto,int tamanioConjunto){
	int contador;
	for (int i = 0; i < tamanioConjunto; ++i){
		contador =0;
		for (int j = 0; j < conjunto[i].tamanioTorres; ++j){
			if(conjunto[i].torre1[j] == estadoBuscado.torre1[j] &&
				conjunto[i].torre2[j] == estadoBuscado.torre2[j] &&
				conjunto[i].torre3[j] == estadoBuscado.torre3[j])
				contador++;
		}
		if(contador == conjunto[i].tamanioTorres)
			return 1;
	}
	return 0;
}



/***********************************************************************************
Funciones para imprimir los estados
************************************************************************************/
void imprimirNoSolucion(){
	printf("Lo siento, pero no hay solución para la estructura de las torres de hanoi dadas.\n");
}

void imprimirEstado(Estado estado){
	printf("\tImprimindo estado: %d - Estado Anterior: %d - Accion: %d - Tamanio Torre:%d\n", estado.id, estado.estadoAnterior, estado.accion, estado.tamanioTorres);
	printf("\t\t{{");
	for (int i = 0; i < estado.tamanioTorres; ++i){
		printf("%d,",estado.torre1[i]);
	}printf("},{");
	for (int i = 0; i < estado.tamanioTorres; ++i){
		printf("%d,",estado.torre2[i]);
	}printf("},{");
	for (int i = 0; i < estado.tamanioTorres; ++i){
		printf("%d,",estado.torre3[i]);
	}printf("}}");
	printf("\n");
}


int* agregarIdEstado(int* listado, int* tamanio, int transicion){
	int* nuevo=(int*)malloc(sizeof(int)*(*tamanio+1));
	for (int i = 0; i < *tamanio; ++i){
		nuevo[i] = listado[i];
	}
	nuevo[*tamanio]=transicion;
	*tamanio=*tamanio+1;
	free(listado);
	return nuevo;
}

void entregarSolucion(Estado estadoActual, Estado * cerrados, int tamanioCerrados){
	int idBuscado = estadoActual.estadoAnterior;
	int posEstadoAnterior = 0, cantidad = 1;
	int* estadosImprimir = (int*)malloc(sizeof(int)*1);
	estadosImprimir[0]=estadoActual.id;
	while(idBuscado != 0){
		posEstadoAnterior = -1;
		for (int i = 0; i < tamanioCerrados; ++i){
			if(idBuscado == cerrados[i].id){
				posEstadoAnterior = i;
			}
		}
		idBuscado = cerrados[posEstadoAnterior].estadoAnterior;
		estadosImprimir = agregarIdEstado(estadosImprimir, &cantidad, cerrados[posEstadoAnterior].id);
	}
	estadosImprimir = agregarIdEstado(estadosImprimir, &cantidad, 0);
	//Imprimo los estados
	for (int i = 0; i < cantidad; ++i){
		for (int j = 0; j < tamanioCerrados; ++j){
			if(estadosImprimir[cantidad-i-1] == cerrados[j].id){
				imprimirEstado(cerrados[j]);
			}
		}
	}
	printf("Fin\n");
}

/*
Función para agregar un estado a una lista de estados.
Consideraciones: Esta función actualiza el tamaño de la lista de estados, por lo cual se pasa por referencia. Esto se puede omitir, pero 
hay que tener cuidado al momento de hacer la invocación de la función.
Se debe considerar que las torres son arreglos dinámicos, por lo cual al momento de crear un nuevo estado, estos se deben inicializar y copiar
uno a uno sus valores.
*/
Estado * agregar(Estado* conjunto,int* tamanioConjunto,Estado estadoAgregar){
	//printf("Agregar: - Iniciando Funcion\n");
	Estado* nuevoConjunto = (Estado*)malloc(sizeof(Estado)*((*tamanioConjunto)+1));
	//printf("Agregar: - Creado nuevo conjunto.\n");
	for (int i = 0; i < *tamanioConjunto; ++i){
		//printf("Agregar: - Copiando el elemento %d del conjunto.\n", i);
		nuevoConjunto[i].tamanioTorres = conjunto[i].tamanioTorres;
		//Se copia la información de cada una de las torres en cada estado
		nuevoConjunto[i].torre1 = (int*)malloc(sizeof(int)*conjunto[i].tamanioTorres);
		nuevoConjunto[i].torre2 = (int*)malloc(sizeof(int)*conjunto[i].tamanioTorres);
		nuevoConjunto[i].torre3 = (int*)malloc(sizeof(int)*conjunto[i].tamanioTorres);
		
		for(int j = 0; j < nuevoConjunto[i].tamanioTorres; j++){
			nuevoConjunto[i].torre1[j] = conjunto[i].torre1[j];
			nuevoConjunto[i].torre2[j] = conjunto[i].torre2[j];
			nuevoConjunto[i].torre3[j] = conjunto[i].torre3[j];
		}
		//Libero memoria de los punteros del struct
		free(conjunto[i].torre1);
		free(conjunto[i].torre2);
		free(conjunto[i].torre3);

		nuevoConjunto[i].id = conjunto[i].id;
		nuevoConjunto[i].estadoAnterior = conjunto[i].estadoAnterior;
		nuevoConjunto[i].accion = conjunto[i].accion;
		//printf("Agregar: - Elemento copiado.\n", i);
	}
	//printf("Agregar: - Copiando el elemento nuevo.\n");
	nuevoConjunto[*tamanioConjunto].tamanioTorres = estadoAgregar.tamanioTorres;
	nuevoConjunto[*tamanioConjunto].torre1 = (int *)malloc(sizeof(int)*estadoAgregar.tamanioTorres);
	nuevoConjunto[*tamanioConjunto].torre2 = (int *)malloc(sizeof(int)*estadoAgregar.tamanioTorres);
	nuevoConjunto[*tamanioConjunto].torre3 = (int *)malloc(sizeof(int)*estadoAgregar.tamanioTorres);

	for (int i = 0; i < estadoAgregar.tamanioTorres; ++i){
		nuevoConjunto[*tamanioConjunto].torre1[i] = estadoAgregar.torre1[i];
		nuevoConjunto[*tamanioConjunto].torre2[i] = estadoAgregar.torre2[i];
		nuevoConjunto[*tamanioConjunto].torre3[i] = estadoAgregar.torre3[i];
	}

	nuevoConjunto[*tamanioConjunto].id = estadoAgregar.id;
	nuevoConjunto[*tamanioConjunto].estadoAnterior = estadoAgregar.estadoAnterior;
	nuevoConjunto[*tamanioConjunto].accion = estadoAgregar.accion;
	//printf("Agregar: - Elemento nuevo copiado.\n");
	free(conjunto);
	//printf("Agregar: - Espacio liberado.\n");
	*tamanioConjunto = *tamanioConjunto+1;
	//printf("Agregar: - Tamanio actualizado.\n");
	return nuevoConjunto;
}


/*
Función que retorna el primer valor de la lista.
La lista cambia su tamaño

OBS: Se realiza una copia del elemento siguiente en el anterior, el último elemento nunca se elemina, 
solo se cambia la cantidad de elementos de la lista
*/
Estado pop(Estado* conjunto,int * tamanioConjunto){
	//printf("POP: - Iniciando Funcion\n");
	//printf("POP: - Copiando el primer elemento.\n");
	Estado primero;
	primero.tamanioTorres = conjunto[0].tamanioTorres;
	primero.torre1 = (int*)malloc(sizeof(int)*conjunto[0].tamanioTorres);
	primero.torre2 = (int*)malloc(sizeof(int)*conjunto[0].tamanioTorres);
	primero.torre3 = (int*)malloc(sizeof(int)*conjunto[0].tamanioTorres);
	for (int i = 0; i < conjunto[0].tamanioTorres; ++i){
		primero.torre1[i]=conjunto[0].torre1[i];
		primero.torre2[i]=conjunto[0].torre2[i];
		primero.torre3[i]=conjunto[0].torre3[i];
	}
	
	primero.id = conjunto[0].id;
	primero.estadoAnterior = conjunto[0].estadoAnterior;
	primero.accion = conjunto[0].accion;
	
	//printf("POP: - Actualizando conjunto.\n");
	for (int i = 1; i < *tamanioConjunto; ++i){
		//printf("POP: - Copiando el elemento %d del conjunto.\n", i);
		//imprimirEstado(conjunto[i-1]);
		//printf("conjunto[%d].tamanioTorres = %d\n",(i-1), conjunto[i-1].tamanioTorres);
		for (int j = 0; j < conjunto[i-1].tamanioTorres; ++j){
			conjunto[i-1].torre1[j]=conjunto[i].torre1[j];
			conjunto[i-1].torre2[j]=conjunto[i].torre2[j];
			conjunto[i-1].torre3[j]=conjunto[i].torre3[j];
		}
		conjunto[i-1].id = conjunto[i].id;
		conjunto[i-1].estadoAnterior = conjunto[i].estadoAnterior;
		conjunto[i-1].accion = conjunto[i].accion;
		//printf("POP: - Elemento copiado.\n", i);
	}
	*tamanioConjunto = *tamanioConjunto-1;
	//printf("POP: - Tamanio actualizado.\n");
	return primero;
}


/*
Función que verifica que sea un estado final
Retorna 1 en caso de ser estado final
Retorna 0 en caso de no ser estado final
OBS: Se considera que se mueva de la torre 1 a la torre 2 o 3
*/
int verEstadoFinal(Estado estadoActual){
	int estTorre1 = 0, estTorre2 = 0, estTorre3 = 0;
	//Para la torre 1 debe ser todo en 0
	for(int i=0;i<estadoActual.tamanioTorres;i++){
		if(estadoActual.torre1[i] != 0)
			return 0;
	}
	//Para mover a la torre 2, esta debe estar ordenada y la torre 3 debe estar en 0
	//Se recorre la torre 2 y la torre 3 al mismo tiempo, si la torre 2 tiene los elementos ordenados de mayor a menor, 
	//se va contando posición a posición que cumpla la propiedad mencionada, se va contando cada vez que se cumpla.
	for (int i=0; i<estadoActual.tamanioTorres; ++i){
		if(estadoActual.torre2[i] == estadoActual.tamanioTorres-i && estadoActual.torre3[i] == 0)
			estTorre2++;
	}//Si se cumple la misma cantidad de elementos que posee la torre, se cumple.
	if(estTorre2 == estadoActual.tamanioTorres)
		return 1;
	//Para mover a la torre 3, esta debe estar ordenada y la torre 2 debe estar en 0
	//Se realiza lo mismo que antes, pero se intercambia la torre 3 por la 2 y viceversa.
	for (int i=0; i<estadoActual.tamanioTorres; ++i){
		if(estadoActual.torre3[i] == estadoActual.tamanioTorres-i && estadoActual.torre2[i] == 0)
			estTorre3++;
	}
	if(estTorre3 == estadoActual.tamanioTorres)
		return 1;
	return 0;
}

/********************************************************************************************
Funciones de transición
1 = Si se puede hacer
0 = No se puede hacer
********************************************************************************************/
//Funciones que verifican que se pueda mover, para eso el elemento de la posición inicial debe ser menor
//que el elemento que hay en la posición final
//Cómo los elementos estarán ordendados desde la posición 0 a la n (n tamaño de la torre), en el momento que
//haya un 0, significa que no hay más elementos.
int sePuedeMover12(Estado estadoActual){
	//Busco el elemento a mover y la posición que posee de la torre 1
	int elementoTorre1=-1, posTorre1=-1;
	int elementoTorre2=-1, posTorre2=-1;
	for (int i = estadoActual.tamanioTorres-1; i >= 0; i--){
		if(estadoActual.torre1[i] != 0 && elementoTorre1 == -1){
	 		elementoTorre1 = estadoActual.torre1[i];
	 		posTorre1 = i;
	 	}
	 	if(estadoActual.torre2[i] != 0 && elementoTorre2 == -1){
	 		elementoTorre2 = estadoActual.torre2[i];
	 		posTorre2 = i;
	 	}
	}
	if(posTorre1==-1)
		return 0;
	//Si el elemento en la torre 2 es mayor que el de la torre 1, se puede mover
	if(elementoTorre2 == -1 || elementoTorre1 < elementoTorre2)
		return 1;
	return 0;
}

int sePuedeMover13(Estado estadoActual){
	int elementoTorre1=-1, posTorre1=-1;
	int elementoTorre3=-1, posTorre3=-1;
	for (int i = estadoActual.tamanioTorres-1; i >= 0; i--){
		if(estadoActual.torre1[i] != 0 && elementoTorre1 == -1){
	 		elementoTorre1 = estadoActual.torre1[i];
	 		posTorre1 = i;
	 	}
	 	if(estadoActual.torre3[i] != 0 && elementoTorre3 == -1){
	 		elementoTorre3 = estadoActual.torre3[i];
	 		posTorre3 = i;
	 	}
	}
	if(posTorre1==-1)
		return 0;
	if(elementoTorre3 == -1 || elementoTorre1 < elementoTorre3)
		return 1;
	return 0;
}

int sePuedeMover21(Estado estadoActual){
	int elementoTorre2=-1, posTorre2=-1;
	int elementoTorre1=-1, posTorre1=-1;
	for (int i = estadoActual.tamanioTorres-1; i >= 0; i--){
		if(estadoActual.torre2[i] != 0 && elementoTorre2 == -1){
	 		elementoTorre2 = estadoActual.torre2[i];
	 		posTorre2 = i;
	 	}
	 	if(estadoActual.torre1[i] != 0 && elementoTorre1 == -1){
	 		elementoTorre1 = estadoActual.torre1[i];
	 		posTorre1 = i;
	 	}
	}
	if(posTorre2==-1)
		return 0;
	if(elementoTorre1 == -1 || elementoTorre2 < elementoTorre1)
		return 1;
	return 0;
}

int sePuedeMover23(Estado estadoActual){
	int elementoTorre2=-1, posTorre2=-1;
	int elementoTorre3=-1, posTorre3=-1;
	for (int i = estadoActual.tamanioTorres-1; i >= 0; i--){
		if(estadoActual.torre2[i] != 0 && elementoTorre2 == -1){
	 		elementoTorre2 = estadoActual.torre2[i];
	 		posTorre2 = i;
	 	}
	 	if(estadoActual.torre3[i] != 0 && elementoTorre3 == -1){
	 		elementoTorre3 = estadoActual.torre3[i];
	 		posTorre3 = i;
	 	}
	}
	if(posTorre2==-1)
		return 0;
	if(elementoTorre3 == -1 || elementoTorre2 < elementoTorre3)
		return 1;
	return 0;
}

int sePuedeMover31(Estado estadoActual){
	int elementoTorre3=-1, posTorre3=-1;
	int elementoTorre1=-1, posTorre1=-1;
	for (int i = estadoActual.tamanioTorres-1; i >= 0; i--){
		if(estadoActual.torre3[i] != 0 && elementoTorre3 == -1){
	 		elementoTorre3 = estadoActual.torre3[i];
	 		posTorre3 = i;
	 	}
	 	if(estadoActual.torre1[i] != 0 && elementoTorre1 == -1){
	 		elementoTorre1 = estadoActual.torre1[i];
	 		posTorre1 = i;
	 	}
	}
	if(posTorre3==-1)
		return 0;
	if(elementoTorre1 == -1 || elementoTorre3 < elementoTorre1)
		return 1;
	return 0;
}

int sePuedeMover32(Estado estadoActual){
	int elementoTorre3=-1, posTorre3=-1;
	int elementoTorre2=-1, posTorre2=-1;
	for (int i = estadoActual.tamanioTorres-1; i >= 0; i--){
		if(estadoActual.torre3[i] != 0 && elementoTorre3 == -1){
	 		elementoTorre3 = estadoActual.torre3[i];
	 		posTorre3 = i;
	 	}
	 	if(estadoActual.torre2[i] != 0 && elementoTorre2 == -1){
	 		elementoTorre2 = estadoActual.torre2[i];
	 		posTorre2 = i;
	 	}
	}
	if(posTorre3==-1)
		return 0;
	if(elementoTorre2 == -1 || elementoTorre3 < elementoTorre2)
		return 1;
	return 0;
}

//Funciones para mover
Estado mover12(Estado estadoActual, int idNuevoEstado){
	//Busco el elemento a mover y la posición que posee de la torre 1
	int elementoTorre1=estadoActual.tamanioTorres+1, posTorre1=-1;
	//printf("Moviendo de 1 a 2.\n");
	for (int i = 0; i < estadoActual.tamanioTorres; ++i) {
	 	if(estadoActual.torre1[i] < elementoTorre1 && estadoActual.torre1[i] != 0){
	 		elementoTorre1 = estadoActual.torre1[i];
	 		posTorre1 = i;
	 	}
	 }
	 //Busco la posición a donde se debe mover el elemento
	 int posTorre2=-1;
	 for (int i = estadoActual.tamanioTorres-1; i >=0 ; i--){
	 	if(estadoActual.torre2[i] == 0){
	 		posTorre2 = i;
	 	}
	 }
	 //Se crea el nuevo estado
	 Estado estadoFinal;
	 estadoFinal.tamanioTorres = estadoActual.tamanioTorres;
	 estadoFinal.torre1 = (int*)malloc(sizeof(int)*estadoFinal.tamanioTorres);
	 estadoFinal.torre2 = (int*)malloc(sizeof(int)*estadoFinal.tamanioTorres);
	 estadoFinal.torre3 = (int*)malloc(sizeof(int)*estadoFinal.tamanioTorres);
	 for (int i = 0; i < estadoFinal.tamanioTorres; ++i){
	 	estadoFinal.torre1[i] = estadoActual.torre1[i];
	 	estadoFinal.torre2[i] = estadoActual.torre2[i];
	 	estadoFinal.torre3[i] = estadoActual.torre3[i];
	 }
	 //Se intercambian los valores
	 estadoFinal.torre1[posTorre1] = 0;
	 estadoFinal.torre2[posTorre2] = elementoTorre1;

	 estadoFinal.id = idNuevoEstado;
	 estadoFinal.estadoAnterior = estadoActual.id;
	 estadoFinal.accion = 12;

	 //imprimirEstado(estadoFinal);
	 return estadoFinal;
}

Estado mover13(Estado estadoActual, int idNuevoEstado){
	//Busco el elemento a mover y la posición que posee de la torre 1
	int elementoTorre1=estadoActual.tamanioTorres+1, posTorre1=-1;
	//printf("\t\tMoviendo de 1 a 3.\n");
	for (int i = 0; i < estadoActual.tamanioTorres; ++i) {
	 	if(estadoActual.torre1[i] < elementoTorre1 && estadoActual.torre1[i] != 0){
	 		elementoTorre1 = estadoActual.torre1[i];
	 		posTorre1 = i;
	 	}
	 }
	 //Busco la posición a donde se debe mover el elemento
	 int posTorre3=-1;
	 for (int i = estadoActual.tamanioTorres-1; i >=0 ; i--){
	 	if(estadoActual.torre3[i] == 0){
	 		posTorre3 = i;
	 	}
	 }
	 //Se crea el nuevo estado
	 Estado estadoFinal;
	 estadoFinal.tamanioTorres = estadoActual.tamanioTorres;
	 estadoFinal.torre1 = (int*)malloc(sizeof(int)*estadoFinal.tamanioTorres);
	 estadoFinal.torre2 = (int*)malloc(sizeof(int)*estadoFinal.tamanioTorres);
	 estadoFinal.torre3 = (int*)malloc(sizeof(int)*estadoFinal.tamanioTorres);
	 for (int i = 0; i < estadoFinal.tamanioTorres; ++i){
	 	estadoFinal.torre1[i] = estadoActual.torre1[i];
	 	estadoFinal.torre2[i] = estadoActual.torre2[i];
	 	estadoFinal.torre3[i] = estadoActual.torre3[i];
	 }
	 //Se intercambian los valores
	 estadoFinal.torre1[posTorre1] = 0;
	 estadoFinal.torre3[posTorre3] = elementoTorre1;
	 
	 estadoFinal.id = idNuevoEstado;
	 estadoFinal.estadoAnterior = estadoActual.id;
	 estadoFinal.accion = 13;

	 //imprimirEstado(estadoFinal);
	 return estadoFinal;
}

Estado mover21(Estado estadoActual, int idNuevoEstado){
	//Busco el elemento a mover y la posición que posee de la torre 1
	int elementoTorre2=estadoActual.tamanioTorres+1, posTorre2=-1;
	//printf("\t\tMoviendo de 2 a 1.\n");
	for (int i = 0; i < estadoActual.tamanioTorres; ++i) {
	 	if(estadoActual.torre2[i] < elementoTorre2 && estadoActual.torre2[i] != 0){
	 		elementoTorre2 = estadoActual.torre2[i];
	 		posTorre2 = i;
	 	}
	 }
	 //Busco la posición a donde se debe mover el elemento
	 int posTorre1=-1;
	 for (int i = estadoActual.tamanioTorres-1; i >=0 ; i--){
	 	if(estadoActual.torre1[i] == 0){
	 		posTorre1 = i;
	 	}
	 }
	 //Se crea el nuevo estado
	 Estado estadoFinal;
	 estadoFinal.tamanioTorres = estadoActual.tamanioTorres;
	 estadoFinal.torre1 = (int*)malloc(sizeof(int)*estadoFinal.tamanioTorres);
	 estadoFinal.torre2 = (int*)malloc(sizeof(int)*estadoFinal.tamanioTorres);
	 estadoFinal.torre3 = (int*)malloc(sizeof(int)*estadoFinal.tamanioTorres);
	 for (int i = 0; i < estadoFinal.tamanioTorres; ++i){
	 	estadoFinal.torre1[i] = estadoActual.torre1[i];
	 	estadoFinal.torre2[i] = estadoActual.torre2[i];
	 	estadoFinal.torre3[i] = estadoActual.torre3[i];
	 }
	 //Se intercambian los valores
	 estadoFinal.torre2[posTorre2] = 0;
	 estadoFinal.torre1[posTorre1] = elementoTorre2;
	 
	 estadoFinal.id = idNuevoEstado;
	 estadoFinal.estadoAnterior = estadoActual.id;
	 estadoFinal.accion = 21;

	 //imprimirEstado(estadoFinal);
	 return estadoFinal;
}

Estado mover23(Estado estadoActual, int idNuevoEstado){
	//Busco el elemento a mover y la posición que posee de la torre 1
	int elementoTorre2=estadoActual.tamanioTorres+1, posTorre2=-1;
	//printf("\t\tMoviendo de 2 a 3.\n");
	for (int i = 0; i < estadoActual.tamanioTorres; ++i) {
	 	if(estadoActual.torre2[i] < elementoTorre2 && estadoActual.torre2[i] != 0){
	 		elementoTorre2 = estadoActual.torre2[i];
	 		posTorre2 = i;
	 	}
	 }
	 //Busco la posición a donde se debe mover el elemento
	 int posTorre3=-1;
	 for (int i = estadoActual.tamanioTorres-1; i >=0 ; i--){
	 	if(estadoActual.torre3[i] == 0){
	 		posTorre3 = i;
	 	}
	 }
	 //Se crea el nuevo estado
	 Estado estadoFinal;
	 estadoFinal.tamanioTorres = estadoActual.tamanioTorres;
	 estadoFinal.torre1 = (int*)malloc(sizeof(int)*estadoFinal.tamanioTorres);
	 estadoFinal.torre2 = (int*)malloc(sizeof(int)*estadoFinal.tamanioTorres);
	 estadoFinal.torre3 = (int*)malloc(sizeof(int)*estadoFinal.tamanioTorres);
	 for (int i = 0; i < estadoFinal.tamanioTorres; ++i){
	 	estadoFinal.torre1[i] = estadoActual.torre1[i];
	 	estadoFinal.torre2[i] = estadoActual.torre2[i];
	 	estadoFinal.torre3[i] = estadoActual.torre3[i];
	 }
	 //Se intercambian los valores
	 estadoFinal.torre2[posTorre2] = 0;
	 estadoFinal.torre3[posTorre3] = elementoTorre2;
	 
	 estadoFinal.id = idNuevoEstado;
	 estadoFinal.estadoAnterior = estadoActual.id;
	 estadoFinal.accion = 23;

	 //imprimirEstado(estadoFinal);
	 return estadoFinal;
}

Estado mover31(Estado estadoActual, int idNuevoEstado){
	//Busco el elemento a mover y la posición que posee de la torre 1
	int elementoTorre3=estadoActual.tamanioTorres+1, posTorre3=-1;
	//printf("\t\tMoviendo de 3 a 1.\n");
	for (int i = 0; i < estadoActual.tamanioTorres; ++i) {
	 	if(estadoActual.torre3[i] < elementoTorre3 && estadoActual.torre3[i] != 0){
	 		elementoTorre3 = estadoActual.torre3[i];
	 		posTorre3 = i;
	 	}
	 }
	 //Busco la posición a donde se debe mover el elemento
	 int posTorre1=-1;
	 for (int i = estadoActual.tamanioTorres-1; i >=0 ; i--){
	 	if(estadoActual.torre1[i] == 0){
	 		posTorre1 = i;
	 	}
	 }
	 //Se crea el nuevo estado
	 Estado estadoFinal;
	 estadoFinal.tamanioTorres = estadoActual.tamanioTorres;
	 estadoFinal.torre1 = (int*)malloc(sizeof(int)*estadoFinal.tamanioTorres);
	 estadoFinal.torre2 = (int*)malloc(sizeof(int)*estadoFinal.tamanioTorres);
	 estadoFinal.torre3 = (int*)malloc(sizeof(int)*estadoFinal.tamanioTorres);
	 for (int i = 0; i < estadoFinal.tamanioTorres; ++i){
	 	estadoFinal.torre1[i] = estadoActual.torre1[i];
	 	estadoFinal.torre2[i] = estadoActual.torre2[i];
	 	estadoFinal.torre3[i] = estadoActual.torre3[i];
	 }
	 //Se intercambian los valores
	 estadoFinal.torre3[posTorre3] = 0;
	 estadoFinal.torre1[posTorre1] = elementoTorre3;
	 
	 estadoFinal.id = idNuevoEstado;
	 estadoFinal.estadoAnterior = estadoActual.id;
	 estadoFinal.accion = 31;

	 //imprimirEstado(estadoFinal);
	 return estadoFinal;
}

Estado mover32(Estado estadoActual, int idNuevoEstado){
	//Busco el elemento a mover y la posición que posee de la torre 1
	int elementoTorre3=estadoActual.tamanioTorres+1, posTorre3=-1;
	//printf("\t\tMoviendo de 3 a 2.\n");
	for (int i = 0; i < estadoActual.tamanioTorres; ++i) {
	 	if(estadoActual.torre3[i] < elementoTorre3 && estadoActual.torre3[i] != 0){
	 		elementoTorre3 = estadoActual.torre3[i];
	 		posTorre3 = i;
	 	}
	 }
	 //Busco la posición a donde se debe mover el elemento
	 int posTorre2=-1;
	 for (int i = estadoActual.tamanioTorres-1; i >=0 ; i--){
	 	if(estadoActual.torre2[i] == 0){
	 		posTorre2 = i;
	 	}
	 }
	 //Se crea el nuevo estado
	 Estado estadoFinal;
	 estadoFinal.tamanioTorres = estadoActual.tamanioTorres;
	 estadoFinal.torre1 = (int*)malloc(sizeof(int)*estadoFinal.tamanioTorres);
	 estadoFinal.torre2 = (int*)malloc(sizeof(int)*estadoFinal.tamanioTorres);
	 estadoFinal.torre3 = (int*)malloc(sizeof(int)*estadoFinal.tamanioTorres);
	 for (int i = 0; i < estadoFinal.tamanioTorres; ++i){
	 	estadoFinal.torre1[i] = estadoActual.torre1[i];
	 	estadoFinal.torre2[i] = estadoActual.torre2[i];
	 	estadoFinal.torre3[i] = estadoActual.torre3[i];
	 }
	 //Se intercambian los valores
	 estadoFinal.torre3[posTorre3] = 0;
	 estadoFinal.torre2[posTorre2] = elementoTorre3;
	 
	 estadoFinal.id = idNuevoEstado;
	 estadoFinal.estadoAnterior = estadoActual.id;
	 estadoFinal.accion = 32;

	 //imprimirEstado(estadoFinal);
	 return estadoFinal;
}


/****************************************************************************************************
Función principal de Búsqueda en espacio de estados
****************************************************************************************************/

void BEE(Estado estadoInicial){
	//Creación de conjuntos abiertos y cerrados
	int tamanioAbiertos = 0, idNuevoEstado=1;
	Estado * abiertos = (Estado *)malloc(sizeof(Estado)*tamanioAbiertos);
	int tamanioCerrados = 0;
	Estado * cerrados = (Estado *)malloc(sizeof(Estado)*tamanioCerrados);
	//Se agrega a abiertos el estado inicial
	abiertos = agregar(abiertos, &tamanioAbiertos, estadoInicial);
	while (tamanioAbiertos > 0){
		/*
		printf("****************************************\n");
		printf("Imprimiendo el conjunto de abiertos: \n");
		for(int i=0; i<tamanioAbiertos; i++){
			imprimirEstado(abiertos[i]);
		}
		printf("****************************************\n");
		
		printf("-----------------------------------------\n");
		printf("Imprimiendo el conjunto de cerrados: \n");
		
		for (int i = 0; i < tamanioCerrados; ++i){
			imprimirEstado(cerrados[i]);
		}
		printf("-----------------------------------------\n");
		*/
		Estado estadoActual = pop(abiertos, &tamanioAbiertos);//Saca el elemento inicial del array de abiertos
		//printf("Verificando si es un estado final.\n");
		if(verEstadoFinal(estadoActual)==1){//Función que retorna un 1 si es el estado final. 
			//Para ver un estado final:
			//	1-. LABERINTO[estadoActual.posX][estadoActual.posY] == 2.
			cerrados = agregar(cerrados, &tamanioCerrados, estadoActual);
			entregarSolucion(estadoActual, cerrados, tamanioCerrados);
			return;
		}

		//printf("Agregando a cerrados.\n");
		cerrados = agregar(cerrados, &tamanioCerrados, estadoActual);
		//REALIZO LAS TRANSICIONES.
		//12
		idNuevoEstado = idNuevoEstado+1;
		//printf("Analizando si se puede mover de 1 a 2.\n");
		if(sePuedeMover12(estadoActual) == 1){
			//printf("\tSi se puede mover de 1 a 2.\n");
			Estado nuevoEstado = mover12(estadoActual,idNuevoEstado);
			idNuevoEstado = idNuevoEstado + 1;
			//Buscamos el nuevo estado en abiertos, si está devuelve un 1, en caso contrario un 0
			if(estaEstado(nuevoEstado, abiertos, tamanioAbiertos) == 0 && estaEstado(nuevoEstado, cerrados, tamanioCerrados) == 0){
				//printf("+++++Se realiza la accion mover Izquierda.\n");
				abiertos = agregar(abiertos, &tamanioAbiertos, nuevoEstado);
			}
		}
		//printf("Analizando si se puede mover de 1 a 3.\n");
		//13
		if(sePuedeMover13(estadoActual) == 1){
			//printf("\tSi se puede mover de 1 a 3.\n");
			Estado nuevoEstado = mover13(estadoActual,idNuevoEstado);
			idNuevoEstado = idNuevoEstado + 1;
			//Buscamos el nuevo estado en abiertos, si está devuelve un 1, en caso contrario un 0
			if(estaEstado(nuevoEstado, abiertos, tamanioAbiertos) == 0 && estaEstado(nuevoEstado, cerrados, tamanioCerrados) == 0){
				//printf("+++++Se realiza la accion mover Izquierda.\n");
				abiertos = agregar(abiertos, &tamanioAbiertos, nuevoEstado);
			}
		}
		//printf("Analizando si se puede mover de 2 a 1.\n");
		//21
		if(sePuedeMover21(estadoActual) == 1){
			//printf("\tSi se puede mover de 2 a 1.\n");
			Estado nuevoEstado = mover21(estadoActual,idNuevoEstado);
			idNuevoEstado = idNuevoEstado + 1;
			//Buscamos el nuevo estado en abiertos, si está devuelve un 1, en caso contrario un 0
			if(estaEstado(nuevoEstado, abiertos, tamanioAbiertos) == 0 && estaEstado(nuevoEstado, cerrados, tamanioCerrados) == 0){
				//printf("+++++Se realiza la accion mover Izquierda.\n");
				abiertos = agregar(abiertos, &tamanioAbiertos, nuevoEstado);
			}
		}
		//printf("Analizando si se puede mover de 2 a 3.\n");
		//23
		if(sePuedeMover23(estadoActual) == 1){
			//printf("\tSi se puede mover de 2 a 3.\n");
			Estado nuevoEstado = mover23(estadoActual,idNuevoEstado);
			idNuevoEstado = idNuevoEstado + 1;
			//Buscamos el nuevo estado en abiertos, si está devuelve un 1, en caso contrario un 0
			if(estaEstado(nuevoEstado, abiertos, tamanioAbiertos) == 0 && estaEstado(nuevoEstado, cerrados, tamanioCerrados) == 0){
				//printf("+++++Se realiza la accion mover Izquierda.\n");
				abiertos = agregar(abiertos, &tamanioAbiertos, nuevoEstado);
			}
		}
		//printf("Analizando si se puede mover de 3 a 1.\n");
		//31
		if(sePuedeMover31(estadoActual) == 1){
			//printf("\tSi se puede mover de 3 a 1.\n");
			Estado nuevoEstado = mover31(estadoActual,idNuevoEstado);
			idNuevoEstado = idNuevoEstado + 1;
			//Buscamos el nuevo estado en abiertos, si está devuelve un 1, en caso contrario un 0
			if(estaEstado(nuevoEstado, abiertos, tamanioAbiertos) == 0 && estaEstado(nuevoEstado, cerrados, tamanioCerrados) == 0){
				//printf("+++++Se realiza la accion mover Izquierda.\n");
				abiertos = agregar(abiertos, &tamanioAbiertos, nuevoEstado);
			}
		}
		//printf("Analizando si se puede mover de 3 a 2.\n");
		//32
		if(sePuedeMover32(estadoActual) == 1){
			//printf("\tSi se puede mover de 3 a 2.\n");
			Estado nuevoEstado = mover32(estadoActual,idNuevoEstado);
			idNuevoEstado = idNuevoEstado + 1;
			//Buscamos el nuevo estado en abiertos, si está devuelve un 1, en caso contrario un 0
			if(estaEstado(nuevoEstado, abiertos, tamanioAbiertos) == 0 && estaEstado(nuevoEstado, cerrados, tamanioCerrados) == 0){
				//printf("+++++Se realiza la accion mover Izquierda.\n");
				abiertos = agregar(abiertos, &tamanioAbiertos, nuevoEstado);
			}
		}
	}
	imprimirNoSolucion();
	return;
}

int main(){
	Estado estadoInicial;
	int cantidadTorres;
	printf("Ingrese la cantidad de elementos que desea en la torre de Hanoi\n");
	scanf("%d",&cantidadTorres);

	estadoInicial.id = 0;
	estadoInicial.estadoAnterior = 0;
	estadoInicial.accion = 0;

	estadoInicial.tamanioTorres = cantidadTorres;
	estadoInicial.torre1 = (int*)malloc(sizeof(int)*cantidadTorres);
	estadoInicial.torre2 = (int*)malloc(sizeof(int)*cantidadTorres);
	estadoInicial.torre3 = (int*)malloc(sizeof(int)*cantidadTorres);

	for (int i = 0; i < cantidadTorres; ++i){
		estadoInicial.torre1[i] = cantidadTorres-i;
		estadoInicial.torre2[i] = 0;
		estadoInicial.torre3[i] = 0;
	}
	
	BEE(estadoInicial);

	return 0;
}