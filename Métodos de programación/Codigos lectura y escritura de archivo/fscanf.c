#include <stdio.h>
#include <stdlib.h>

void leerArchivo(char* nombre, char*** data){
    FILE* arch;
    arch = fopen(nombre,"r");
    if(arch == NULL){
        printf("No existe el archivo\n");
        exit(1);
    }
    int i = 0;
    while(feof(arch) == 0){
        char* aux = (char*)malloc(100*sizeof(char));
        char* aux2 = (char*)malloc(100*sizeof(char));
        char* aux3 = (char*)malloc(100*sizeof(char));
        fscanf(arch,"%s %s %s",aux,aux2,aux3);
        data[i][0] = aux;
        data[i][1] = aux2;
        data[i][2] = aux3;
        i++;
    }
    fclose(arch);
}

int main(){
    char*** data = (char***)malloc(100*sizeof(char**));
    for(int i=0;i<100;i++){
        data[i] = (char**)malloc(100*sizeof(char*));
    }
    leerArchivo("prueba.txt",data);
    for(int i=0;i<3;i++){
        for(int j = 0;j<3;j++){
            printf("%s",data[i][j]);
        }
    }
    free(data);
    return 0;
}