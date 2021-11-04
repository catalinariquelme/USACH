// SECCIÓN: L-11
// PROFESOR DE LABORATORIO: IGNACIO IBÁÑEZ ALIAGA
//
// AUTORA
// NOMBRE: Catalina Riquelme Zamora
// RUT: 20.642.812-0

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <unistd.h>

void leerArchivoFGETS(char* nombre, char** data);
void imprimirTablero(int dimension,int tablero[][dimension]);
void escribirArchivo(int dimension,int dataSalida[][dimension],int generacionesTotales);

//Entardas: char*nombre(nombre del archivo a leer)
//Salida: int dimension(tamaño de las filas y columnas)
//Objetivo: leer y almacenar la primera línea del archivo (dimension)
int tamanoDimension(char* nombre){    
    FILE* arch;
    arch = fopen(nombre,"r");
    if(arch == NULL){
        printf("No existe el archivo\n");
        exit(1);
    }
    char* aux = (char*)malloc(100*sizeof(char));
    fgets(aux,100,arch);
    fclose(arch);
    int dimension;
    dimension = atoi(aux);
    return dimension;
}

//Entardas: char*nombre(nombre del archivo a leer),char**data(char en donde se alamacenará la información leída)
//Objetivo: leer y almacenar la información del archivo
void leerArchivoFGETS(char* nombre, char** data){
    FILE* arch;
    arch = fopen(nombre,"r");
    int i = 0;
    while(feof(arch) == 0){
        char* aux = (char*)malloc(100*sizeof(char));
        fgets(aux,100,arch);
        data[i] = aux;
        i++;
    }
    fclose(arch);
}

//Entardas: int dimension(tamaño de la matriz),int tablero(matriz en donde se encuentran los estados de las celulas)
//Objetivo: escibir un archivo que contenga la matriz pedida por el usuario
void escribirArchivo(int dimension,int tablero[][dimension],int generacionesTotales){
    FILE* arch;
    char nombreArchivo[100];
    sprintf(nombreArchivo,"Salida_gen%d.txt",generacionesTotales);
    int dataSalida[dimension-1][dimension-1];
    arch = fopen(("%s",nombreArchivo),"w");

    for (int i=0; i < dimension; i++){
        for (int j=0; j < dimension; j++){
            //1 = vivo
            if(tablero[i][j] == 1){
                dataSalida[i][j] = 'X';
            }
            //0 = muerto
            else if(tablero[i][j] == 0){
                dataSalida[i][j] = '_';
            }
            fputc(dataSalida[i][j],arch);
        }
        if (i != (dimension-1)){
            fputs("\n",arch);
        } 
    }
    fclose(arch);
}

//Entardas: int numero(numero que se verificará si es potencia de 2)
//Salida: bool(en el caso que sea true, esta es potencia de 2, por el contrario es es false)
//Objetivo: determinar si un número es potencia de 2 o no
int validacionPotencia2(int numero){
    while (numero % 2 == 0){
        numero = numero / 2;
        if (numero == 1){
            return true;
        }
    }
    return false;
}

//Entardas:char** data(char en donde se encuentra almacenada la infromación del archivo), int dimension(tamaño del cual debería ser la matriz)
//Salida: int 1(el archivo tiene un problema ya sea de dimension o de caracteres) o int 0(el archivo es correcto)
//Objetivo: determinar si el archivo ingresado por el usuario cumple con los parámetros 
int validacion(char** data,int dimension){
    for (int i=1; i <= dimension; i++){
        for (int j=0; j < dimension; j++){
            if( data[i][j] != 'X' && data[i][j] != '_'){
                return 1;
            }
        }
    }
    return 0;
}

//Entardas: int dimension(tamaño de la matriz),int tablero(matriz en donde se encuentran los estados de las celulas)
//Salida
//Objetivo: imprimir el estado de las celulas desde la matriz
void imprimirTablero(int dimension,int tablero[][dimension]){
    for (int i=0; i < dimension; i++){
        for (int j=0; j < dimension; j++){
            if (tablero[i][j] == 0){
                printf("_");
            }
            else{
                printf("X");
            }
            //printf("%d ",tableroNuevo[i][j]);
        }
        printf("\n");
    }
}

