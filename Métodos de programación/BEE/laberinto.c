#include <stdio.h>
#include <stdlib.h>

typedef struct posicion posicion;

struct posicion{
	int row;
	int col;
	int idEstado;
	int estadoAnterior;
	char * transicion;
};

int correlativo;
/*Funciones necesarias*/
posicion crearEstado(int row, int col, int anterior, char * t);
posicion * agregarEstado(posicion * lista, int * elementos, posicion estado);
posicion * sacarElemento(posicion * lista, int * elementos);
int esFinal(posicion p, int** matriz);
void imprimirEstado(posicion p);
int estaEstado(posicion * lista, int elementos, posicion p);
void mostrarSolucion(posicion * lista, int ultimo);

/*Funciones para verificar los estados*/
int verificarArriba(posicion estado,int** matriz,int dim);
int verificarAbajo(posicion estado,int** matriz,int dim);
int verificarDerecha(posicion estado,int** matriz,int dim);
int verificarIzquierda(posicion estado,int** matriz,int dim);

/*Funciones para realizar las transiciones*/
posicion arriba(posicion estado);
posicion abajo(posicion estado);
posicion derecha(posicion estado);
posicion izquierda(posicion estado);

posicion crearEstado(int row, int col, int anterior, char * t){
	posicion nuevoEstado;
	nuevoEstado.row = row;
	nuevoEstado.col = col;
	nuevoEstado.idEstado = correlativo;
	nuevoEstado.estadoAnterior = anterior;
	nuevoEstado.transicion = t;
	correlativo = correlativo + 1;
	return nuevoEstado;
}
posicion * agregarEstado(posicion * lista, int * elementos, posicion estado){
	posicion * nuevaLista = (posicion *)malloc(sizeof(posicion)*(*elementos+1));
	for (int i = 0; i < *elementos; ++i){
		nuevaLista[i] = lista[i];
	}
	nuevaLista[*elementos] = estado;
	*elementos = *elementos+1;
	free(lista);
	return nuevaLista;
}
posicion * sacarElemento(posicion * lista, int * elementos){
	posicion * nuevaLista = (posicion *)malloc(sizeof(posicion)*(*elementos-1));
	for (int i = 1; i < *elementos; ++i){
		nuevaLista[i-1]=lista[i];
	}
	*elementos = *elementos-1;
	free(lista);
	return nuevaLista;
}
int esFinal(posicion p, int** matriz){
	if(matriz[p.row][p.col] == 2)
		return 1;
	return 0;
}
void imprimirEstado(posicion p){
	printf("Id:%d; row:%d, col:%d; T:%s, IdAnt:%d\n", p.idEstado, p.row, p.col, p.transicion, p.estadoAnterior);
}
int estaEstado(posicion * lista, int elementos, posicion b){
	for (int i = 0; i < elementos; ++i){
		if((lista[i].row == b.row) && (lista[i].col == b.col))
			return 1;
	}return 0;
}
void mostrarSolucion(posicion * lista, int ultimo){
	printf("Los pasos son, del ultimo al primero: \n");
	while(lista[ultimo].idEstado != 0){
		printf("%s\n", lista[ultimo].transicion);
		ultimo = lista[ultimo].estadoAnterior;
	}
}


int verificarArriba(posicion estado,int** matriz,int dim){
    if(estado.row >0){
        if(matriz[estado.row-1][estado.col] == 0 || matriz[estado.row-1][estado.col] == 2){
            return 1;
        }
    }
    return 0;
}
int verificarAbajo(posicion estado,int** matriz,int dim){
    if(estado.row < dim-1){
        if(matriz[estado.row+1][estado.col] == 0 || matriz[estado.row+1][estado.col] == 2){
            return 1;
        }
    }
    return 0;
}
int verificarDerecha(posicion estado,int** matriz,int dim){
    if(estado.col < dim -1){
        if(matriz[estado.row][estado.col+1] == 0 || matriz[estado.row][estado.col+1] == 2){
            return 1;
        }
    }
    return 0;
}
int verificarIzquierda(posicion estado,int** matriz,int dim){
    if(estado.col > 0){
        if(matriz[estado.row][estado.col-1] == 0 || matriz[estado.row][estado.col-1] == 2){
            return 1;
        }
    }
    return 0;
}

