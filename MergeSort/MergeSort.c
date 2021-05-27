#include<stdio.h>
#include "MergeSort.h"


void merge(int array[], int indexInicial, int indexCentral, int indexFinal){
    int i, j, k;//Iteradores

    //Tamanho dos subarrays auxiliares
    int n1 = indexCentral - indexInicial + 1;
    int n2 = indexFinal - indexCentral;

    //Subarrays auxiliares
    int arrayAuxiliar1[n1], arrayAuxiliar2[n2];

    //Copia os dados do array para subarrays auxiliares
    for (i = 0; i < n1; i++)
        arrayAuxiliar1[i] = array[indexInicial + i];

    for (j = 0; j < n2; j++)
        arrayAuxiliar2[j] = array[indexCentral + 1 + j];

    i = 0; //Iterador de arrayAuxiliar1
    j = 0; //Iterador de arrayAuxiliar2
    k = indexInicial; //Iterador de array (array de combinação)

    //Efetua a combinação dos valores dos subarrays na variavel array
    while (i < n1 && j < n2) {
        if (arrayAuxiliar1[i] <= arrayAuxiliar2[j]) {
            array[k] = arrayAuxiliar1[i];
            i++;
        }
        else {
            array[k] = arrayAuxiliar2[j];
            j++;
        }
        k++;
    }

    //Copia os elementos restantes de arrayAxiliar1, se existir algum
    while (i < n1) {
        array[k] = arrayAuxiliar1[i];
        i++;
        k++;
    }

    //Copia os elementos restantes de arrayAxiliar2, se existir algum
    while (j < n2) {
        array[k] = arrayAuxiliar2[j];
        j++;
        k++;
    }
}


void mergeSort(int array[], int indexInicial, int IndexFinal){
    if (indexInicial < IndexFinal) {

        int indexCentral = indexInicial + (IndexFinal - indexInicial) / 2;

        mergeSort(array, indexInicial, indexCentral);
        mergeSort(array, indexCentral + 1, IndexFinal);

        merge(array, indexInicial, indexCentral, IndexFinal);
    }
}
