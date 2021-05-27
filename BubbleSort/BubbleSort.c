#include <stdio.h>
#include "BubbleSort.h"


#define troca(a, b) {int temp = a; a = b; b = temp;}


void bubbleSort(int vetor[], int n){
    for(int i = 1; i < n; i++){
        int houveTroca = 0;
        for(int pos = 0; pos < n-i; pos++){
            if(vetor[pos] > vetor[pos+1]){
                troca(vetor[pos], vetor[pos+1]);
                houveTroca = 1;
            }
        }
        if(!houveTroca){
            break;
        }
    }
}
