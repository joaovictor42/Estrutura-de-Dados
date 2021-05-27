#include <stdio.h>
#include "SelectionSort.h"


#define troca(a, b) {int temp = a; a = b; b = temp;}


int selection(int vetor[], int n){
    int pos = 0;
    for(int i = 0; i < n; i++){
        if(vetor[i] > vetor[pos])
            pos = i;
    }
    return pos;
}


void selectionSort(int vetor[], int n){
    while(n > 1){
        int posMaiorValor = selection(vetor, n);
        troca(vetor[posMaiorValor], vetor[n-1]);
        n--;
    }
}
