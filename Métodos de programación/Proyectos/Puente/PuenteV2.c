// SECCIÓN: L-11
// PROFESOR DE LABORATORIO: IGNACIO IBÁÑEZ ALIAGA
//
// AUTORA
// NOMBRE: Catalina Riquelme Zamora
// RUT: 20.642.812-0
// FECHA: 11/01/2020

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct puente{
    int P1;
    int P2;
    int P3;
    int P4;
    int linterna;
    int tiempo;
	int idEstado;
	int estadoAnterior;
	char * transicion;
}
puente;

//Variable para crear los identificadores
int correlativo;
void mostrarSolucion(puente * lista, int ultimo,char** nombres,int tP1,int tP2,int tP3,int tP4);

//Entardas: int num1(primer número), int num2(segundo número)
//Salida: int resultado(número mayor)
//Objetivo: encontrar el número mayor entre dos números
int max(int num1, int num2) {
   int resultado;
   if (num1 > num2)
      resultado = num1;
   else
      resultado = num2;
   return resultado;
}

//Entardas: int ladoP1(lado en el que se encuentra la P1 (0|1)), int ladoP2(lado en el que se encuentra la P2 (0|1)),int ladoP3(lado en el que se encuentra la P3 (0|1))
//int ladoP4(lado en el que se encuentra la P4 (0|1)), int ladoLinterna(lado en el que se encuentra la linterna (0|1)), int anterior(estado anterior), char*t(transicion)
//int tiempoMax(tiempo maximo para cumplir el cruce)
//Salida: nuevoEstado(el estado actualizado)
//Objetivo: modificar el el estado
puente crearEstado(int ladoP1, int ladoP2,int ladoP3,int ladoP4,int ladoLinterna, int anterior, char * t,int tiempoMax){
	puente nuevoEstado;
	nuevoEstado.P1 = ladoP1;
    nuevoEstado.P2 = ladoP2;
    nuevoEstado.P3 = ladoP3;
    nuevoEstado.P4 = ladoP4;
    nuevoEstado.linterna = ladoLinterna;
	nuevoEstado.idEstado = correlativo;
	nuevoEstado.estadoAnterior = anterior;
	nuevoEstado.transicion = t;
	correlativo = correlativo + 1;
    nuevoEstado.tiempo = tiempoMax;
	return nuevoEstado;
}

//Entardas: puente* lista (abiertos|cerrados),int* elementos(cantidad abiertos o cerrados), puente estado(estado actual)
//Salida: nuevaLista (lista con nuevo estado)
//Objetivo: agregar un estado
puente * agregarEstado(puente * lista, int * elementos, puente estado){
	puente * nuevaLista = (puente *)malloc(sizeof(puente)*(*elementos+1));
	for (int i = 0; i < *elementos; ++i){
		nuevaLista[i] = lista[i];
	}
	nuevaLista[*elementos] = estado;
	*elementos = *elementos+1;
	free(lista);
	return nuevaLista;
}

//Entardas: puente* lista (abiertos|cerrados),int* elementos(cantidad abiertos o cerrados)
//Salida: nuevaLista (lista con nuevo estado)
//Objetivo: sacar un elemento
puente * sacarElemento(puente * lista, int * elementos){
	puente * nuevaLista = (puente *)malloc(sizeof(puente)*(*elementos-1));
	for (int i = 1; i < *elementos; ++i){
		nuevaLista[i-1]=lista[i];
	}
	*elementos = *elementos-1;
	free(lista);
	return nuevaLista;
}

//Entardas: puente b(estado), int tiempoTotal(tiempo total que se tiene para cruzar)
//Salida: int 1(en el caso que todos hallan cruzado), int 0(no han cruzado todos)
//Objetivo: determinar si todos han cruzado en un determinado tiempo
int esFinal(puente b,int tiempoTotal){
	if(b.P1 == 1 && b.P2 == 1 && b.P3 == 1 && b.P4 == 1 && b.linterna == 1 && b.tiempo <= tiempoTotal){
        return 1;
    }
	return 0;
}

