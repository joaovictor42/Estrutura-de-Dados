#ifndef TABELAHASH_H_INCLUDED
#define TABELAHASH_H_INCLUDED

#define TABLE_SIZE 100
#define P 547


//Nó da tabela hash
struct node{
    int data;
    struct Node *next;
};

typedef struct node Node;


//Tabela hash
struct hashTable{
    int randomValue1;//Variavel aleatória do hash universal
    int randomValue2;//Variavel aleatória do hash universal
    int tableSize;
    int currentSize;
    Node** buckets;
};

typedef struct hashTable HashTable;


//Cria tabela hash
HashTable* createHashTable();

//Insere um novo elemento na tabela hash
int insertHashTable(HashTable** ht, int key);

//Busca um um elemento na tabela hash
Node* searchHashTable(HashTable* ht, int key);

//Libera a tabela hash
void freeHashTable(HashTable** ht);

//Printa todos os elementos da tabela hash
void printHashTable(HashTable* ht);

#endif // TABELAHASH_H_INCLUDED