//Entardas:int dimension(tamaño de la matriz),int tablero(matriz en donde se encuentran los estados de las celulas), int fila(posición en la fila de la célula),int columna(posición en la columna de la célula)
//Salida: int vecinos(número de celulas vecinas que tiene cierta célula en cierta posición)
//Objetivo: determinar el número de células vecinas que tiene determinada célula
int numeroVecinos(int dimension,int tablero[][dimension], int fila, int columna){
    //Inicializar el numero de vecinos a cero
    int vecinos = 0;
 
    //Se recorren las celdas colidantes
    for(int j = fila-1; j < fila+2; j++){
        for(int i = columna-1; i < columna+2; i++){
            //En caso de que se encuentre la casilla central ,no se cuenta    
            if(j == fila && i == columna){
                vecinos = vecinos + 0;
            }
            else{
                //En el caso que este fuera de rango
                if(i < 0 || i >= dimension || j < 0 || j >= dimension){
                    vecinos = vecinos + 0;
                }
                else{
                    //Sumar el valor de la casilla vecina (+1 si esta viva, 0 si está muerta)
                    vecinos = vecinos + tablero[i][j];
                }
            }
        }
    }
    //Devolver el numero de vecinos
    return vecinos;
}

/*
//Objetivo: dividir la matriz hasta que quede 1x1, quedando una posicion
int posicionTablero(int dimension,int tablero[][dimension],int posicion,int inicio,int fin){
    
    //CASO BASE
    if (dimension ==1){
        //queda la posicion
    }
    
    int nuevaDimension = dimension/2;
    int nuevaMatriz[nuevaDimension][nuevaDimension];

    int i = 0;
    while(i<nuevaDimension){

        i++;
    }
}
*/

//Entardas:int dimension(tamaño de la matriz),int tablero(matriz en donde se encuentran los estados de las celulas),int generacionesTotales(número de generaciones que se verá el comportamiento de las células),
//int generacion(número de generacioón de la cual se esta calculando),int verTablero(opción del usuario para determinar si se desea ver por pantalla el procedimiento)
//Salida:int 0(cuando acaba el procedimiento), a si misma para calcular las generaciones que quedan
//Objetivo: realizar el cálculo si una célula vive o muere para la siguiente generación, además de determianr como quedará el tablero de estas mismas
int generaciones(int dimension,int tablero[][dimension], int generacionesTotales,int generacion,int verTablero){
    int fila,columna;
    int vecinos;
    //CASO BASE
    //En el caso que se completen las generaciones pasadas
    if (generacion == generacionesTotales){
        if(verTablero==1){
            printf("\nGENERACION %d\n",generacion);
            imprimirTablero(dimension,tablero);
        }
        escribirArchivo(dimension,tablero,generacionesTotales);
        printf("Archivo guaradado\n");
        printf("Programa finalizado");
        return 0;
    }
    //En el caso que quden generaciones que calcular
    else{
        int tableroNuevo[dimension][dimension];

        for (int i=1; i < dimension; i++){
            for (int j=0; j < dimension; j++){
                tableroNuevo[i][j] = tablero[i][j];
            }
        }
        for(int fila=0;fila<dimension;fila++){
            for(int columna=0; columna<dimension; columna++){
                vecinos = numeroVecinos(dimension,tablero,columna,fila);
               //Viva
               if (tablero[fila][columna]==1){
                   if (vecinos < 2 || vecinos >3){
                       tableroNuevo[fila][columna]= 0;
                   }
                   else{
                       tableroNuevo[fila][columna]= 1;
                   }
                }
                //Muerta
                else if (tablero[fila][columna]==0){
                    if (vecinos==3){
                        tableroNuevo[fila][columna]= 1;
                    }
                    else{
                        tableroNuevo[fila][columna]= 0;
                    }
                }
                vecinos = 0;
            }
        }
        if(verTablero==1){
            sleep(1);
            printf("\nGENERACION %d\n",generacion);
            imprimirTablero(dimension,tablero);
        }
        generacion+=1;
        return generaciones(dimension,tableroNuevo,generacionesTotales,generacion,verTablero);
    }
}