//Entardas: puente* lista(abiertos|cerrados),int elementos(cantidad abiertos o cerrados), puente b(estado)
//Salida: int 1(se encuentra en la lista), int 0(no se encuentra en la lista)
//Objetivo: determinar si un estado se ecuentra en una lista(evitar repetición)
int estaEstado(puente * lista, int elementos, puente b){
	for (int i = 0; i < elementos; ++i){
		if((lista[i].P1 == b.P1) && (lista[i].P2 == b.P2) && (lista[i].P3 == b.P3) && (lista[i].P4 == b.P4) && (lista[i].tiempo == b.tiempo))
			return 1;
	}
    return 0;
}

//Entardas: puente * lista(cerrados), int ultimo(cantidad cerrados -1), char** nombres(nombres de las personas),int tP1(tiempo que tarda en cruzar la persona 1),
//int tP2(tiempo que tarda en cruzar la persona 2),int tP3(tiempo que tarda en cruzar la persona 3),int tP4(tiempo que tarda en cruzar la persona 4)
//Objetivo: mostrar al usuario los resultados de la busqueda
void mostrarSolucion(puente * lista, int ultimo, char** nombres,int tP1,int tP2,int tP3,int tP4){
	printf("Los movimientos son: \n");
    int tiempoFinal = 0;
	while(lista[ultimo].idEstado != 0){
        printf("-");
        if (lista[ultimo].transicion == "P1 P2 DERECHA"){
            printf("Cruza ");
            printf("%s ",nombres[0]);
            printf("y ");
            printf("%s ",nombres[1]);
            int tiempoPuente = max(tP1,tP2);
            tiempoFinal += tiempoPuente;
            printf("de la isla a la ciudad,demorando %d minutos se tiene un total de %d minutos.\n",tiempoPuente,tiempoFinal);
        }

        else if(lista[ultimo].transicion == "P1 P3 DERECHA"){
            printf("Cruza ");
            printf("%s ",nombres[0]);
            printf("y ");
            printf("%s ",nombres[2]);
            int tiempoPuente = max(tP1,tP3);
            tiempoFinal += tiempoPuente;
            printf("de la isla a la ciudad,demorando %d minutos se tiene un total de %d minutos.\n",tiempoPuente,tiempoFinal);
        }
        else if(lista[ultimo].transicion == "P1 P4 DERECHA"){
            printf("Cruza ");
            printf("%s ",nombres[0]);
            printf("y ");
            printf("%s ",nombres[3]);
            int tiempoPuente = max(tP1,tP4);
            tiempoFinal += tiempoPuente;
            printf("de la isla a la ciudad,demorando %d minutos se tiene un total de %d minutos.\n",tiempoPuente,tiempoFinal);
        }
        else if(lista[ultimo].transicion == "P2 P3 DERECHA"){
            printf("Cruza ");
            printf("%s ",nombres[1]);
            printf("y ");
            printf("%s ",nombres[2]);
            int tiempoPuente = max(tP2,tP3);
            tiempoFinal += tiempoPuente;
            printf("de la isla a la ciudad,demorando %d minutos se tiene un total de %d minutos.\n",tiempoPuente,tiempoFinal);
        }
        else if(lista[ultimo].transicion == "P2 P4 DERECHA"){
            printf("Cruza ");
            printf("%s ",nombres[1]);
            printf("y ");
            printf("%s ",nombres[3]);
            int tiempoPuente = max(tP2,tP4);
            tiempoFinal += tiempoPuente;
            printf(" demorando %d minutos,se tiene un total de %d minutos.\n",tiempoPuente,tiempoFinal);
        }
        else if(lista[ultimo].transicion == "P3 P4 DERECHA"){
            printf("Cruza ");
            printf("%s ",nombres[2]);
            printf("y ");
            printf("%s ",nombres[3]);
            int tiempoPuente = max(tP3,tP4);
            tiempoFinal += tiempoPuente;
            printf("de la ciudad a la isla demorando %d minutos se tiene un total de %d minutos.\n",tiempoPuente,tiempoFinal);
        }
        else if(lista[ultimo].transicion == "P1 IZQUIERDA"){
            printf("Cruza ");
            printf("%s ",nombres[0]);
            int tiempoPuente = tP1;
            tiempoFinal += tiempoPuente;
            printf("de la isla a la ciudad demorando %d minutos se tiene un total de %d minutos.\n",tiempoPuente,tiempoFinal);
        }
        else if(lista[ultimo].transicion == "P2 IZQUIERDA"){
            printf("Cruza ");
            printf("%s ",nombres[1]);
            int tiempoPuente = tP2;
            tiempoFinal += tiempoPuente;
            printf("de la isla a la ciudad demorando %d minutos se tiene un total de %d minutos.\n",tiempoPuente,tiempoFinal);
        }
        else if(lista[ultimo].transicion == "P3 IZQUIERDA"){
            printf("Cruza ");
            printf("%s ",nombres[2]);
            int tiempoPuente = tP3;
            tiempoFinal += tiempoPuente;
            printf("de la isla a la ciudad demorando %d minutos se tiene un total de %d minutos.\n",tiempoPuente,tiempoFinal);
        }
        else if(lista[ultimo].transicion == "P4 IZQUIERDA"){
            printf("Cruza ");
            printf("%s ",nombres[3]);
            int tiempoPuente = tP4;
            tiempoFinal += tiempoPuente;
            printf("de la isla a la ciudad demorando %d minutos se tiene un total de %d minutos.\n",tiempoPuente,tiempoFinal);
        }
        else{
            printf("Algo no calza\n");
        }
		ultimo = lista[ultimo].estadoAnterior;
	}
}


