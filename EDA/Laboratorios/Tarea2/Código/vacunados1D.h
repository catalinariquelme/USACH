#include <stdio.h>
#include <stdlib.h>

struct vacunados1dosis;

typedef struct vacunados1dosis{
  char* rut;
  char* nombre;
  char* apellido;
  char* edad;
  char fecha1dosis[80];
  char* idVacuna;
  
}vacunados1dosis;

typedef struct nodo1D{
  struct vacunados1dosis vacunados1D;
  struct nodo1D * siguiente;
}nodo1D;

nodo1D* crearListaVacia1D(){
  nodo1D* lista=(nodo1D*)malloc(sizeof(nodo1D));
  lista=NULL;
  return lista;
}

/*
Entradas: lista(cabeza de la lista)
Salida: 1|0 (Dependiendo si se encuentra vácia o no)
Objetivo: determina si una lista se encuentra vácia
*/
int esListaVacia1D(nodo1D* lista){
  if (lista == NULL){
    return 1;
  }
  else
    return 0;
}

/*
Entradas: lista(cabeza de la lista), valor (dato a agregar)
Salida:-
Objetivo: insertar un dato al final de la lista entregada
*/
void insertarNodoFinal1D(nodo1D* lista, vacunados1dosis valor){
  nodo1D* nuevo=(nodo1D*)malloc(sizeof(nodo1D));
  nodo1D* final = lista;
  nuevo->vacunados1D=valor;
  nuevo->siguiente = NULL;
  if (esListaVacia1D(lista)){
    lista = nuevo;
  }
  else{
    while(final->siguiente != NULL){
      final = final->siguiente;
    }
    final->siguiente = nuevo;
  }
}

/*
Entradas: a(puntero), b(puntero)
Salida:-
Objetivo: intercambia hacia donde apunta los punteros del nodo a y b
*/
void intercambio1D(struct nodo1D *a, struct nodo1D *b){
    vacunados1dosis aux;
    aux = a->vacunados1D;
    a->vacunados1D = b->vacunados1D;
    b->vacunados1D = aux;
}
