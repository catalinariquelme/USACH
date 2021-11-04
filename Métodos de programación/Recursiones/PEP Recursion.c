// SECCIÓN: A-1
// PROFESOR DE TEORIA: ALEJANDRO CISTERNA
//
// AUTORA
// NOMBRE: Catalina Riquelme Zamora
// RUT: 20.642.812-0

// Fecha: 27/11/2020
// VERSION: 2.0
// Objetivo:Desarrollar un programa capaz de conocer el número de la semana de colpaso del sistema de seguridad de un país dado los contagiados inicales
//y computadores totales

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//Entrada: entero(porcentajeColpaso(valor en donde el sistema se ve colpasado)),entero(computadoresTotales(universo computadores)),entero(contagiados(número de computadores que trasmiten el virus)),
//entero(infectados(número de computadores enfectadas pero que no transmiten enfermedad)),flotante(bloqueadosNuevos(número de computadores bloqueados que aprecen cada semana)).
//entero(bloqueadosTotales(número de bloqueados a traves de todas las semanas))
//Salida: entero (semana)
//Función que calcula el número de la semana en que colapsa la seguridad de un país
int estadoComputadores(int porcentajeColapso,int computadoresTotales,int *contagiados,int *semana,int *infectados,float *bloqueadosNuevos,int *bloqueadosTotales){
    printf("\n\n-----SEMANA %d------\n\n",*semana);
    printf("Infectados: %d\n",*infectados);
    printf("Contagiados: %d \n",*contagiados);
    printf("Nuevos bloqueados: %f\n",*bloqueadosNuevos);
    int bloqueadosEntero;
    //Se redondea el valor de los computadores bloqueados
    bloqueadosEntero= round(*bloqueadosNuevos);
    int contagiadosAnterior,infectadosAnterior;
    //Caso base (en caso que la semana de los contagiados y los infectados sea superior al 60% de los computadores totales)
    if ((*contagiados+ *infectados) > porcentajeColapso){
        *bloqueadosTotales = *bloqueadosTotales + bloqueadosEntero;
        printf("Bloqueados: %d\n",*bloqueadosTotales);
        //Termina la función, retornando la semana
        return *semana;
    }
    else{
        //Se preparan los datos para los calculos de la siguiente semana
        //Se guardan los datos contagiados e infectados
        contagiadosAnterior = *contagiados ;
        infectadosAnterior = *infectados;
        //Se calculan los contagiados e infectados que se ingresaran en la función estadoComputadores
        *contagiados = contagiadosAnterior + infectadosAnterior;
        *infectados = contagiadosAnterior * 5;
        //Se calculan los computadores bloqueados y se suman los computadores totales bloqueados a lo largo de la semana
        *bloqueadosNuevos = *contagiados * 0.025;
        *bloqueadosTotales = *bloqueadosTotales + bloqueadosEntero;
        printf("Bloqueados: %d\n",*bloqueadosTotales);
        //Se restan a los contagiados los computadores bloqueados ya que ya no pueden infectar
        *contagiados = *contagiados - *bloqueadosTotales;
        //Aumenta el número de la semana
        *semana += 1;
        return estadoComputadores(porcentajeColapso,computadoresTotales,contagiados,semana,infectados,bloqueadosNuevos,bloqueadosTotales);
    }
}

int main(){
    int computadoresTotales,contagiados,porcentajeColapso,semana,infectados,bloqueadosTotales,semanaColpaso;
    float bloqueadosNuevos;
    //Se solicitan los computadores totales con los cuales se van a trabajar
    printf("Ingrese el total de computadores: ");
    scanf("%d",&computadoresTotales);
    //En el caso que el usuario ingrese un número igual a 0 o negativo, terminará el programa, tendrá que volver a ejecutarlo con valores correctos
    if (computadoresTotales <= 0){
        printf("El numero de computadores no es valido, ejecute nuevamente el programa con valores positivos");
        return 0;
    }
    //Se solicitan la cantidad inical de computadores contagiantes
    printf("Ingrese la cantidad inical de contagiantes: ");
    scanf("%d",&contagiados);
    //En el caso que el usuario ingrese un número igual a 0 o negativo, terminará el programa,tendrá que volver a ejecutarlo con valores correctos
    if (contagiados <= 0){
        printf("El numero de contagiados no es valido, ejecute nuevamente el programa con valores positivos");
        return 0;
    }
    //Se calcula cuanl es el porcentaje de computadores tienen que estar infectados para que colaspse el sistema, dependiendo del total
    porcentajeColapso = computadoresTotales * 0.6;
    //Parten en 0 las variables de computadores bloqueados y la semana en la que se trabaja
    bloqueadosNuevos = 0;
    bloqueadosTotales = 0;
    infectados = 0;
    semana = 0;
    semanaColpaso = estadoComputadores(porcentajeColapso,computadoresTotales,&contagiados,&semana,&infectados,&bloqueadosNuevos,&bloqueadosTotales);
    //Se imprime el número de la semana
    printf("\nEl sistema de seguridad del pais colpaso en la semana %d\n",semanaColpaso);
    return 0;
}