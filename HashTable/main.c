#include <stdio.h>
#include "HashTable.c"


int main(){

    HashTable* hashTable = createHashTable();

    for(int i = 0; i < 250; i++){
        insertHashTable(&hashTable, i);
    }

    printHashTable(hashTable);

    puts("");

    Node* noInicial = searchHashTable(hashTable, 0);
    printf("Valor encontrado = %d\n", noInicial->data);

    Node* noMedio = searchHashTable(hashTable, 20);
    printf("Valor encontrado = %d\n", noMedio->data);

    Node* noFinal = searchHashTable(hashTable, 40);
    printf("Valor encontrado = %d\n", noFinal->data);

    puts("");

    int itens1[] = {30, 20, 10, 0, 21, 11, 1, 12, 2, 3};

    for(int i = 0; i < 10; i++){
        removeNode(hashTable, itens1[i]);
    }

    int itens2[] = {47, 37, 27, 17, 7};

    for(int i = 0; i < 5; i++){
        removeNode(hashTable, itens2[i]);
    }

    removeNode(hashTable, 47);
    removeNode(hashTable, 37);

    insertHashTable(&hashTable, 47);

    removeNode(hashTable, 47);

    insertHashTable(&hashTable, 7);

    printHashTable(hashTable);

    puts("");

    printf("Tabela Liberada\n\n");

    freeHashTable(&hashTable);

    printf("Valor da tabela hash pós liberação = %p\n",  hashTable);

    return 0;
}
