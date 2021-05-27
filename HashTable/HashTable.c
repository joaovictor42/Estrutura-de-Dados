#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include "HashTable.h"

/*Função de hash universal.*/
int hash(HashTable* ht, int key){
    return ((ht->randomValue1*key + ht->randomValue2) % P) % TABLE_SIZE;
}


/*Cria um novo elemento para tabela com a chave fornecida, retornando seu endereço.*/
Node* createNode(int key){
    Node* newNode = (Node*) malloc(sizeof(Node));
    if(newNode){
        newNode->data = key;
        newNode->next = NULL;
    }
    return newNode;
}


/*Cria uma tabela hash, retornando seu endereço.*/
HashTable* createHashTable(void){

    HashTable* ht = (HashTable*) malloc(sizeof(HashTable));

    if(!ht) return NULL;

    ht->tableSize = TABLE_SIZE;
    ht->currentSize = 0;

    //Semente para geração de número aleatorio
    srand(time(0));

    //Atribuição contantes aleatórias da função de hash universal
    ht->randomValue1 = rand() % P;
    ht->randomValue2 = rand() % P;

    //Alocação do array da tabela hash
    Node** buckets = (Node**) malloc(TABLE_SIZE * sizeof(Node*));

    if(buckets){
        ht->buckets = buckets;

        //Seta os buckts para NULL
        for(int i = 0; i < TABLE_SIZE; i++) {
            ht->buckets[i] = NULL;
        }
    }
    else{//Se nao conseguiu alocar o array, desaloca a tabela hash
        free(ht);
        return NULL;
    }

    return ht;
}


/*Adiciona o nó no inicio da lista encadeada.*/
void prependNode(Node** head, Node* newNode) {
    newNode->next = *head;
    *head = newNode;
}


/*Insere um elemento na tabela hash.*/
int insertHashTable(HashTable** ht, int key){
    if(!(*ht)){//Se houver uma tabela, uma tabela sera criada
        *ht = createHashTable();
        if(*ht) return -1;
    }

    unsigned hashCode = hash(*ht, key);

    Node* newNode = createNode(key);

    if(!newNode) return -1;

    //Inserir nó no bucket
    if(!(*ht)->buckets[hashCode]){
        (*ht)->buckets[hashCode] = newNode;
    }else{//Inserir nó na lista encadeada
        prependNode(&(*ht)->buckets[hashCode], newNode);
    }

    (*ht)->currentSize++;

    return 0;
}


/*Procura um elemento na tabela hash, retornando seu endereço.*/
Node* searchHashTable(HashTable* ht, int key){

    if(!ht) return NULL;

    unsigned hashCode = hash(ht, key);

    Node* current = ht->buckets[hashCode];

    while(current){//Porcura elemento na lista encadeada
        if(current->data == key)
            return current;
        current = current->next;
    }

    return current;
}


/*Remove um elemento da tabela hash.*/
void removeNode(HashTable* ht, int key){

    if(!ht) return;

    unsigned hashCode = hash(ht, key);

    if(!ht->buckets[hashCode]) return;

    Node* temp = ht->buckets[hashCode];
    Node* prev;

    //Remove elemento na primeira posicao da lista encadeada
    if(temp->data == key) {
        ht->buckets[hashCode] = temp->next;
        free(temp);
        ht->currentSize--;
        return;
    }

    //Remove elemento após a primeira posicao da lista encadeada
    while(temp != NULL && temp->data != key){
        prev = temp;
        temp = temp->next;
    }

    if(temp == NULL) return;

    prev->next = temp->next;

    free(temp);

    ht->currentSize--;
}


/*Libera a lista encadeada.*/
void freeLinkedList(Node** head){

    Node* current = *head;
    Node* next;

    //Percorre a lista encadeada liberando cada elemento
    while(current){
        next = current->next;
        free(current);
        current = next;
    }

    *head = NULL;
}


/*Libera a tabela hash.*/
void freeHashTable(HashTable** ht){
    if(!(*ht)) return;

    //Libera a lista encadeada de cada bucket
    for(int i = 0; i < (*ht)->tableSize; i++){
        freeLinkedList(&((*ht)->buckets[i]));
    }

    free((*ht)->buckets);//Libera o array
    free(*ht);//Libera a tabela
    *ht = NULL;//Seta o ponteiro que aponta para tabela para NULL
}


/*Imprime a tabela hash, mostrando os elementos armazenados em cada bucket.*/
void printHashTable(HashTable* ht){

    if(!ht) return;

    for(int i = 0; i < TABLE_SIZE; i++){
        Node* node = ht->buckets[i];

        if(!node) continue;

        while(node) {
            printf("%d ", node->data);
            node = node->next;
        }
        printf("\n");
    }
}
