#include <stdio.h>
#include "InsertionSort.h"


#define troca(a, b) {int temp = a; a = b; b = temp;}


void insertion(int valor, int array[], int n){
    while(n > 0 && valor < array[n-1]){
        array[n] = array[n-1];
        n--;
    }
    array[n] = valor;
}


void insertionSort(int array[], int n){
    for(int i = 0; i < n; i++){
        insertion(array[i], array, i);
    }
}
