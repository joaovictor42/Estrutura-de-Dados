#include <stdio.h>
#include <stdlib.h>
#include "arvBin.h"


//Nó da árvore binária.
struct arv_no{
    int info;
    ArvNo* sae;//Subárvore à esquerda
    ArvNo* sad;//Subárvore à direita
};


//Tipo abstrato árvore binária.
struct arv{
    ArvNo* raiz;
};


/*Cria um nó, recebendo como parâmetro respectivamente,
seu valor, subárvore à esquerda e subárvore à direita.*/
ArvNo* arv_criaNo(int valor, ArvNo* sae, ArvNo* sad){
    ArvNo* raiz = (ArvNo*) malloc(sizeof(ArvNo));
    raiz->info = valor;
    raiz->sae = sae;
    raiz->sad = sad;
    return raiz;
}


/*Cria a representação do tipo abstrato árvore binária, recebendo como parâmetro um nó.*/
Arv* arv_cria(ArvNo* raiz){
    Arv* arv = (Arv*) malloc(sizeof(Arv));
    arv->raiz = raiz;
    return arv;
}


/*Busca, recursivamente, um valor na árvore binária a partir da raiz.*/
ArvNo* busca(ArvNo* raiz, int valor){
    if(raiz == NULL || raiz->info == valor){//Verifica se o nó é nulo ou armazena o valor buscado
        return raiz;
    }
    else{
        ArvNo* busca_sae = busca(raiz->sae, valor);//Busca o valor na subárvore à esquerda
        return (busca_sae) ? busca_sae : busca(raiz->sad, valor);//Caso não tenha encontrado na sae, busca na sad
    }
}


/*Efetua a operação de busca sobre o tipo abstrato árvore binária.*/
ArvNo* arv_busca(Arv* arv, int valor){
    return busca(arv->raiz, valor);
}


/*Imprime a árvore em ordem simétrica a partir da raiz.*/
void imprime(ArvNo* raiz){
    if(raiz != NULL){
        imprime(raiz->sae);
        printf("%c ", raiz->info);
        imprime(raiz->sad);
    }
}


/*Efetua a operação de impressão sobre o tipo abstrato árvore binária.*/
void arv_imprime(Arv* arv){
    imprime(arv->raiz);
}


/*Libera, recursivamente, cada nó da árvore a partir da raiz.*/
void libera(ArvNo* raiz){
    if(raiz != NULL){
       libera(raiz->sae);
       libera(raiz->sad);
       free(raiz);
    }
}


/*Efetua a operação de liberação sobre o tipo abstrato árvore binária.*/
void arv_libera(Arv* arv){
    libera(arv->raiz);
    free(arv);
}
