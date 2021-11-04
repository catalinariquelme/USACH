//Experiencia 4
//Catalina Riquelme Z.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct perrito{
    char* nombre;
    char* raza;
    int edad;
    int sexo;
    int vacuna;
}
perritos;

void sexoPerritos(int cantidadPerritos,perritos*datosPerritos,int sexoPerrito);
void nombrePerritos(int cantidadPerritos,perritos*datosPerritos,char* nombrePerrito);
void vacunaPerritos(int cantidadPerritos,perritos*datosPerritos);

int main(){
    //En cantidadPerritos se almecena el número de perritos
    int cantidadPerritos;
    printf("Ingrese la cantidad de perritos: ");
    scanf("%d",&cantidadPerritos);
    perritos* datosPerritos;
    datosPerritos = (perritos*)malloc(sizeof(perritos)*cantidadPerritos);
    //Se le asigna memoria y se almacenan datos(ingresados por el usuario)
    for(int i = 0;i < cantidadPerritos;i++){
        datosPerritos[i].nombre = (char*)malloc(sizeof(char)*12);
        datosPerritos[i].raza = (char*)malloc(sizeof(char)*12);
        printf("\nPerrito %d\n\n",i+1);
        printf("Nombre: ");
        scanf("%s",datosPerritos[i].nombre);
        printf("Raza: ");
        scanf("%s",datosPerritos[i].raza);
        printf("Edad: ");
        scanf("%d",&datosPerritos[i].edad);
        printf("1)Hembra 2)Macho\n");
        printf("Sexo (1|2): ");
        scanf("%d",&datosPerritos[i].sexo);
        //En el caso que usuario ingrese un número distinto de 1 o 2, se le pide ingresar otro
        while (datosPerritos[i].sexo != 1 && datosPerritos[i].sexo != 2){
            printf("Dato erroneo\n");
            printf("1)Hembra 2)Macho\n");
            printf("Sexo (1|2): ");
            scanf("%d",&datosPerritos[i].sexo);
        }
        printf("1)Si 2)No\n");
        printf("Vacuna (1|2): ");
        scanf("%d",&datosPerritos[i].vacuna);
        //En el caso que usuario ingrese un número distinto de 1 o 2, se le pide ingresar otro
        while (datosPerritos[i].vacuna !=1 && datosPerritos[i].vacuna !=2){
            printf("Dato erroneo\n");
            printf("1)Si 2)No\n");
            printf("Vacuna (1|2): ");
            scanf("%d",&datosPerritos[i].vacuna);
        }
        printf("\n");
    }
    int j = 0;
    int numeroMenu;
    while (j == 0){
        printf("1)Buscar a un perrito por su nombre y mostrar toda su informacion\n");
        printf("2)Mostrar todos los nombres de los perritos de un cierto sexo\n");
        printf("3)Mostrar todos los nombres de los perritos vacunados\n");
        printf("4)Salir del programa\n\n");
        printf("Elija una opcion: ");
        scanf("%d",&numeroMenu);
        //Primera opción
        if (numeroMenu==1){
            char* nombrePerrito;
            nombrePerrito = (char*)malloc(sizeof(char)*12);
            printf("Nombre perrito:");
            scanf("%s",nombrePerrito);
            nombrePerritos(cantidadPerritos,datosPerritos,nombrePerrito);
            printf("\n");
        }
        //Segunda opción
        else if (numeroMenu==2){
            int sexoPerrito;
            printf("1)Hembra 2)Macho\n");
            printf("Sexo (1|2):");
            scanf("%d",&sexoPerrito);
            //En el caso que usuario ingrese un número distinto de 1 y 2, se le pide ingresar otro
            while (sexoPerrito != 1 && sexoPerrito != 2){
                printf("Dato erroneo\n");
                printf("1)Hembra 2)Macho\n");
                printf("Sexo (1|2): ");
                scanf("%d",&sexoPerrito);
            }
            printf("\nPerritos segun sexo: ");
            //En caso hembra(1)
            if (sexoPerrito == 1){
                sexoPerritos(cantidadPerritos,datosPerritos,1);
            }
            //En el caso macho(2)
            else if (sexoPerrito == 2){
                sexoPerritos(cantidadPerritos,datosPerritos,2);
            }
            printf("\n\n");
        }
        //Tercera opción
        else if (numeroMenu ==3){
            printf("\nPerritos vacunados: ");
            vacunaPerritos(cantidadPerritos,datosPerritos);
            printf("\n\n");
        }
        //Cuarta opción
        else if (numeroMenu==4){
            printf("Adios, gracias por usar el programa");
            break;
        }
        //En el caso que usuario ingrese un número distinto a 1,2,3 y 4
        else{
            printf("La opcion seleccionada no existe\n");
        }
    } 
    return 0;
}
//Función que recorre todos los nombres de los perritos para hayar similitud, en el caso de hacerlo imprime toda su información
void nombrePerritos(int cantidadPerritos,perritos*datosPerritos,char* nombrePerrito){
    int perritosNombre = 0;
    for(int i = 0; i < cantidadPerritos;i++){
        if (strcmp(nombrePerrito,datosPerritos[i].nombre)==0){
            printf("\nNombre: %s\n",datosPerritos[i].nombre);
            printf("Raza: %s\n",datosPerritos[i].raza);
            printf("Edad: %d\n",datosPerritos[i].edad);
            printf("Sexo: %d\n",datosPerritos[i].sexo);
            printf("Vacuna: %d\n",datosPerritos[i].vacuna);
            printf("\n");
            perritosNombre=+1;
        }
    }
    //En el caso que no se encuentre ningun perrito con ese nombre con contador perritoNombre quedará igual (0)
    if (perritosNombre == 0){
        printf("\nNo se encontro ningun perrito con ese nombre\n");
    }
}
//Función que recorre todos los sexos de los perritos e imprime el nombre de los perritos con cierto sexo seleccionado por el usuario
void sexoPerritos(int cantidadPerritos,perritos*datosPerritos,int sexoPerrito){
    for(int i=0; i < cantidadPerritos;i++){
        if (datosPerritos[i].sexo == sexoPerrito){
            printf("%s ",datosPerritos[i].nombre);
        }
    }
}
//Función que recorre todas vacunas de los perritos e imprime el nombre de los perrotos que esten vacunados (1)
void vacunaPerritos(int cantidadPerritos,perritos*datosPerritos){
    for(int i = 0;i < cantidadPerritos;i++){
        if (datosPerritos[i].vacuna == 1){
            printf("%s ",datosPerritos[i].nombre);
        }
    }
}