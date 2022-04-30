#include <stdio.h>
#include <stdlib.h>
#include "arvAVL.h"


//Nó da árvore avl.
struct arv_no{
    int info;
    int altura;
    ArvNo* sae;//Subárvore à esquerda
    ArvNo* sad;//Subárvore à direita
};


//Tipo abstrato árvore avl.
struct arv_avl{
    ArvNo* raiz;
};


/*Cria um novo nó.*/
ArvNo* novoNo(int valor){
    ArvNo* no  = (ArvNo*) malloc(sizeof(ArvNo));
    no->altura = 0;
    no->info   = valor;
    no->sae    = NULL;
    no->sad    = NULL;
    return no;
}


/*Cria a representação do tipo abstrato árvore avl.*/
ArvAVL* avl_cria(void){
    ArvAVL* avl = (ArvAVL*) malloc(sizeof(ArvAVL));
    avl->raiz = NULL;
    return avl;
}


/*Retorna a altura de uma subárvore.*/
int altura(ArvNo* raiz){
    if(raiz == NULL)
        return -1;
    return raiz->altura;
}


/*Retorna o maior entre os dois valores passados como parâmetro.*/
int maior(int a, int b){
    return (a > b)? a : b;
}


/*Retorna a diferença entre as alturas da sae e sad de um nó.*/
int fatorDeBalanceamento(ArvNo* raiz){
    return altura(raiz->sae) - altura(raiz->sad);
}


/*Efetua a operação de rotação à direita.*/
ArvNo* rotacaoDir(ArvNo *raiz){
    //A nova raiz passa a ser o filho esquerdo da raiz original.
    ArvNo* novaRaiz = raiz->sae;
    //O filho esquerdo da raiz original passa a ser o filho direito da nova raiz.
    raiz->sae = novaRaiz->sad;
    //O filho direito da nova raiz passa a ser a raiz original
    novaRaiz->sad = raiz;

    //Atualiza as alturas
    raiz->altura = 1 + maior(altura(raiz->sae), altura(raiz->sad));
    novaRaiz->altura = 1 + maior(altura(novaRaiz->sae), altura(novaRaiz->sad));

    return novaRaiz;
}


/*Efetua a operação de rotação à esquerda.*/
ArvNo* rotacaoEsq(ArvNo* raiz){
    //A nova raiz passa a ser o filho direito da raiz original.
    ArvNo* novaRaiz = raiz->sad;
    //O filho direito da raiz original passa a ser o filho esquerdo da nova raiz.
    raiz->sad = novaRaiz->sae;
    //O filho esquerdo da nova raiz passa a ser a raiz original
    novaRaiz->sae = raiz;

    //Atualiza as alturas
    raiz->altura = 1 + maior(altura(raiz->sae), altura(raiz->sad));
    novaRaiz->altura = 1 + maior(altura(novaRaiz->sae), altura(novaRaiz->sad));

    return novaRaiz;
}


/*Efetua a operação de inserção na árvore avl a partir da raiz.*/
ArvNo* insereNo(ArvNo* raiz, int valor){
    //1.  Operação de inserção padrão da árvore binária de busca
    if (raiz == NULL)
        return novoNo(valor);

    if(valor < raiz->info)
        raiz->sae = insereNo(raiz->sae, valor);
    else if(valor > raiz->info)
        raiz->sad = insereNo(raiz->sad, valor);
    else//Trata chaves iguais
        return raiz;

    //2. Atualiza a altura do nó atual
    raiz->altura = 1 + maior(altura(raiz->sae), altura(raiz->sad));

    //3. Verifica o fator de balanceamento desse nó
    int fBalanceamento = fatorDeBalanceamento(raiz);

    //Se o nó se tornar desbalanceado, então uma operação de rotação deverá ser aplicada

    //Verifica os casos de rotação simples e dupla à direita
    if (fBalanceamento > 1){
        if(valor > raiz->sae->info)//Caso de rotação dupla
            raiz->sae = rotacaoEsq(raiz->sae);
        return rotacaoDir(raiz);
    }

    //Verifica os casos de rotação simples e dupla à esquerda
    if (fBalanceamento < -1){
        if(valor < raiz->sad->info)//Caso de rotação dupla
            raiz->sad = rotacaoDir(raiz->sad);
        return rotacaoEsq(raiz);
    }
    return raiz;
}


/*Efetua a operação de inserção sobre o tipo abstrato árvore avl.*/
void avl_insere(ArvAVL* avl, int valor){
        avl->raiz = insereNo(avl->raiz, valor);
}


/*Efetua a operação de busca na árvore avl a partir da raiz.*/
ArvNo* busca(ArvNo* raiz, int valor){
    if(raiz == NULL || raiz->info == valor)//Verifica se o nó é nulo ou armazena o valor buscado
        return raiz;
    else if(valor < raiz->info)
        return busca(raiz->sae, valor);
    else
        return busca(raiz->sad, valor);
}


/*Efetua a operação de busca sobre o tipo abstrato árvore avl.*/
ArvNo* avl_busca(ArvAVL* avl, int valor){
    return busca(avl->raiz, valor);
}


/*Efetua a operação de remoção na árvore avl a partir da raiz.*/
ArvNo* removeNo(ArvNo* raiz, int valor){
    //1.  Operação de remoção padrão da árvore binária de busca
    if(raiz == NULL)
        return NULL;
    else if(valor < raiz->info)//Remove na sae
        raiz->sae = removeNo(raiz->sae, valor);
    else if(valor > raiz-> info)//Remove na sad
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

    //2. Atualiza a altura do nó atual
    raiz->altura = 1 + maior(altura(raiz->sae), altura(raiz->sad));

    //3. Verifica o fator de balanceamento desse nó
    int fBalanceamento = fatorDeBalanceamento(raiz);

    //Verifica os casos de rotação simples e dupla à direita
    if(fBalanceamento > 1){
        if(fatorDeBalanceamento(raiz->sae) < 0)//Caso de rotação dupla
            raiz->sae = rotacaoEsq(raiz->sae);
        return rotacaoDir(raiz);
    }

    //Verifica os casos de rotação simples e dupla à esquerda
    if(fBalanceamento < -1){
        if(fatorDeBalanceamento(raiz->sad) > 0)//Caso de rotação dupla
            raiz->sad = rotacaoDir(raiz->sad);
        return rotacaoEsq(raiz);
    }
    return raiz;
}


/*Efetua a operação de remoção sobre o tipo abstrato árvore avl.*/
void avl_remove(ArvAVL* avl, int valor){
    avl->raiz = removeNo(avl->raiz, valor);
}


/*Imprime a árvore em ordem simétrica a partir da raiz.*/
void imprime(ArvNo* raiz){
    if(raiz != NULL){
        imprime(raiz->sae);
        printf("%d ", raiz->info);
        imprime(raiz->sad);
    }
}


/*Efetua a operação de impressão sobre o tipo abstrato árvore avl.*/
void avl_imprime(ArvAVL* avl){
    imprime(avl->raiz);
}


/*Libera, recursivamente, cada nó da árvore a partir da raiz.*/
void libera(ArvNo* raiz){
    if(raiz != NULL){
       libera(raiz->sae);
       libera(raiz->sad);
       free(raiz);
    }
}


/*Efetua a operação de liberação sobre o tipo abstrato árvore avl.*/
void avl_libera(ArvAVL* avl){
    libera(avl->raiz);
    free(avl);
}
