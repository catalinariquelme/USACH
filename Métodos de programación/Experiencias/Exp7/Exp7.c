//EXP 7

//Catalina Riquelme Z.
//20.642.812-0

#include <stdio.h>
#include <stdlib.h>
#include <string.h>



void filasColumnas(char* nombre,int *filas,int *columnas,int *arregloEnteros);
void convertirArreglo(char** data,int** arregloEnteros,int filas,int columnas);

//Entardas: char** data(información de la matriz),int** arregloEnteros(matriz en donde se guardaran los números convertidos a enteros),int filas(número filas),int columnas(número columnas)
//Objetivo: convertir una matriz de char a enteros
void convertirArreglo(char** data,int** arregloEnteros,int filas,int columnas){
    for(int i=1;i<=filas;i++){
        char* token;
        token = strtok(data[i]," ");
        int numero;
        numero = atoi(token);
        int j=0;
        while(token!=NULL){
            numero = atoi(token);
            token = strtok(NULL," ");
            arregloEnteros[i][j]=numero;
            j++;
        }                        
    }
}

//Entardas: char* nombre(nombre archivo),int *filas(número filas),int *columnas(número columnas),int*arregloEnteros(arreglo en donde se almacenará la información (en enteros))
//Salida: int dimension(tamaño de las filas y columnas)
//Objetivo: leer y almacenar la primera línea del archivo (dimension tanto de las filas y columnas)
void filasColumnas(char* nombre,int *filas,int *columnas,int*arregloEnteros){    
    FILE* arch;
    arch = fopen(nombre,"r");
    char* aux = (char*)malloc(100*sizeof(char));
    fgets(aux,100,arch);
    fclose(arch);
    char* token;
    token = strtok(aux," ");
    int numero;
    numero = atoi(token);
    int i=0;
    while(token!=NULL){
        numero = atoi(token);
        token = strtok(NULL," ");
        arregloEnteros[i]=numero;
        i++;
        }          
    *filas = arregloEnteros[0];
    *columnas = arregloEnteros[1];
    free(aux);
}

//Entardas: char*nombre(nombre del archivo a leer),char**data(char en donde se alamacenará la información leída)
//Objetivo: leer y almacenar la información del archivo
void leerArchivoFGETS(char* nombre, char** data){
    FILE* arch;
    if(arch == NULL){
        printf("No existe el archivo\n");
        exit(1);
    }
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

//Entardas:int *matriz(matriz(Se ingresa una sola fila) en donde se enucuentran los números a analizar),int inicio(posición inicial del array),int fin,int numero(posición final del array))
//Salida: 0 (se encuentra en el array), -1(no se encuentra en el array)
//Objetivo: División y conquista, busqueda binaria para encontrar la posicion de determinado número, para saber si se encuentra o no
int busquedaBinaria(int *matriz,int inicio,int fin,int numero){
    int pivote = (inicio+ fin)/2;
    int valorPivote = matriz[pivote];
    //No esta en el arreglo
    if(pivote==fin || pivote==inicio){
        return -1;
    }
    //CASO BASE
    //Esta en el arreglo
    if (valorPivote == numero){
        return 0;
    }
    else{
        if (valorPivote < numero){
            inicio = pivote;
            fin = fin;
        }
        else if(valorPivote > numero){
            inicio = inicio;
            fin = pivote;
        }
        //Hace recursion con los valores de inicio y fin modificados dependiendo del valor del pivote
        return busquedaBinaria(matriz,inicio,fin,numero);
    }
}

int main(){
    int filas,columnas;
    char* nombreArchivo = "Matriz.in";
    //PARA LEER LA INFORMACIÓN DE FILAS Y COLUMNAS (solo 1 fila)
    int* arregloEnterosFC = (int*)malloc(1000*sizeof(int*));
    filasColumnas(nombreArchivo,&filas,&columnas,arregloEnterosFC);
    //SE CREA ARREGLO DE ENTEROS para transformar la información del resto de la matriz
    char** data = (char**)malloc(100*sizeof(char*));
    for(int i=0;i<100;i++){
        data[i] = (char*)malloc(100);
    }
    leerArchivoFGETS(nombreArchivo,data);
    //SE CREA ARREGLO DE ENTEROS para almacenar lo números en su versión entera
    int** arregloEnteros = (int**)malloc(1000*sizeof(int*));
    for(int i=0;i<100;i++){
        arregloEnteros[i] = (int*)malloc(100*sizeof(int));
    }
    convertirArreglo(data,arregloEnteros,filas,columnas);
    //Se traspasa al tablero definitivo 
    int matriz[filas][columnas];
    for(int i=1;i<filas;i++){
        for(int j=0;j<columnas;j++){
            matriz[i][j]=arregloEnteros[i+1][j];
        }
    }
    int numero;
    printf("Numero a buscar:");
    scanf("%d",&numero);
    //Se analiza cada columna pa ver si esta la basura de número
    int fin = columnas;
    int inicio = 0;
    for(int i=0;i<filas;i++){
        int resultado = busquedaBinaria(matriz[i],inicio,fin,numero);
        //En el caso que el retorno sea igual a 0 significa que se encontro el número en el analísis, por lo que finaliza el progranma
        if (resultado== 0){
            //+2 contando la línea que indica las filas y columnas, además de 
            printf("El numero se encuentra en la matriz, en la fila %d del archivo",i+2);
            free(arregloEnterosFC);
            free(arregloEnteros);
            return 0;
        }
    }
    //En el caso que no se encuentre ninguna coincidencia en el ciclo significa que se analizo toda la matriz y no hay similitudes
    printf("No se encuentra en la matriz");
    free(arregloEnterosFC);
    free(arregloEnteros);
    return 0;
}