#include<stdio.h>
#include "QuickSort.h"


#define troca(a, b) {int temp = a; a = b; b = temp;}


int partition(int array[], int indexInicial, int indexFinal) {

    int pivo = array[indexFinal];

    // pointer for greater element
    int i = (indexInicial - 1);

    for(int j = indexInicial; j < indexFinal; j++){
        if(array[j] <= pivo){
            i++;
            troca(array[i], array[j]);
        }
    }
    // swap the pivot element with the greater element at i
    troca(array[i+1], array[indexFinal]);
    //Retorna posicao do pivo
    return i + 1;
}


void quickSort(int array[], int indexInicial, int indexFinal) {
    if (indexInicial < indexFinal) {

        int indexPivo = partition(array, indexInicial, indexFinal);

        quickSort(array, indexInicial, indexPivo-1);
        quickSort(array, indexPivo+1, indexFinal);
    }
}
