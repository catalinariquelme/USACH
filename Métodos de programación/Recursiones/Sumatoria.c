#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Sumatoria primeros 10 números

int sumatoria_recursiva(int n){
    if(n <= 0){
        return 0;
    }
    return n + sumatoria_recursiva(n-1);
}


int main () {
    int n = 10;
    printf("Recursiva: %d",sumatoria_recursiva(n));
    return 0;
}


