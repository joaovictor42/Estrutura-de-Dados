#ifndef ARVBIN_H_INCLUDED
#define ARVBIN_H_INCLUDED


//Nó da árvore binária.
typedef struct arv Arv;
//Tipo abstrato árvore binária.
typedef struct arv_no ArvNo;


/*Cria um novo nó, recebendo como parâmetro respectivamente,
seu valor, subárvore à esquerda e subárvore à direita.*/
ArvNo* arv_criaNo(int valor, ArvNo* sae, ArvNo* sad);

/*Cria a representação do tipo abstrato árvore binária, recebendo como parâmetro um nó.*/
Arv* arv_cria(ArvNo* raiz);

/*Efetua a operação de busca sobre o tipo abstrato árvore binária.*/
ArvNo* arv_busca(Arv* arv, int valor);

/*Efetua a operação de impressão sobre o tipo abstrato árvore binária.*/
void arv_imprime(Arv* arv);

/*Efetua a operação de liberação sobre o tipo abstrato árvore binária.*/
void arv_libera(Arv* arv);

#endif // ARVBIN_H_INCLUDED
