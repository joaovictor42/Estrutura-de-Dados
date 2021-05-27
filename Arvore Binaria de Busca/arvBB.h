#ifndef ARVBB_H_INCLUDED
#define ARVBB_H_INCLUDED


typedef struct arv_bb ArvBB;
typedef struct arv_no ArvNo;


/*Cria a representação do tipo abstrato árvore binária de busca.*/
ArvBB* abb_cria(void);

/*Efetua a operação de inserção sobre o tipo abstrato árvore binária de busca.*/
void abb_insere(ArvBB* abb, int valor);

/*Efetua a operação de busca sobre o tipo abstrato árvore binária de busca.*/
ArvNo* abb_busca(ArvBB* abb, int valor);

/*Efetua a operação de remoção sobre o tipo abstrato árvore binária de busca.*/
void abb_remove(ArvBB* abb, int valor);

/*Efetua a operação de impressão sobre o tipo abstrato árvore binária de busca.*/
void abb_imprime(ArvBB* abb);

/*Efetua a operação de liberação sobre o tipo abstrato árvore binária de busca.*/
void abb_libera(ArvBB* abb);

#endif // ARVBB_H_INCLUDED
