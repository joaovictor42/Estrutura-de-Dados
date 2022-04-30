#include "arvAVL.c"


int main(){
    ArvAVL* arv = avl_cria();

    int valores[] = {9, 5, 10, 0, 6, 11, -1, 1, 1, 2};
    for(int i = 0; i < 9; i++){
        avl_insere(arv, valores[i]);
    }

    /* Arvore construida
            9
           /  \
          1    10
        /  \     \
       0    5     11
      /    /  \
     -1   2    6
    */

    printf("Arvore completa\n");
    printf("Ordem crescente: ");
    avl_imprime(arv);

    avl_remove(arv, -1);
    avl_remove(arv, 10);
    avl_remove(arv, 9);

    /* Árvore após remoções
          5
        /   \
       1     9
      / \   / \
     0   2 6  11

    */

    printf("\n\nArvore após a remocao do valores -1, 10 e 9\n");
    printf("Ordem crescente: ");
    avl_imprime(arv);

    printf("\n\nOperações de busca:");
    for(int i = 0; i < 15; i++){
        if(avl_busca(arv, i))
            printf("\n%d Encontrado!", i);
        else
            printf("\n%d Não Encontrado!", i);
    }

    avl_libera(arv);

    return 0;
}
