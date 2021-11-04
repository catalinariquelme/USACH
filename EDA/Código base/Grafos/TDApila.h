#include <stdio.h>
#include <stdlib.h>

/*------------- estructura de datos -------------*/
typedef struct
{
  int capacidad;
  int size;
  nodo* tope;
}TDApila;


/*------------- operaciones -------------*/

TDApila* crearPilaVacia(int capacidad){
  TDApila* pila=(TDApila*)malloc(sizeof(TDApila));
  pila->capacidad=capacidad;
  pila->size=0;
  pila->tope=NULL;
  return pila;
}

int esPilaVacia(TDApila* pila){
  if (pila->size == 0)
    return 1;
  else
    return 0;
}


/*================== Semana 7 ===================*/

/*----------------- Actividad 1 -----------------*/
void apilar(TDApila* pila, int dato){
  if (pila->size < pila->capacidad)
  {
    nodo* nuevo=(nodo*)malloc(sizeof(nodo));
    nuevo->dato=dato;
    nuevo->siguiente = pila->tope;
    pila->tope=nuevo;
    pila->size=pila->size+1;
  }
  else
    printf("La pila está llena\n");
}


nodo* tope(TDApila* pila);

void desapilar(TDApila* pila);

/*----------------- Actividad 2 -----------------*/
int buscarDatoPila(TDApila* pila, int dato);