#include <stdio.h>
#include <stdlib.h>

/*--------------- estructura de datos -----------------*/

typedef struct nodoAVL{ 
  int dato;
	struct nodoAVL* padre;
	struct nodoAVL* hijoIzquierdo;
	struct nodoAVL* hijoDerecho;
}nodoArbolAVL;

typedef struct 
{	nodoArbolAVL* inicio;
}TDAarbolAVL;

/*--------------- operaciones de creación -----------------*/

nodoArbolAVL* crearNodoAVLVacio() {
  nodoArbolAVL* nodoAVL = (nodoArbolAVL*)malloc(sizeof(nodoArbolAVL));
	nodoAVL->dato= 0;
	nodoAVL->padre=NULL;
	nodoAVL->hijoIzquierdo=NULL;
	nodoAVL->hijoDerecho=NULL;
	return nodoAVL;
}

TDAarbolAVL* crearAVLVacio(){
  TDAarbolAVL* arbol=(TDAarbolAVL*)malloc(sizeof(TDAarbolAVL));
  arbol->inicio=NULL;
  return arbol;
}

int esAVLvacio(TDAarbolAVL* arbol){
  if (arbol->inicio == NULL)
    return 1;
  else
    return 0;
}


/*--------------- operaciones de posicion -----------------*/

//devuelve NULO si el árbol está vacío
nodoArbolAVL* raiz(TDAarbolAVL* arbol){
  if (arbol!=NULL)
    return arbol->inicio;
  return NULL;
}

nodoArbolAVL* padreNodoAVL(nodoArbolAVL* nodo){
  if (nodo!=NULL)
    return nodo->padre;
}

nodoArbolAVL* hijoIzqNodoAVL(nodoArbolAVL* nodo){
  if (nodo!=NULL)
    return nodo->hijoIzquierdo;
}

nodoArbolAVL* hijoDerNodoAVL(nodoArbolAVL* nodo){
  if (nodo!=NULL)
    return nodo->hijoDerecho;
}

int esHoja(nodoArbolAVL* nodo){
  if (nodo!=NULL){
    if ((nodo->hijoIzquierdo==NULL)&&(nodo->hijoDerecho==NULL))
      return 1;
  }
  return 0;
}

/*--------------- operaciones de recorrido -----------------*/
/*
Entradas: nodo 
Salida: -
Objetivo: entrega información consecutiva
*/
void recorridoInorden(nodoArbolAVL* nodo){
  if (nodo!=NULL){
    //hijo izquierdo
    recorridoInorden(nodo->hijoIzquierdo);
    // raiz
    printf("%d ",nodo->dato);
    // hijo derecho
    recorridoInorden(nodo->hijoDerecho);
  }
}

void recorridoInordenAVL(TDAarbolAVL* arbol){
  if (!esAVLvacio(arbol)){
    printf("INORDEN: ");
    recorridoInorden(arbol->inicio);
    printf("\n");
  }
  else
    printf("El árbol AVL está vacío\n");
}

/*------------------ operaciones de balance --------------------*/

int calcularAltura(nodoArbolAVL* nodo){
  if (nodo!=NULL){
    if (esHoja(nodo)) //nodo es una hoja
      return 1;
     //nodo NO es una hoja
    else{
      int alturaIzq=calcularAltura(nodo->hijoIzquierdo);
      int alturaDer=calcularAltura(nodo->hijoDerecho);
      if (alturaIzq > alturaDer)
        return alturaIzq+1;
      return alturaDer+1;
    }
  }
  else
    return 0;
}

int esBalanceadoNodoAVL(TDAarbolAVL* arbol, nodoArbolAVL* nodo){

}

void recuperarBalanceAVL(TDAarbolAVL* arbol, nodoArbolAVL* z);


/*--------------- operaciones de actualización -----------------*/

nodoArbolAVL* buscarNodoAVL(TDAarbolAVL* arbol, int dato);

void insertarNodoAVL(TDAarbolAVL* arbol, int dato){
  if (arbol ==NULL){
    nodoArbolAVL* nuevo = crearAVLVacio();
    nuevo->dato = dato;
    arbol = nuevo;
  }
  else{
    if (dato <= (arbol->inicio->dato)){
      insertarNodoAVL(arbol->inicio->hijoIzquierdo,dato);
    }
    else{
      insertarNodoAVL(arbol->inicio->hijoDerecho,dato);
    }
  }
}

void eliminarNodoAVL(TDAarbolAVL* arbol, int dato);

