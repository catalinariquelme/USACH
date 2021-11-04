#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*
Función que crea un tablero dadas ciertas posiciones
Entrada: Conjunto de posiciones (4 específicamente, cada una posee dos elementos)
Salida: Una matriz de enteros con 0's y 1's. Los 1's van en las posiciones dadas
*/
int ** crearTablero(int ** posiciones){
	int ** t = (int **)malloc(sizeof(int*)*4);//Se reserva memoria para un tablero de 4 filas
	//Se reserva memoria para todo, con un inicio en 0 para ellas.
	for (int i = 0; i < 4; ++i){
		t[i] = (int *)malloc(sizeof(int)*4);//Se reserva memoria para que cada fila posea 4 elementos
		for(int j=0; j<4; j++){
			t[i][j] = 0;
		}
	}
	//Se colocan los 1's correspondientes en cada posición
	for (int i = 0; i < 4; ++i){
		//Se recorren las 4 posiciones, donde la fila corresponde a la posición en 0
		//y la columna a la posición en 1.
		t[posiciones[i][0]][posiciones[i][1]] = 1;
	}
	return t;
}

/*
Función que agrega un elmento a una lista de elementos
Entrada: El conjunto de elementos a donde debo agregar el nuevo elemento
				(Cada elemento es una matriz de enteros, por lo que debe ser una lista de matrices)
			La cantidad de elementos que posee este conjunto (Se pasa por referencia)
			El nuevo elemento a agregar (Una matriz de enteros)
Salida: Un nuevo conjunto de elementos
*/
int *** agregarSolucion(int *** conjunto, int * cantElementos, int ** solucion){
	//Se crea el nuevo conjunto de soluciones
	int*** conjuntoNuevo = (int ***)malloc(sizeof(int**)*(*cantElementos+1));
	for (int i = 0; i < *cantElementos+1; ++i){
		conjuntoNuevo[i] = (int **)malloc(sizeof(int *)*4);
		for (int j = 0; j < 4; ++j){
			conjuntoNuevo[i][j] = (int *)malloc(sizeof(int)*4);
		}
	}
	//Se copian las soluciones existentes
	for (int numSolucion = 0; numSolucion < *cantElementos; ++numSolucion){
		for(int ejeX = 0; ejeX < 4; ejeX ++){
			for (int ejeY = 0; ejeY < 4; ++ejeY){
				conjuntoNuevo[numSolucion][ejeX][ejeY] = conjunto[numSolucion][ejeX][ejeY];
			}
		}
	}
	//Se agrega la nueva solución
	for (int ejeXSol = 0; ejeXSol < 4; ++ejeXSol){
		for (int ejeYSol = 0; ejeYSol < 4; ++ejeYSol){
			conjuntoNuevo[*cantElementos][ejeXSol][ejeYSol] = solucion[ejeXSol][ejeYSol];
		}
	}
	*cantElementos = *cantElementos+1;//Se actualiza la cantidad de elementos
	free(conjunto);//Se libera memoria del conjunto de soluciones que ya no se utilizará
	return conjuntoNuevo;
}

/*
Función que elimina un elmento a una lista de elementos
Entrada: El conjunto de elementos a donde debo agregar el nuevo elemento
				(Cada elemento es una matriz de enteros, por lo que debe ser una lista de matrices)
			La cantidad de elementos que posee este conjunto (Se pasa por referencia)
			La posición del elemento a eliminar
Salida: Un nuevo conjunto de elementos
*/
int *** eliminarSolucion(int *** conjunto, int * cantElementos, int posSolEliminar){
	//Se crea el nuevo conjunto de soluciones
	int*** conjuntoNuevo = (int ***)malloc(sizeof(int**)*(*cantElementos-1));
	for (int i = 0; i < *cantElementos-1; ++i){
		conjuntoNuevo[i] = (int **)malloc(sizeof(int *)*4);
		for (int j = 0; j < 4; ++j){
			conjuntoNuevo[i][j] = (int *)malloc(sizeof(int)*4);
		}
	}
	//Se copian las soluciones existentes, excepto aquel que hay que eliminar
	int contNuevaLista = 0;//Este contador corresponde a la lista nueva
	int contAntiguaLista = 0;
	while(contAntiguaLista < *cantElementos){
		//printf("\tComparando: %d con %d\n", contAntiguaLista, posSolEliminar);
		//Acá se verifica que no sea la solución a eliminar
		if(posSolEliminar != contAntiguaLista){
			//printf("\t\tDistintos, se mantiene\n");
			for(int ejeX = 0; ejeX < 4; ejeX ++){
				for (int ejeY = 0; ejeY < 4; ++ejeY){
					conjuntoNuevo[contNuevaLista][ejeX][ejeY] = conjunto[contAntiguaLista][ejeX][ejeY];
				}
			}//Si se agrega, se aumenta el contador de la nueva lista
			contNuevaLista++;
		}
		else{
			//printf("\t\tcontAntiguaLista eliminado\n");
		}//Siempre se debe avanzar el contador de la lista antigua
		contAntiguaLista++;
	}
	*cantElementos = *cantElementos-1;//Se actualiza la cantidad de elementos
	free(conjunto);//Se libera memoria del conjunto de soluciones que ya no se utilizará
	return conjuntoNuevo;
}


