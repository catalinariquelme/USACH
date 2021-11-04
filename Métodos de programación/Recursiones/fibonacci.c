#include <stdio.h>

//Sucesion fibonacci

int fibonacci(int n){
    if(n<2){
        return n;
    }
    else{
        return fibonacci(n-1)+ fibonacci(n-2);
    }
        
}

int main(){
    printf("Fibonacci: %d",fibonacci(6));
    return 0;
}