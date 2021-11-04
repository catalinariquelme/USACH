#include <stdio.h>

// inicio y fin indican lugares especificos de la lista
// cuando va a partir la funcion inicio=0 y fin=n-1
int peak(int *a, int inicio, int fin) {
    int k=(inicio+fin)/2;
    printf("inicio:%d k:%d fin:%d\n",inicio,k,fin);
    // caso base
    // caso sencillo podria ser inicio==fin (pero esto no funciona bien)
    if (k==fin || k==inicio) { // la condicion para detectar que punto medio es un 
      // elemento del borde k=inicio o k=fin
       return(-1); // no lo encontre
    }else if (a[k]>a[k-1] && a[k]>a[k+1]) { // pregunto si es el peak
      return(a[k]); 
    }else { // caso general, punto medio esta separado de los bordes
             // el punto medio no es el peak
        
        // podemos descartar una de las dos mitades

        // veamos si es creciente
        if (a[k-1]<=a[k] && a[k]<=a[k+1]) {// se toma el lado derecho
          return(peak(a, k+1, fin));
        }
       
        // veamos si es decreciente
        if (a[k-1]>=a[k] && a[k]>=a[k+1]) {// se toma el lado izq
          return(peak(a, inicio, k));
        } 
    }
}

int main() {
  int a[]={1,30,30,10,9,8,7,6,5,4,3};

  printf("resultado=%d\n", peak(a,0,9)); 
}