/*
Función que imprime por pantalla un tablero en específico.
Entrada: Matriz de números enteros
*/
void imprimir(int ** t){
	for (int i = 0; i < 4; ++i){
		for (int j = 0; j < 4; ++j){
			printf("%d ", t[i][j]);
		}
		printf("\n");
	}
	return;
}

/*
Función que imprime una lista de tableros
Entrada: Lista de matrices de enteros
*/
void imprimirSoluciones(int *** soluciones, int cantidadSoluciones){
	for(int nSol = 0; nSol < cantidadSoluciones; nSol ++){
		printf("Solucion N=%d\n", nSol);
		for (int i = 0; i < 4; ++i){
			for (int j = 0; j < 4; ++j){
				printf("%d ", soluciones[nSol][i][j]);
			}
			printf("\n");
		}
	}
	return;	
}

/*
Función que verifica que no existan dos 1's en la misma fila
Entrada: Matriz de enteros
Salida: Un número entero, 0 en caso que haya más de un 1; 1 en caso contrario
*/
int verificarHorizontal(int ** tablero){
	int aux;
	for (int i = 0; i < 4; ++i){
		aux = 0;
		for (int j = 0; j < 4; ++j){
			if(tablero[i][j] == 1)
				aux++;
			if(aux>1)
				return 0;
		}
	}
	return 1;
}

/*
Función que verifica que no existan dos 1's en la misma columna
Entrada: Matriz de enteros
Salida: Un número entero, 0 en caso que haya más de un 1; 1 en caso contrario
*/
int verificarVertical(int ** tablero){
	int aux;
	for (int i = 0; i < 4; ++i){
		aux = 0;
		for (int j = 0; j < 4; ++j){
			if(tablero[j][i] == 1)
				aux++;
			if(aux>1)
				return 0;
		}
	}
	return 1;
}

/*
Función que verifica que no existan dos 1's en la misma diagonal
Entrada: Matriz de enteros
Salida: Un número entero, 0 en caso que haya más de un 1; 1 en caso contrario
*/
int verificarDiagonal(int ** tablero){
	int r1, r2, r3;
	for (int i = 0; i < 4; ++i){
		r1 = 0;
		r2 = 0;
		r3 = 0;
		for (int j = 0; j < 4; ++j){
			if(tablero[i][j] == 1){
				//Búsqueda en la diagonal hacia la derecha
				if((i+1 < 4) && ((j+1) < 4)){
					if(tablero[i+1][j+1] == 1){
						r1 = 1;
					}
				}
				if((i+2 < 4) && (j+2) < 4){
					if(tablero[i+2][j+2] == 1){
						r2 = 1;
					}
				}
				if((i+3 < 4) && (j+3) < 4){
					if(tablero[i+3][j+3] == 1){
						r3 = 1;
					}
				}
				if((r1+r2+r3) > 0){
					return 0;
				}
				//Búsqueda en la diagonal hacia la izquieda
				if((i+1 < 4) && ((j-1) >= 0)){
					if(tablero[i+1][j-1] == 1){
						r1 = 1;
					}
				}
				if((i+2 < 4) && ((j-2) >= 0)){
					if(tablero[i+2][j-2] == 1){
						r2 = 1;
					}
				}
				if((i+3 < 4) && ((j-3) >= 0)){
					if(tablero[i+3][j-3] == 1){
						r3 = 1;
					}
				}
				if((r1+r2+r3) > 0){
					return 0;
				}
			}
		}
	}
	return 1;
}


