#include <stdio.h>
#include <stdlib.h>

//No dirigido
typedef struct nodoAB{
  int dato;
  struct nodoAB* padre;
  struct nodoAB* hijoIzquierdo;
  struct nodoAB* hijoDerecho;
}nodoArbolBinario;

typedef struct {
  nodoArbolBinario* inicio;
}TDAarbolBinario;

/*
Entradas: -
Salida: nodo árbol binario
Objetivo: crear un nuevo nodo vácio
*/
nodoArbolBinario*crearNodoVacio(){
  nodoArbolBinario* nuevoNodo = (nodoArbolBinario*)malloc(sizeof(nodoArbolBinario)); 
  nuevoNodo->dato = 0;
  nuevoNodo->padre = 0;
  nuevoNodo->hijoIzquierdo = 0;
  nuevoNodo->hijoDerecho = 0;

  return nuevoNodo;
}

/*
Entradas: -
Salida: arbolBinario
Objetivo: crear árbol binario vácio
*/
TDAarbolBinario* crearArbolBinarioVacio(){
  TDAarbolBinario* arbolBinario=(TDAarbolBinario*)malloc(sizeof(TDAarbolBinario));
  arbolBinario->inicio=NULL;
  return arbolBinario;
}

/*
Entradas: arbolBinario 
Salida: 1(vácio) | 0 (no vácio)
Objetivo: verificar si un árbol esta vácio
*/
int esArbolBinarioVacio(TDAarbolBinario* arbolBinario){
  if (arbolBinario->inicio == NULL)
    return 1;
  else
    return 0;
}


//devuelve NULO si el árbol está vacío
nodoArbolBinario* raiz(TDAarbolBinario* arbol){
  if (arbol!=NULL)
    return arbol->inicio;
  return NULL;
}

// devuelve NULO si no existe
nodoArbolBinario* padreNodoAB(TDAarbolBinario* arbol, nodoArbolBinario* nodo){
  if (nodo!=NULL)
    return nodo->padre;
}

/*
Entradas: arbol (arbolBinario), nodo
Salida: 1 (es hoja) | 0 ( no es hoja)
Objetivo: crear árbol binario 
*/
int esHoja(TDAarbolBinario* arbol, nodoArbolBinario* nodo){
  if (!esArbolBinarioVacio(arbol)){
    if ((nodo->hijoIzquierdo==NULL)&&(nodo->hijoDerecho==NULL))
      return 1;
  }
  return 0;
}

/*--------------- operaciones de recorrido -----------------*/

void recorridoInordenArbolBinario(TDAarbolBinario* arbol);
void recorridoPreordenArbolBinario(TDAarbolBinario* arbol);
void recorridoPostordenArbolBinario(TDAarbolBinario* arbol);

/*--------------- operaciones de actualización -----------------*/

/*
Entradas: arbol(árbol binario), padre, dato, tipoHijo
Salida: arbol
Objetivo: insertar nodo en arbol binario (tipoHijo={0 (izquierdo), 1 (derecho)})
*/
TDAarbolBinario* insertarNodo(TDAarbolBinario* arbol, int padre, int dato, int tipoHijo){
  nodoArbolBinario*nodoPadre = buscarDato(arbol->inicio,padre);
  nodoArbolBinario* nuevoNodo = crearNodoVacio();
  if(nodoPadre != NULL){
    nuevoNodo->dato=dato;
  }
  else{
    if(nodoPadre->hijoIzquierdo==NULL && tipoHijo==0){
      nodoPadre->hijoIzquierdo = nuevoNodo;
      nuevoNodo->padre = nodoPadre;
    }
    else if(nodoPadre->hijoDerecho==NULL && tipoHijo==1){
      nodoPadre->hijoDerecho = nuevoNodo;
      nuevoNodo->padre = nodoPadre;
    }
  }
}


void eliminarNodo(TDAarbolBinario* arbol, int dato);
nodoArbolBinario* buscarNodo(TDAarbolBinario* arbol, int dato){

}


