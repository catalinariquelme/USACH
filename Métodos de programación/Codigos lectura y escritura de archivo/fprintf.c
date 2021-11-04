#include <stdio.h>
#include <stdlib.h>

void escribirArchivo(char** data){
    FILE* arch;

    arch = fopen("respuesta.txt","w");

    for(int i=0;i<3;i++){
        fprintf(arch,data[i]);
    }

    fprintf(arch,"\n(%s)","Hola mundo");

    fclose(arch);
}

void leerArchivo(char* nombre, char** data){
    FILE* arch;
    arch = fopen(nombre,"r");
    if(arch == NULL){
        printf("No existe el archivo\n");
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
    char** data = (char**)malloc(100*sizeof(char*));
    for(int i=0;i<100;i++){
        data[i] = (char*)malloc(100*sizeof(char));
    }
    leerArchivo("prueba.txt",data);
    for(int i=0;i<3;i++){
        printf("%s",data[i]);
    }
    escribirArchivo(data);

    free(data);
    return 0;
}