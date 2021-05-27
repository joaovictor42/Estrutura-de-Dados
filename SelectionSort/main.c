#include <stdio.h>
#include "SelectionSort.c"


void printArray(int array[], int n){
    for(int i = 0; i < n; i++){
        printf("%d ", array[i]);
    }
    printf("\n");
}


int main(){

    int array[] = {10,9,4,8,15,3,5,6,1,0,13,21};
    int tamanho = 12;

    selectionSort(array, tamanho);

    printArray(array, tamanho);

    return 0;
}
