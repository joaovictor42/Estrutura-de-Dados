#include "arvBB.c"


int main(){
    ArvBB* arv = abb_cria();

    int valores[] = {9, 5, 10, 0, 6, 11, -1, 1, 1, 2};
    for(int i = 0; i < 9; i++){
        abb_insere(arv, valores[i]);
    }

    /* Árvore construída
            9
           / \
          5   10
         / \    \
        0   6    11
       / \
     -1   1
           \
            2
    */

    printf("Arvore completa\n");
    printf("Ordem crescente: ");
    abb_imprime(arv);

    abb_remove(arv, -1);
    abb_remove(arv, 10);
    abb_remove(arv, 9);

    /* Árvore após remoções
            6
           / \
          5   11
         /
        0
         \
          1
           \
            2
    */

    printf("\n\nArvore após a remocao do valores -1, 10 e 9\n");
    printf("Ordem crescente: ");
    abb_imprime(arv);

    printf("\n\nOperações de busca:");
    for(int i = 0; i < 15; i++){
        if(abb_busca(arv, i))
            printf("\n%d Encontrado!", i);
        else
            printf("\n%d Não Encontrado!", i);
    }

    abb_libera(arv);

    return 0;
}