int main(){
	/*Primero se procesede a crear una lista de tableros, los cuales nos ayudarán a crear todas las soluciones posibles de las reinas*/
	int cantidadSoluciones = 0;
	int *** conjuntoSoluciones = (int ***)malloc(sizeof(int**)*cantidadSoluciones);
	//Se definen variables para almacenar las posiciones que tendrán las reinas
	int posX1reina,posY1reina,posX2reina,posY2reina,posX3reina,posY3reina, posX4reina, posY4reina;
	//Se define una variable que servirá para almacenar las posiciones de las reinas
	int ** pos = (int **)malloc(sizeof(int*)*4);
	for (int i = 0; i < 4; ++i){
		pos[i] = (int *)malloc(sizeof(int)*2);
	}
	// Se generan todas las combinaciones posibles en donde pueden estar las reinas, independiente si cumplen o no con las reglas.
	// Se setean las posiciones de la primera reina
	posX1reina = 0;
	posY1reina = 0;
	while((posX1reina < 4) && (posY1reina < 4)){
		// Se setean las posiciones de la segunda reina
		if(posY1reina == 3){
			posY2reina = 0;
			posX2reina = posX1reina + 1;
		}
		else{
			posY2reina = posY1reina + 1;
			posX2reina = posX1reina;
		}
		while((posX2reina < 4) && (posY2reina < 4)){
			// Se setean las posiciones de la tercera reina
			if(posY2reina == 3){
				posY3reina = 0;
				posX3reina = posX2reina + 1;
			}
			else{
				posY3reina = posY2reina + 1;
				posX3reina = posX2reina;
			}
			while((posX3reina < 4) && (posY3reina < 4)){
				// Se setean las posiciones de la cuarta reina
				if(posY3reina == 3){
					posY4reina = 0;
					posX4reina = posX3reina + 1;
				}
				else{
					posY4reina = posY3reina + 1;
					posX4reina = posX3reina;
				}
				while((posX4reina < 4) && (posY4reina < 4)){
					pos[0][0] = posX1reina;
					pos[0][1] = posY1reina;
					pos[1][0] = posX2reina;
					pos[1][1] = posY2reina;
					pos[2][0] = posX3reina;
					pos[2][1] = posY3reina;
					pos[3][0] = posX4reina;
					pos[3][1] = posY4reina;
					posY4reina ++;
					if(posY4reina >= 4){
						posY4reina = 0;
						posX4reina ++;
					}
					//Se crea un tablero con esta variables
					int ** t = crearTablero(pos);
					//Se agrega el tablero a la lista
					conjuntoSoluciones = agregarSolucion(conjuntoSoluciones, &cantidadSoluciones, t);
					//imprimir(t);
					//printf("\n");
				}
				posY3reina ++;
				if(posY3reina >= 4){
					posY3reina = 0;
					posX3reina ++;
				}
			}
			posY2reina ++;
			if(posY2reina >= 4){
				posY2reina = 0;
				posX2reina ++;
			}
		}
		posY1reina ++;
		if(posY1reina >= 4){
			posY1reina = 0;
			posX1reina ++;
		}
	}
	/*
	imprimirSoluciones(conjuntoSoluciones, cantidadSoluciones);
	int c;
	printf("Ingrese numero para continuar.\n");
	scanf("%d",&c);
	*/
	
	//Se prueba dejan aquellos que cumplen horizontal
	int cumple;
	for (int i = 0; i < cantidadSoluciones; ++i){
		cumple = verificarHorizontal(conjuntoSoluciones[i]);
		if(cumple == 0){
			conjuntoSoluciones = eliminarSolucion(conjuntoSoluciones, &cantidadSoluciones, i);
			i --;
		}/*
		imprimirSoluciones(conjuntoSoluciones, cantidadSoluciones);
		printf("Ingrese numero para continuar.\n");
		scanf("%d",&c);*/
	}
	//imprimirSoluciones(conjuntoSoluciones, cantidadSoluciones);
	for (int i = 0; i < cantidadSoluciones; ++i){
		cumple = verificarVertical(conjuntoSoluciones[i]);
		if(cumple == 0){
			conjuntoSoluciones = eliminarSolucion(conjuntoSoluciones, &cantidadSoluciones, i);
			i --;
		}/*
		imprimirSoluciones(conjuntoSoluciones, cantidadSoluciones);
		printf("Ingrese numero para continuar.\n");
		scanf("%d",&c);*/
	}
	//imprimirSoluciones(conjuntoSoluciones, cantidadSoluciones);
	for (int i = 0; i < cantidadSoluciones; ++i){
		cumple = verificarDiagonal(conjuntoSoluciones[i]);
		if(cumple == 0){
			conjuntoSoluciones = eliminarSolucion(conjuntoSoluciones, &cantidadSoluciones, i);
			i --;
		}/*
		imprimirSoluciones(conjuntoSoluciones, cantidadSoluciones);
		printf("Ingrese numero para continuar.\n");
		scanf("%d",&c);*/
	}
	imprimirSoluciones(conjuntoSoluciones, cantidadSoluciones);

	return 0;
}