posicion arriba(posicion estado){
    return crearEstado(estado.row-1, estado.col, estado.idEstado, "ARRIBA");
}
posicion abajo(posicion estado){
    return crearEstado(estado.row+1, estado.col, estado.idEstado, "ABAJO");
}
posicion derecha(posicion estado){
    return crearEstado(estado.row, estado.col+1, estado.idEstado, "DERECHA");
}
posicion izquierda(posicion estado){
    return crearEstado(estado.row, estado.col-1, estado.idEstado, "IZQUIERDA");
}



int getDimMatriz(FILE* file){
    int dim;
    fscanf(file,"%d",&dim);
    return dim;
}

int** createMatriz(int dim, FILE* file){
    int** matriz = (int**) malloc(sizeof(int*)*dim);
    for(int i=0; i< dim; i++){
        matriz[i] = (int*) malloc(sizeof(int)* dim);
    }
    int buffer;
    for(int i=0; i< dim ; i++){
        for(int j=0;j<dim;j++){
            fscanf(file,"%d", &buffer);
            matriz[i][j]= buffer;
        }
    }
    return matriz;
}



int main(){
    FILE* file = fopen("entrada.in", "r");
    int dim = getDimMatriz(file);
    int** matriz = createMatriz(dim,file);
    //Para imprimir la matriz
    /*for(int i=0; i< dim; i++){
        for(int j=0;j<dim;j++){
            printf("%d", matriz[i][j]);
        }
        printf("\n");
    }*/


    correlativo = 0;
	int canAbiertos = 0;
	int canCerrados = 0;
	posicion bActual, bSiguiente;
	posicion * abiertos = (posicion *)malloc(sizeof(posicion)*canAbiertos);
	posicion * cerrados = (posicion *)malloc(sizeof(posicion)*canCerrados);
	posicion inicial = crearEstado(0, 0, correlativo, "");
	abiertos = agregarEstado(abiertos, &canAbiertos, inicial);
	while(canAbiertos > 0){
		bActual = abiertos[0];
		abiertos = sacarElemento(abiertos, &canAbiertos);
		cerrados = agregarEstado(cerrados, &canCerrados, bActual);
		if(esFinal(bActual,matriz) == 1){
			printf("Llegue\n");
			mostrarSolucion(cerrados,canCerrados-1);
			return 0;
		}else{
			//ARRIBA
			if(verificarArriba(bActual,matriz,dim) == 1){
				bSiguiente = arriba(bActual);
				if((estaEstado(abiertos,canAbiertos,bSiguiente) == 0) && (estaEstado(cerrados,canCerrados,bSiguiente) == 0)){
					abiertos = agregarEstado(abiertos,&canAbiertos,bSiguiente);
				}else{
					correlativo = correlativo - 1;
				}
			}
			//ABAJO
			if(verificarAbajo(bActual,matriz,dim) == 1){
				bSiguiente = abajo(bActual);
				if((estaEstado(abiertos,canAbiertos,bSiguiente) == 0) && (estaEstado(cerrados,canCerrados,bSiguiente) == 0)){
					abiertos = agregarEstado(abiertos,&canAbiertos,bSiguiente);
				}else{
					correlativo = correlativo - 1;
				}
			}
			//DERECHA
			if(verificarDerecha(bActual,matriz,dim) == 1){
				bSiguiente = derecha(bActual);
				if((estaEstado(abiertos,canAbiertos,bSiguiente) == 0) && (estaEstado(cerrados,canCerrados,bSiguiente) == 0)){
					abiertos = agregarEstado(abiertos,&canAbiertos,bSiguiente);
				}else{
					correlativo = correlativo - 1;
				}
			}
			//IZQUIERDA
			if(verificarIzquierda(bActual,matriz,dim) == 1){
				bSiguiente = izquierda(bActual);
				if((estaEstado(abiertos,canAbiertos,bSiguiente) == 0) && (estaEstado(cerrados,canCerrados,bSiguiente) == 0)){
					abiertos = agregarEstado(abiertos,&canAbiertos,bSiguiente);
				}else{
					correlativo = correlativo - 1;
				}
			}
			
		}

		printf("ABIERTOS:");
		for (int i = 0; i < canAbiertos; ++i)
		{
			imprimirEstado(abiertos[i]);
		}


		printf("\nCERRADOS:");
		for (int i = 0; i < canCerrados; ++i)
		{
			imprimirEstado(cerrados[i]);
		}
		printf("\n\n");
	}
    return 0;
}