//VERIFICACIONES
//Entardas: puente estado(estado a analizar)
//Salida: int 1(en el caso que se pueda cruzar) int 0(en el caso que no se pueda cruzar)
//Objetivo: verificar si la(s) personas pueden cruzar

// TRANSICIONES
//Entardas: puente estado(estado a analizar),int tiempoPx(tiempo de una persona determinada x),int tiempoP2 (tiempo de una segunda persona determinada x)(en el caso que exista)
//Salida:crearEstado(estado p1,estado p2,estado P3,estado P4,estado linterna, estado.idEstado,transicion ,estado.tiempo+tiempo );
//Objetivo: crear un estado con la transicion realizada
int verificarP1P2D(puente estado){
    //Si P1 y P2 estan en la izquierda pueden cruzar a la derecha
    if(estado.P1 == 0 && estado.P2 == 0){
        return 1;
    }
    return 0;
}
puente P1P2D(puente estado,int tiempoP1,int tiempoP2){
    int tiempo =max(tiempoP1,tiempoP2);
    return crearEstado(1,1,estado.P3,estado.P4,1, estado.idEstado,"P1 P2 DERECHA",estado.tiempo+tiempo );
}
int verificarP1P3D(puente estado){
    if(estado.P1 == 0 && estado.P3 == 0 ){
        return 1;
    }
    return 0;
}
puente P1P3D(puente estado,int tiempoP1,int tiempoP3 ){
     int tiempo =max(tiempoP1,tiempoP3);
    return crearEstado(1,estado.P2,1,estado.P4,1, estado.idEstado, "P1 P3 DERECHA",estado.tiempo+tiempo);
}
int verificarP1P4D(puente estado){
    if(estado.P1 == 0 && estado.P4 == 0 ){
        return 1;
    }
    return 0;
}
puente P1P4D(puente estado,int tiempoP1,int tiempoP4 ){
     int tiempo =max(tiempoP1,tiempoP4);
    return crearEstado(1,estado.P2,estado.P3,1,1, estado.idEstado, "P1 P4 DERECHA",estado.tiempo+tiempo);
}
int verificarP2P3D(puente estado){
    if(estado.P2 == 0 && estado.P3 == 0 ){
        return 1;
    }
    return 0;
}
puente P2P3D(puente estado,int tiempoP2,int tiempoP3 ){
     int tiempo =max(tiempoP2,tiempoP3);
    return crearEstado(estado.P1,1,1,estado.P4,1, estado.idEstado, "P2 P3 DERECHA",estado.tiempo+tiempo);
}
int verificarP2P4D(puente estado){
    if(estado.P2 == 0 && estado.P4 == 0 ){
        return 1;
    }
    return 0;
}
puente P2P4D(puente estado,int tiempoP2,int tiempoP4 ){
     int tiempo =max(tiempoP2,tiempoP4);
    return crearEstado(estado.P1,1,estado.P3,1,1, estado.idEstado, "P2 P4 DERECHA",estado.tiempo+tiempo);
}
int verificarP3P4D(puente estado){
    if(estado.P3 == 0 && estado.P4 == 0 ){
        return 1;
    }
    return 0;
}
puente P3P4D(puente estado,int tiempoP3,int tiempoP4 ){
     int tiempo =max(tiempoP3,tiempoP4);
    return crearEstado(estado.P1,estado.P2,1,1,1, estado.idEstado, "P3 P4 DERECHA",estado.tiempo+tiempo);
}
int verificarP1I(puente estado){
    if(estado.P1 == 1){
        return 1;
    }
    return 0;
}
puente P1I(puente estado,int tiempoP1 ){
    int tiempo = tiempoP1;
    return crearEstado(0,estado.P2,estado.P3,estado.P4,0, estado.idEstado, "P1 IZQUIERDA",estado.tiempo+tiempo);
}
int verificarP2I(puente estado){
    if(estado.P2 == 1 ){
        return 1;
    }
    return 0;
}
puente P2I(puente estado,int tiempoP2 ){
     int tiempo = tiempoP2;
    return crearEstado(estado.P1,0,estado.P3,estado.P4,0, estado.idEstado, "P2 IZQUIERDA",estado.tiempo+tiempo);
}
int verificarP3I(puente estado){
    if(estado.P3 == 1){
        return 1;
    }
    return 0;
}
puente P3I(puente estado,int tiempoP3 ){
     int tiempo = tiempoP3;
    return crearEstado(estado.P1,estado.P2,0,estado.P4,0, estado.idEstado, "P3 IZQUIERDA",estado.tiempo+tiempo);
}
int verificarP4I(puente estado){
    if(estado.P4 == 1 ){
        return 1;
    }
    return 0;
}
puente P4I(puente estado,int tiempoP4 ){
     int tiempo = tiempoP4;
    return crearEstado(estado.P1,estado.P2,estado.P3,0,0, estado.idEstado, "P2 IZQUIERDA",estado.tiempo+tiempo);
}



