#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void copiar_a_arregloEnteros(char** data,int** enteros,int lineas){
    for(int i=1;i<=lineas;i++){
        int j=0;
        int largoLinea=0;
        while(data[i][j]!='\0'){
            largoLinea++;
            j++;
        }
        char auxiliar[largoLinea];
        //COPIA A AUX.
        for(int p=0;p<largoLinea;p++){
            auxiliar[p]=data[i][p];
        }
        char* token;
        token = strtok(auxiliar," ");
        int numero;
        numero = atoi(token);
        int m=0;
        while(token!=NULL){
            //printf("Token: %s\n",token);
            numero = atoi(token);
            token = strtok(NULL," ");
            //printf("En entero: %d\n",numero);
            enteros[i][m]=numero;
            printf("Arreglo entero posicion [%d][%d] es igual a %d\n",i,m,numero);
            m++;
        }                        
    }

}

void leerArchivo(char* nombre, char** data){
    FILE* arch;
    arch = fopen(nombre,"r");
    if(arch == NULL){
        printf("No existe el archivo.\n");
        exit(1);
    }
    int i = 0;
    while(feof(arch) == 0){
        char* aux = (char*)malloc(100*sizeof(char));
        fgets(aux,100,arch);
        data[i] = aux;
        i++;
    }
    fclose(arch);
}


int main(){
    char** alturas = (char**)malloc(100*sizeof(char*));
    for(int i=0;i<100;i++){
        alturas[i] = (char*)malloc(100*sizeof(char));
    }

    leerArchivo("Cordilleras.in",alturas);
    int numeroLineas;
    for(int i=0;i<1;i++){//se lee la primera linea, que nos permite saber la dimension del archivo
        char *cadena = alturas[i];
        numeroLineas = atoi(cadena);//n es equivalente al numero de lineas.
        free(cadena);
    }
    //CONTENIDO DEL ARCHIVO
    printf("Cordilleras.in\n");    
    for(int i=0;i<numeroLineas+1;i++){//Se imprime el texto leido,i=0 nos indica la dimension
        printf("%s",alturas[i]);//Desde i=1, tenemos los datos.
    }
    printf("\n\n");
    
    numeroLineas = numeroLineas;

    //SE CREA ARREGLO DE ENTEROS
    int** arregloEnteros = (int**)malloc(1000*sizeof(int*));
    for(int i=0;i<100;i++){
        arregloEnteros[i] = (int*)malloc(100*sizeof(int));
    } 

    copiar_a_arregloEnteros(alturas,arregloEnteros,numeroLineas); 

    printf("En arreglo de enteros. \n");  
    //prueba  
    printf("%d ", arregloEnteros[1][0]);
    printf("\n\n");
    return 0;
}