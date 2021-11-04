#include <stdio.h>
#include <stdlib.h>

void leerArchivoFGETS(char* nombre, char** data1){
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
        data1[i] = aux;
        i++;
    }
    fclose(arch);
}

int main(){
    char** data1 = (char**)malloc(100*sizeof(char*));
    for(int i=0;i<100;i++){
        data1[i] = (char*)malloc(100*sizeof(char));
    }
    leerArchivoFGETS("prueba.txt",data1);
    for(int i=0;i<3;i++){
        printf("%c",data1[i][0]);
    }
    free(data1);
    return 0;
}