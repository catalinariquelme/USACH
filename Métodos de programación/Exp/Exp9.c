//EXP 9

//Catalina Riquelme Z.
//20.642.812-0

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct ciudad{
	int ciudadOrigen;
	int ciudadLlegada;
	int idEstado;
	int estadoAnterior;
	char * transicion;
}
ciudad;

int correlativo;

void leerArchivo(char* nombre, char** data);
void leerArchivoCiudadesCaminos(char* nombre,int *cantudadCiudades,int *cantidadCaminos,int*arregloEnteros);

//Entardas: char** data(información de la matriz),int** arregloEnteros(matriz en donde se guardaran los números convertidos a enteros),int filas(número filas),int columnas(número columnas)
//Objetivo: convertir una matriz de char a enteros
void convertirArreglo(char** data,int** arregloEnteros,int filas){
    for(int i=1;i<=filas;i++){
        char* token;
        //printf("32\n");
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
    *cantudadCiudades = arregloEnteros[0];
    *cantidadCaminos = arregloEnteros[1];
    free(aux);
}

//Entrada:int arregloCiudades(conexiones de las ciudades)
//Salida: estado (Cerrado o abierto)
//Objetivo: determinar si el estado de una ciudad a otra es cerrado o abierto
int estadoCiudades(int arregloCiudades){
    //1 ABIERTO
    //0 CERRADO
    //Se realiza un ciclo analizando las conexiones, dejando cerrados las ciudades a las que se puede ir
}



ciudad crearEstado(int cOrigen, int cFinal, int anterior, char * t){
	ciudad nuevoEstado;
	nuevoEstado.ciudadOrigen = cOrigen;
    nuevoEstado.ciudadLlegada = cFinal;
	nuevoEstado.idEstado = correlativo;
	nuevoEstado.estadoAnterior = anterior;
	nuevoEstado.transicion = t;
	correlativo = correlativo + 1;
	return nuevoEstado;
}
ciudad * agregarEstado(ciudad * lista, int * elementos, ciudad estado){
	ciudad * nuevaLista = (ciudad *)malloc(sizeof(ciudad)*(*elementos+1));
	for (int i = 0; i < *elementos; ++i){
		nuevaLista[i] = lista[i];
	}
	nuevaLista[*elementos] = estado;
	*elementos = *elementos+1;
	free(lista);
	return nuevaLista;
}
ciudad * sacarElemento(ciudad * lista, int * elementos){
	ciudad * nuevaLista = (ciudad *)malloc(sizeof(ciudad)*(*elementos-1));
	for (int i = 1; i < *elementos; ++i){
		nuevaLista[i-1]=lista[i];
	}
	*elementos = *elementos-1;
	free(lista);
	return nuevaLista;
}

int esFinal(ciudad b){
	if(){
        return 1;
    }
	return 0;
}




void mostrarSolucion(ciudad * lista, int ultimo){
	printf("Los pasos son, del ultimo al primero: \n");
	while(lista[ultimo].idEstado != 0){
		printf("%s\n", lista[ultimo].transicion);
		ultimo = lista[ultimo].estadoAnterior;
	}
}


int main(){
    int cantidadCiudades,cantidadCaminos;
    char* nombreArchivo = "Entrada.in";
    //PARA LEER LA INFORMACIÓN DE CIDADES Y CAMINOS (solo 1 fila)
    int* arregloEnterosCC = (int*)malloc(1000*sizeof(int*));
    printf("1\n");
    leerArchivoCiudadesCaminos(nombreArchivo,&cantidadCiudades,&cantidadCaminos,arregloEnterosCC);

    printf("Cantidad ciudades: %d\n",cantidadCiudades);
    printf("Cantidad caminos: %d\n",cantidadCaminos);
    //SE CREA ARREGLO DE ENTEROS para transformar la información del resto de la matriz
    char** data = (char**)malloc(100*sizeof(char*));
    for(int i=0;i<100;i++){
        data[i] = (char*)malloc(100);
    }
    leerArchivo(nombreArchivo,data);
    //SE CREA ARREGLO DE ENTEROS para almacenar lo números en su versión entera
    int** arregloEnteros = (int**)malloc(1000*sizeof(int*));
    for(int i=0;i<100;i++){
        arregloEnteros[i] = (int*)malloc(100*sizeof(int));
    }
    convertirArreglo(data,arregloEnteros,cantidadCaminos);
    
    for(int i=1;i<cantidadCaminos;i++){
        for(int j = 0; j<2;j++){
            printf("%d",arregloEnteros[i][j]);
            if (j ==0){
                printf("-> ");
            }
        }
        printf("\n");
    }


    int ciudadPartida;
    printf("Ciudad a buscar:");
    scanf("%d",&ciudadPartida);

    //Variable para crear los identificadores
    correlativo = 0;
    //Variable para guardar la cantidad estados se encuentran dentro del arreglo abiertos
	int canAbiertos = 0;
    //Variable para guardar la cantidad estados se encuentran dentro del arreglo cerrados
	int canCerrados = 0;

    ciudad cActual, cSiguiente;
	ciudad * abiertos = (ciudad *)malloc(sizeof(ciudad)*canAbiertos);
    ciudad * cerrados = (ciudad *)malloc(sizeof(ciudad)*canCerrados);
    //Al inicio todos parten en el lado izquierdo del puente(en la isla)
    ciudad inicial = crearEstado(arregloEnteros[1][0],arregloEnteros[1][1],correlativo,"");
    //En abiertos se agregar el estado inical
    abiertos = agregarEstado(abiertos, &canAbiertos, inicial);
    while(canAbiertos > 0){
        cActual = abiertos[0];
		abiertos = sacarElemento(abiertos, &canAbiertos);
		cerrados = agregarEstado(cerrados, &canCerrados, cActual);
		if(esFinal(cActual) == 1){
			printf("Llegue\n");
			mostrarSolucion(cerrados,canCerrados-1);
			return 0;
		}
        else{

        }

		printf("ABIERTOS:");
		for (int i = 0; i < canAbiertos; ++i)
		{
			imprimirEstado(abiertos[i]);
		}
		
		printf("\nCERRADOS:");
		for (int i = 0; i < canCerrados; ++i)
		{
			imprimirEstado(cerrados[i]);
		}
		printf("\n\n");
    }
    
    
    
    
    /*
    //Recorre lista en busca de la ciudad igresada por el usuario conociendo a que ciudades conecta
    //estadoCiudades()
    //Imprimir el listado de ciudades a las que no se puede ingresar(cerrado)

    */
}