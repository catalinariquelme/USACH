#include <stdio.h>
#include <stdlib.h>
 
void merge(int arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;
 
    int L[n1], R[n2];
 
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];
 
    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
 
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
 
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}
 
void mergeSort(int arr[], int l, int r)
{
    if (l < r) {
        int m = l + (r - l) / 2;
 
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
 
        merge(arr, l, m, r);
    }
}

int binarySearch(int arr[], int l, int r, int x) 
{ 
    if (r >= l) { 
        int mid = l + (r - l) / 2; 

        if (arr[mid] == x) 
            return mid; 

        if (arr[mid] > x) 
            return binarySearch(arr, l, mid - 1, x);

        return binarySearch(arr, mid + 1, r, x); 
    }
    return -1; 
} 
 
void printArray(int A[], int size) {
    int i;
    for (i = 0; i < size; i++)
        printf("%d ", A[i]);
    printf("\n");
}

int main() {
    int arreglo[] = { 12, 11, 13, 5, 6, 7, 8, 9, 10 };
    int tam_arreglo = sizeof(arreglo) / sizeof(arreglo[0]);
 
    printf("El arreglo de entrada es :\n");
    printArray(arreglo, tam_arreglo);
 
    mergeSort(arreglo, 0, tam_arreglo - 1);
 
    printf("\nEl arreglo ordenado es :\n");
    printArray(arreglo, tam_arreglo);

    for(int i = 1; i < arreglo[tam_arreglo - 1]; i++) {
    	if (binarySearch(arreglo, 0, tam_arreglo - 1, i) == -1) {
    		printf("El elemento mas pequeno que falta en el arreglo es el %d\n", i);
    		return 0;
    	}
    }
    printf("No faltan elementos en el arreglo\n");
    return 0;
}