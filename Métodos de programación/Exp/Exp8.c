//EXP 8

//Catalina Riquelme Z.
//20.642.812-0

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct ciudades ciudades;

struct ciudades{
	int ciudadOrigenL;
	int ciudadLlegada;
	int idEstado;
	int estadoAnterior;
};


void leerArchivo(char* nombre, char** data);
void leerArchivoCiudadesCaminos(char* nombre,int *cantudadCiudades,int *cantidadCaminos,int*arregloEnteros);

//Entardas: char*nombre(nombre del archivo a leer),char**data(char en donde se alamacenará la información leída)
//Objetivo: leer y almacenar la información del archivo
void leerArchivo(char* nombre, char** data){
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


//Entardas: char* nombre(nombre archivo),int *cantidadCiudades(número ciudades),int *cantidadCaminos(número caminos),int*arregloEnteros(arreglo en donde se almacenará la información (en enteros))
//Objetivo: leer y almacenar la información del archivo (sólo de la primera fila)
void leerArchivoCiudadesCaminos(char* nombre,int *cantudadCiudades,int *cantidadCaminos,int*arregloEnteros){
    FILE* arch;
    arch = fopen(nombre,"r");
    char* aux = (char*)malloc(100*sizeof(char));
    fgets(aux,100,arch);
    fclose(arch);
    //Se convierte a enteros para poder trabajar posteriormente
}

//Entrada:int arregloCiudades(conexiones de las ciudades)
//Salida: estado (Cerrado o abierto)
//Objetivo: determinar si el estado de una ciudad a otra es cerrado o abierto
int estadoCiudades(int arregloCiudades){
    //1 ABIERTO
    //0 CERRADO
    //Se realiza un ciclo analizando las conexiones, dejando cerrados las ciudades a las que se puede ir
}



int main(){
    int cantidadCiudades,cantidadCaminos;
    char* nombreArchivo = "Entrada.in";
    /*

    //Se lee la información sobre la cantidad de ciudades y camnimos(fila 1)
    filasColumnas(nombreArchivo,&cantidadCiudades,&cantidadCaminos,arregloEnteros);

    //Se lee la infromación de las ciudades en si
    leerArchivo(nombreArchivo,data)

    //int ciudad;
    printf("Ciudad a buscar:");
    scanf("%d",&ciudad);


    //Recorre lista en busca de la ciudad igresada por el usuario conociendo a que ciudades conecta
    //estadoCiudades()
    //Imprimir el listado de ciudades a las que no se puede ingresar(cerrado)

    */
}