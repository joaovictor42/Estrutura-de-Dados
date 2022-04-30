#include <stdio.h>
#include <stdlib.h>
#include "arvBB.h"


//Nó da árvore binária de busca.
struct arv_no{
    int info;
    ArvNo* sae;//Subárvore à esquerda
    ArvNo* sad;//Subárvore à direita
};


//Tipo abstrato árvore binária de busca.
struct arv_bb{
    ArvNo* raiz;
};


/*Cria um novo nó.*/
ArvNo* novoNo(int valor){
    ArvNo* novoNo  = (ArvNo*) malloc(sizeof(ArvNo));
    novoNo->info   = valor;
    novoNo->sae    = NULL;
    novoNo->sad    = NULL;
    return novoNo;
}


/*Cria a representação do tipo abstrato árvore binária de busca.*/
ArvBB* abb_cria(void){
    ArvBB* abb = (ArvBB*) malloc(sizeof(ArvBB));
    abb->raiz = NULL;
    return abb;
}


/*Efetua a operação de inserção na árvore binária de busca a partir da raiz.*/
ArvNo* insereNo(ArvNo* raiz, int valor){
    if(raiz == NULL)
        return novoNo(valor);
    else if(valor < raiz->info)
        raiz->sae = insereNo(raiz->sae, valor);
    else if(valor > raiz->info)
        raiz->sad = insereNo(raiz->sad, valor);
    return raiz;
}


/*Efetua a operação de inserção sobre o tipo abstrato árvore binária de busca.*/
void abb_insere(ArvBB* abb, int valor){
    abb->raiz = insereNo(abb->raiz, valor);
}


/*Efetua a operação de busca na árvore binária de busca a partir da raiz.*/
ArvNo* busca(ArvNo* raiz, int valor){
    if(raiz == NULL || raiz->info == valor)//Verifica se o nó é nulo ou armazena o valor buscado
        return raiz;
    else if(valor < raiz->info)
        return busca(raiz->sae, valor);
    else
        return busca(raiz->sad, valor);
}


/*Efetua a operação de busca sobre o tipo abstrato árvore binária de busca.*/
ArvNo* abb_busca(ArvBB* abb, int valor){
    return busca(abb->raiz, valor);
}


/*Efetua a operação de remoção na árvore binária de busca a partir da raiz.*/
ArvNo* removeNo(ArvNo* raiz, int valor){
    if(raiz == NULL)
        return NULL;
    else if(valor < raiz->info)//Remove na sae
        raiz->sae = removeNo(raiz->sae, valor);
    else if(valor > raiz->info)//Remove na sad
        raiz->sad = removeNo(raiz->sad, valor);
    else{//Nó encontrado
        if(raiz->sae == NULL && raiz->sad == NULL){
            //Quando o nó a ser removido é uma folha
            free(raiz);
            return NULL;
        }
        else if(raiz->sae == NULL || raiz->sad == NULL){
            //Quando o nó a ser removido tem apenas um filho
            ArvNo* no = raiz;
            raiz = (raiz->sae)? raiz->sae : raiz->sad;//Armazena o nó filho
            free(no);
        }
        else{
            //Quando o nó a ser removido tem dois filhos
            ArvNo* precedente = raiz->sae;
            while(precedente->sad != NULL){//Busca o nó de maior valor, na sae do nó a ser removido
                precedente = precedente->sad;
            }
            //Troca de valores entre o nó a ser removido e seu precedente
            raiz->info = precedente->info;
            precedente->info = valor;
            raiz->sae = removeNo(raiz->sae, valor);//Efetua a remoção sobre a sae do nó.
        }
    }
    return raiz;
}


/*Efetua a operação de remoção sobre o tipo abstrato árvore binária de busca.*/
void abb_remove(ArvBB* abb, int valor){
    abb->raiz = removeNo(abb->raiz, valor);
}


/*Imprime a árvore em ordem simétrica a partir da raiz.*/
void imprime(ArvNo* raiz){
    if(raiz != NULL) {
        imprime(raiz->sae);
        printf("%d ", raiz->info);
        imprime(raiz->sad);
    }
}


/*Efetua a operação de impressão sobre o tipo abstrato árvore binária de busca.*/
void abb_imprime(ArvBB* abb){
    imprime(abb->raiz);
}


/*Libera, recursivamente, cada nó da árvore a partir da raiz.*/
void libera(ArvNo* raiz){
    if(raiz != NULL){
       libera(raiz->sae);
       libera(raiz->sad);
       free(raiz);
    }
}


/*Efetua a operação de liberação sobre o tipo abstrato árvore binária de busca.*/
void abb_libera(ArvBB* abb){
    libera(abb->raiz);
    free(abb);
}