int main(){
    printf(" _____ _     _                              _        _               _     _       \n");
    printf("|  ___| |   (_)                            | |      | |             (_)   | |      \n");
    printf("| |__ | |    _ _   _  ___  __ _  ___     __| | ___  | | __ _  __   ___  __| | __ _ \n");
    printf("|  __|| |   | | | | |/ _ \\/ _` |/ _ \\   / _` |/ _ \\ | |/ _` | \\ \\ / / |/ _` |/ _` |\n");
    printf("| |___| |   | | |_| |  __/ (_| | (_) | | (_| |  __/ | | (_| |  \\ V /| | (_| | (_| |\n");
    printf("\\____/|_|   | |\\__,_|\\___|\\__, |\\___/   \\__,_|\\___| |_|\\__,_|   \\_/ |_|\\__,_|\\__,_|\n");
    printf("           _/ |            __/ |                                                   \n");
    printf("          |__/            |___/                                                    \n");

    //Modificar acá el nombre del archivo (nombre.txt)
    char* nombreArchivo = "Entrada2.txt";
    
    //Se imprime el menú para que el usuario escoja
    printf("\n1)Indicar la cantidad generaciones\n");
    printf("2)Salir del programa\n\n");
    printf("Indique la opcion (1|2):");
    int opcion;
    scanf("%d",&opcion);

    //En el caso que se desee salir del juego
    if (opcion == 2){
        printf("Adios, gracias por usar el programa");
        return 0;
    }
    //En el caso que se desee jugar
    else if (opcion ==1){
        int generacionesTotales;
        printf("Cantidad de generaciones a simular:");
        scanf("%d",&generacionesTotales);
        //En el caso que el número ingresado por el usuario sea negativo o 0
        while (generacionesTotales <= 0){
            printf("Ingrese un numero positivo\n");
            printf("Cantidad de generaciones a simular:");
            scanf("%d",&generacionesTotales);
        }
        int verTablero;
        printf("\nSe desea ver el tablero\n1)Si 2)No:");
        scanf("%d",&verTablero);
        //Se lee y se alamacena la dimension del archivo
        int dimension = tamanoDimension(nombreArchivo);
        //Se lee el archivo .txt
        char** data = (char**)malloc(dimension*sizeof(char*));
        for(int i=0;i<100;i++){
            data[i] = (char*)malloc(dimension*sizeof(char));
        }
        leerArchivoFGETS(nombreArchivo,data);
        //VALIDACIÓN ARCHIVO
        //Validación potencia de 2
        printf("\n");
        int potenciaDe2 = validacionPotencia2(dimension);
        if (potenciaDe2 == false){
            printf("El tamano de la matriz no es potencia de 2\n");
            printf("Corrija el archivo");
            return 0;
        }
        //Validacion caracteres X,_ y cantidad de filas y columnas respecto a la dimensión indicada
        int esX_ = validacion(data,dimension);
        if (esX_ == 1){
            printf("Hay un error con el archivo, recuerde colocar solo caracteres X _, ademas de colocar el numero de filas y columnas correctas\n");
            printf("Corrija el archivo");
            return 0;
        }
        //Se crea la matriz en donde se almacenarán las células
        int tablero[dimension][dimension];
        for (int i=1; i <= dimension; i++){
            for (int j=0; j < dimension; j++){
                //1 = vivo
                if( data[i][j] == 'X'){
                    tablero[i-1][j] = 1;
                }
                //0 = muerto
                else if(data[i][j] == '_'){
                    tablero[i-1][j] = 0;
                }
            }
        }
        if(verTablero==1){
            printf("GENERACION 0\n");
            for(int i=1;i<= dimension ;i++){
                printf("%s",data[i]);
            }
            printf("\n");
        }
        int generacion = 1;
        generaciones(dimension,tablero,generacionesTotales,generacion,verTablero);
        free(data);
        return 0;
        }
}