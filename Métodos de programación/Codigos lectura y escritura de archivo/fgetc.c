#include <stdio.h>
#include <stdlib.h>

void leerArchivo(char* nombre, char* data){
    FILE* arch;
    arch = fopen(nombre,"r");
    if(arch == NULL){
        printf("No existe el archivo\n");
        exit(1);
    }
    int i = 0;
    while(feof(arch) == 0){
        char aux;
        aux = fgetc(arch);
        data[i] = aux;
        i++;
    }
    fclose(arch);
}

int main(){
    char* data = (char*)malloc(100*sizeof(char));
    leerArchivo("prueba.txt",data);
    for(int i=0;i<55;i++){
        printf("%c\n",data[i]);
    }
    free(data);
    return 0;
}