#ifndef ARVAVL_H_INCLUDED
#define ARVAVL_H_INCLUDED

//Nó da árvore avl.
typedef struct arv_avl ArvAVL;
//Tipo abstrato árvore avl.
typedef struct arv_no ArvNo;


/*Cria a representação do tipo abstrato árvore avl.*/
ArvAVL* avl_cria(void);

/*Efetua a operação de inserção sobre o tipo abstrato árvore avl.*/
void avl_insere(ArvAVL* avl, int valor);

/*Efetua a operação de busca sobre o tipo abstrato árvore avl.*/
ArvNo* avl_busca(ArvAVL* avl, int valor);

/*Efetua a operação de remoção sobre o tipo abstrato árvore avl.*/
void avl_remove(ArvAVL* avl, int valor);

/*Efetua a operação de impressão sobre o tipo abstrato árvore avl.*/
void avl_imprime(ArvAVL* avl);

/*Efetua a operação de liberação sobre o tipo abstrato árvore avl.*/
void avl_libera(ArvAVL* avl);

#endif // ARVAVL_H_INCLUDED
