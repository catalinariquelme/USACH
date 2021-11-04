#include <stdio.h>
#include <stdlib.h>

/*---------- estructura de datos ----------*/

typedef struct nodoGenerico{
  int dato;
  struct nodoGenerico* siguiente;
}nodo;

typedef struct listaGenerica{
  nodo* inicio;
}TDAlista;


/*------------- operaciones -------------*/

TDAlista* crearListaVacia(){
  TDAlista* lista=(TDAlista*)malloc(sizeof(TDAlista));
  lista->inicio=NULL;
  return lista;
}

int esListaVacia(TDAlista* lista){
  if (lista->inicio == NULL)
    return 1;
  else
    return 0;
}

void recorrerLista(TDAlista* lista){
  if (!esListaVacia(lista)){
    nodo* auxiliar=lista->inicio;
    while (auxiliar!=NULL){
      printf("%s  ",auxiliar->dato);
      auxiliar=auxiliar->siguiente;
    }
    printf("\n");
  }
  else
    printf("La lista está vacia\n");
}

void insertarNodoInicio(TDAlista* lista, char* valor){
  nodo* nuevo=(nodo*)malloc(sizeof(nodo));
  nuevo->dato=valor;
  nuevo->siguiente = lista->inicio;
  lista->inicio=nuevo;
}

void insertarNodoFinal(TDAlista* lista, char* valor){
  nodo* nuevo=(nodo*)malloc(sizeof(nodo));
  nodo* final = lista->inicio;
  nuevo->dato=valor;
  nuevo->siguiente = NULL;
  if (esListaVacia(lista)){
    lista->inicio = nuevo;
    
  }
  else{
    while(final->siguiente != NULL){
        final = final->siguiente;
    }
    final->siguiente = nuevo;
  }
}


int main(){
  TDAlista * lista=crearListaVacia();

  insertarNodoFinal(lista, 23);
  //printf("Lista [%d]",lista->inicio->dato);
  recorrerLista(lista);
  insertarNodoFinal(lista,44);
  recorrerLista(lista);
  return 0;
}