//Experiencia 5

#include <stdio.h>
#include<stdbool.h>

//Entrada: entero (número), entero(i)
//Salida: booleano (true = primo,false = no es primo)
//Función que determina si un número es primo devolviendo un booleano
bool primo(int numero, int *i){
    if (*i == 1){
        return true;
    }
    else if (numero % *i == 0){
        return false;
    }
    else{
        *i -= 1;
        return primo(numero, i);
    }
}

//Entrada: entero(número), entero(j)
//Salida: entero (0)
//Función que determina los factores de un número
int factores(int numero,int *j){
    bool esPrimo;
    int i;
    //Se averigua si el numero ingresado a la función es primo o no
    i = numero -1;
    esPrimo = primo(numero,&i);
    //En el caso que lo sea es caso base y se imprime, y terminando con la función
    if (esPrimo == true){
        printf("%d ",numero);
        return 0;
    }
    //En el caso que no sea primo el número, significa que es compuesto y que hay que descomponer
    else{
        //En el caso que el números sea divisible por j se obtiene un nuevo valor para número y se reinicia el j a 2 (este es el primo más pequeño)
        if (numero % *j == 0){
            printf("%d ",*j);
            numero = numero / *j;
            *j = 2;
            return factores(numero,j);
        }
        //En el caso que el número no sea divisible por j, se mantiene el valor de número y aumenta en 1 el valor de j
        else{
            *j= *j +1;
            return factores(numero,j);
        }
    }
}

int main(){
    int numero,i;
    bool numeroEsPrimo;
    printf("Ingrese un numero: ");
    scanf("%d",&numero);
    //Si el número ingresado por el usuario es 1 o 0 no se puede descomponer
    if (numero <= 1 ){
        printf("No se puede expresar en factores");
    }
    //Si el número es mayor a 1 se descompone
    else{
        i = numero -1;
        numeroEsPrimo = primo(numero,&i);
        //En caso de que el número sea ya primo, no se puede descomponer más por lo que se imprime su valor
        if (numeroEsPrimo == true){
            printf("Factor: %d",numero);
        }
        //De lo contrario es necesario trabajar descomponiendo el numero dado
        else{
            i = 2;
            printf("Factores:");
            factores(numero,&i);
        }
    }
}