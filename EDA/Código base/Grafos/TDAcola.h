#include <stdio.h>
#include <stdlib.h>

/*------------- estructura de datos -------------*/

typedef struct
{
  int capacidad;
  int size;
  nodo* frente;
  nodo* final;
}TDAcola;

/*------------- operaciones -------------*/

TDAcola* crearColaVacia(int capacidad)
{
  TDAcola* cola=(TDAcola*)malloc(sizeof(TDAcola));
  cola->capacidad=capacidad;
  cola->size=0;
  cola->frente=NULL;
  cola->final=NULL;
  return cola;
}


/*================== Semana 7 ===================*/

/*----------------- Actividad 3 -----------------*/
int esColaVacia(TDAcola* cola);
nodo* frente(TDAcola* cola);
nodo* final(TDAcola* cola);
void encolar(TDAcola* cola, int dato);
void descolar(TDAcola* cola);
