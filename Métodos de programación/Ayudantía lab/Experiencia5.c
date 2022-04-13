#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int iterativa(int n){
    int* sucesion = (int*)malloc(sizeof(int)*n);
    //Casos base
    sucesion[0]=0;
    sucesion[1]=0;
    sucesion[2]=1;
    int i=3;
    while (i < n){
      sucesion[i]= sucesion[i-1]+sucesion[i-2]+sucesion[i-3];
      i++;
    }
    return sucesion[i-1];
}

int recursionCola(int n){
  if(n==1)
    return 0;

  else if (n==2)
    return 0;

  else if(n==3)
    return 1;
  
  else
    return recursionCola(n-1) + recursionCola(n-2) +recursionCola(n-3);
}

int recursionPila(int n,int resultado){
  if(n<3)
    return resultado;
  else
    return recursionPila(n-1,resultado + n);
}

int main(){
    clock_t start, finish, duration;
    printf("NUMEROS TRIBONACCI\n\n");
    int numero;
    printf("Ingrese posicion de la secuencia: ");
    scanf("%d",&numero);


    
    start = clock();
    int resultado = iterativa(numero);
    printf("\nPor iteracion: %d\n",resultado);
    finish = clock();
    printf("Tiempo: %f\n\n", ((double) (finish - start)) / CLOCKS_PER_SEC );

    start = clock();
    int resultado2 = recursionCola(numero);
    printf("\nPor cola: %d\n",resultado2);
    finish = clock();
    printf("Tiempo: %f\n\n", ((double) (finish - start)) / CLOCKS_PER_SEC );

    start = clock();
    int resultado3 = recursionPila(numero,0);
    printf("\nPor pila: %d\n",resultado3);
    finish = clock();
    printf("Tiempo: %f\n\n", ((double) (finish - start)) / CLOCKS_PER_SEC );
  
    return 0;
}