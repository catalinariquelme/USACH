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
      printf("%d ",auxiliar->dato);
      auxiliar=auxiliar->siguiente;
    }
    printf("\n");
  }
  else
    printf("La lista está vacía\n");
}

void insertarNodoInicio(TDAlista* lista, int valor){
  nodo* nuevo=(nodo*)malloc(sizeof(nodo));
  nuevo->dato=valor;
  nuevo->siguiente = lista->inicio;
  lista->inicio=nuevo;
}

void insertarNodoFinal(TDAlista* lista, int valor){
    nodo* nuevo=(nodo*)malloc(sizeof(nodo));
    nodo* final = lista;
    while(final->siguiente != NULL){
        final = final->siguiente;
    }
    nuevo->dato=valor;
    nuevo->siguiente = NULL;
    final->siguiente = lista;
}

void insertarNodoDespues(TDAlista* lista, int valor, int datoAnterior){
  nodo* nuevo=(nodo*)malloc(sizeof(nodo));
  nodo* anterior = lista;
  while(anterior->dato != datoAnterior){
    anterior = anterior -> siguiente;
  }
  nuevo->dato=valor;
  nuevo->siguiente = lista->inicio;
  anterior->siguiente = nuevo;
}

void eliminarInicio(TDAlista* lista){
  nodo* auxiliar;
  if(!esListaVacia(lista)){
    auxiliar=lista->inicio;
    lista->inicio=lista->inicio->siguiente;
    free(auxiliar);
  }
}

/*------------- Actividad 1 -------------*/
int buscarDato(TDAlista* lista, int dato);
void liberarLista(TDAlista* lista);
int obtenerNumeroNodos(TDAlista* lista);

/*------------- Actividad 2 -------------*/

void eliminarFinal(TDAlista* lista);
void eliminarDato(TDAlista* lista, int dato);
nodo* obtenerNodo(TDAlista* lista, int posicion);


int main()
{
  TDAlista * lista=crearListaVacia();
  recorrerLista(lista);
  insertarNodoInicio(lista,23);
  recorrerLista(lista);
  insertarNodoInicio(lista,44);
  recorrerLista(lista);
  return 0;
}