int main(){
    //Se realiza un ciclo hasta que se vea interrumpido 
    while (0==0){
        printf("1)Ingresar la informacion del grupo para cruzar\n");
        printf("2)Salir del programa\n");
        printf("Indique la opcion (1|2):");
        int opcion;
        scanf("%d",&opcion);

        //Validación, solo se acepta 1 o 2
        while (opcion != 1 && opcion !=2){
            printf("Ingre un numero valido\n");
            printf("Indique la opcion (1|2):");
            scanf("%d",&opcion);
        }
        //En el caso que se desee salir del juego
        if (opcion == 2){
            printf("Adios, gracias por usar el programa");
            return 0;
        }
        else{
            //Variable con el tiempo que tienen para cruzar
            int tiempoTotal;
            printf("Tiempo para cruzar:");
            scanf("%d",&tiempoTotal);
            //Se guaradan los nombres de las personas
            char* nombres[4];
            //Se declaran las vareiables en donde se guardarán los tiempos de cada persona
            int tP1,tP2,tP3,tP4;
            int i =0;

            //Se ingresan los nombres de las personas y se almacenan
            char nombreP1[100];
            printf( "\nIntroduzca el nombre de la 1 persona: ");
            scanf("%s",nombreP1);
            nombres[0]=nombreP1;

            char nombreP2[100];
            printf( "Introduzca el nombre de la 2 persona: ");
            scanf("%s",nombreP2);
            nombres[1]=nombreP2;

            char nombreP3[100];
            printf( "Introduzca el nombre de la 3 persona: ");
            scanf("%s",nombreP3);
            nombres[2]=nombreP3;
            
            char nombreP4[100];
            printf( "Introduzca el nombre de la 4 persona: ");
            scanf("%s",nombreP4);
            nombres[3]=nombreP4;

            //Se almacenan los tiempos de cada persona
            printf("\nTiempo %s (en minutos):",nombres[0]);
            scanf("%d",&tP1);
            printf("Tiempo %s (en minutos):",nombres[1]);
            scanf("%d",&tP2);
            printf("Tiempo %s (en minutos):",nombres[2]);
            scanf("%d",&tP3);
            printf("Tiempo %s (en minutos):",nombres[3]);
            scanf("%d",&tP4);

            correlativo = 0;
            //Variable para guardar la cantidad estados se encuentran dentro del arreglo abiertos
            int canAbiertos = 0;
            //Variable para guardar la cantidad estados se encuentran dentro del arreglo cerrados
            int canCerrados = 0;
            puente pActual, pSiguiente;
            puente * abiertos = (puente *)malloc(sizeof(puente)*canAbiertos);
            puente * cerrados = (puente *)malloc(sizeof(puente)*canCerrados);
            //Al inicio todos parten en el lado izquierdo del puente(en la isla)
            puente inicial = crearEstado(0,0,0,0,0,correlativo,"",0);
            //En abiertos se agregar el estado inical
            abiertos = agregarEstado(abiertos, &canAbiertos, inicial);
            //Mientras queden estados abiertos se ejecutará
            while(canAbiertos > 0){
                pActual = abiertos[0];
                abiertos = sacarElemento(abiertos, &canAbiertos);
                cerrados = agregarEstado(cerrados, &canCerrados, pActual);
                
                //En el caso que se logre el estado final (todo se encuentren al otro lado)
                if(esFinal(pActual,tiempoTotal) == 1){
                    printf("\n");
                    mostrarSolucion(cerrados,canCerrados-1,nombres,tP1, tP2,tP3,tP4);
                    continue;
                }
                //En el caso que no logren pasar en el tiempo indicado
                else if(pActual.tiempo > tiempoTotal){
                    continue;
                }
                else{
                    switch (pActual.linterna){
                        //En caso que la linterna se encuentre en el lado original
                        case 0:
                        if (verificarP1P2D(pActual) == 1){
                            pSiguiente = P1P2D(pActual,tP1,tP2);

                            if((estaEstado(abiertos,canAbiertos,pSiguiente) == 0) && (estaEstado(cerrados,canCerrados,pSiguiente) == 0)){
                                abiertos = agregarEstado(abiertos,&canAbiertos,pSiguiente);
                            }else{
                                correlativo = correlativo - 1;
                            }
                        }

                        if (verificarP1P3D(pActual) == 1){
                            pSiguiente = P1P3D(pActual,tP1,tP3 );

                            if((estaEstado(abiertos,canAbiertos,pSiguiente) == 0) && (estaEstado(cerrados,canCerrados,pSiguiente) == 0)){
                                abiertos = agregarEstado(abiertos,&canAbiertos,pSiguiente);
                            }else{
                                correlativo = correlativo - 1;
                            }
                        }
                        
                        if (verificarP1P4D(pActual) == 1){
                            pSiguiente = P1P4D(pActual,tP1,tP4 );

                            if((estaEstado(abiertos,canAbiertos,pSiguiente) == 0) && (estaEstado(cerrados,canCerrados,pSiguiente) == 0)){
                                
                                abiertos = agregarEstado(abiertos,&canAbiertos,pSiguiente);
                            }else{
                                correlativo = correlativo - 1;
                            }
                        }
                        
                        if (verificarP2P3D(pActual) == 1){
                            pSiguiente = P2P3D(pActual,tP2,tP3 );

                            if((estaEstado(abiertos,canAbiertos,pSiguiente) == 0) && (estaEstado(cerrados,canCerrados,pSiguiente) == 0)){
                                abiertos = agregarEstado(abiertos,&canAbiertos,pSiguiente);
                            }else{
                                correlativo = correlativo - 1;
                            }
                        }
                        
                        if (verificarP2P4D(pActual) == 1){
                            pSiguiente = P2P4D(pActual,tP2,tP4 );

                            if((estaEstado(abiertos,canAbiertos,pSiguiente) == 0) && (estaEstado(cerrados,canCerrados,pSiguiente) == 0)){
                                abiertos = agregarEstado(abiertos,&canAbiertos,pSiguiente);
                            }else{
                                correlativo = correlativo - 1;
                            }
                        }

                        if (verificarP3P4D(pActual) == 1){
                                pSiguiente = P3P4D(pActual,tP3,tP4 );

                                if((estaEstado(abiertos,canAbiertos,pSiguiente) == 0) && (estaEstado(cerrados,canCerrados,pSiguiente) == 0)){
                                    abiertos = agregarEstado(abiertos,&canAbiertos,pSiguiente);
                                }
                                else{
                                    correlativo = correlativo - 1;
                                }
                            }
                        
                        //En el caso que la linterna se encuentre el otro lado
                        case 1:
                        if (verificarP1I(pActual) == 1){
                            pSiguiente = P1I(pActual,tP1 );

                            if((estaEstado(abiertos,canAbiertos,pSiguiente) == 0) && (estaEstado(cerrados,canCerrados,pSiguiente) == 0)){
                                abiertos = agregarEstado(abiertos,&canAbiertos,pSiguiente);
                            }else{
                                correlativo = correlativo - 1;
                            }
                        }
                        
                        if (verificarP2I(pActual) == 1){
                            pSiguiente = P2I(pActual,tP2 );

                            if((estaEstado(abiertos,canAbiertos,pSiguiente) == 0) && (estaEstado(cerrados,canCerrados,pSiguiente) == 0)){
                                abiertos = agregarEstado(abiertos,&canAbiertos,pSiguiente);
                            }else{
                                correlativo = correlativo - 1;
                            }
                        }
                        
                        if (verificarP3I(pActual) == 1){
                            pSiguiente = P3I(pActual,tP3 );

                            if((estaEstado(abiertos,canAbiertos,pSiguiente) == 0) && (estaEstado(cerrados,canCerrados,pSiguiente) == 0)){
                                abiertos = agregarEstado(abiertos,&canAbiertos,pSiguiente);
                            }else{
                                correlativo = correlativo - 1;
                            }
                        }

                        if (verificarP4I(pActual) == 1){
                                pSiguiente = P4I(pActual,tP4 );

                                if((estaEstado(abiertos,canAbiertos,pSiguiente) == 0) && (estaEstado(cerrados,canCerrados,pSiguiente) == 0)){
                                    abiertos = agregarEstado(abiertos,&canAbiertos,pSiguiente);
                                }
                                else{
                                    correlativo = correlativo - 1;
                                }
                            }
                    }    

                }
            }
            printf("El grupo no puede cruzar en el tiempo indicado\n");
        }
        printf("\nFINALIZO\n\n");
        printf("1)Continuar con el programa\n");
        printf("2)Salir del programa\n");
        printf("Indique la opcion (1|2):");
        int opcion2;
        scanf("%d",&opcion2);
        if (opcion2 == 2){
            printf("Adios, gracias por usar el programa");
            return 0;
        }
        //Validación, solo se acepta 1 o 2
        while (opcion2 != 1 && opcion2 !=2){
            printf("Ingre un numero valido\n");
            printf("Indique la opcion (1|2):");
            scanf("%d",&opcion2);
        }
        printf("\n");
    }
    return 0;
}