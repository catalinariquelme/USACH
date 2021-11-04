//Experiencia 2

#include <stdio.h>
#include<stdbool.h>
void calculoPrimo (bool *esPrimo, int primerNumero);
int main(){
    int numeroMenu,primerNumero,j;
    j = 0;
    while (j =! 0){
        printf("1)Consulta si un numero es primo\t2)Numeros primos entre dos numeros\n");
        printf("3)Suma de los primos entre dos numeros\t4)Salir del programa\n\n");
        printf("Eliga una opcion: ");
        scanf("%d",&numeroMenu);
        if (numeroMenu==1){
            bool esPrimo = true;
            int primerNumero;
            printf("Ingrese un numero: ");
            scanf("%d",&primerNumero); 
            calculoPrimo(&esPrimo,primerNumero);
            if (esPrimo == false || primerNumero == 1){
                printf("No es primo\n\n");
            }
            else{
                printf("Es primo\n\n");
            }
        }else if (numeroMenu==2){
            int primerNumero,segundoNumero;
            bool esPrimo;
            printf("Ingrese el primer numero: ");
            scanf("%d",&primerNumero);
            printf("Ingrese el segundo numero: ");
            scanf("%d",&segundoNumero);
            printf("Los numeros primos son: ");

            while (primerNumero <= segundoNumero){
                esPrimo = true;
                calculoPrimo(&esPrimo,primerNumero);
                if (esPrimo == true && primerNumero != 1){
                    printf("%i ",primerNumero);
                }
                primerNumero = primerNumero + 1;
            }
            printf("\n\n");
        }
        else if (numeroMenu==3){
            int primerNumero,segundoNumero,suma;
            bool esPrimo;
            printf("Ingrese el primer numero: ");
            scanf("%d",&primerNumero);
            printf("Ingrese el segundo numero: ");
            scanf("%d",&segundoNumero);
            suma = 0;
    
            while (primerNumero <= segundoNumero){
                esPrimo = true;
                calculoPrimo(&esPrimo,primerNumero);
                if (esPrimo == true && primerNumero != 1){
                    suma = suma+ primerNumero;
                }
                primerNumero = primerNumero + 1;
            }
            printf("La suma entre los numeros primos son: %i",suma);
            printf("\n\n");
        }
        else if (numeroMenu==4){
            printf("Adios, gracias por usar el programa");
            break;
        }  
        else{
            printf("La opcion seleccionada no existe\n");
        }
    }
    return 0;
}
void calculoPrimo (bool *esPrimo, int primerNumero){
    int i = 2;
    while (i < primerNumero){
        if (primerNumero % i == 0){
            *esPrimo = false;
        }
        i = i+1;
    }
}