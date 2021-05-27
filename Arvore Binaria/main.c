#include "arvBin.c"


int main(){
    Arv* arv = arv_cria(arv_criaNo('a', arv_criaNo('b', NULL , arv_criaNo('d', NULL , NULL)),
             arv_criaNo('c', arv_criaNo('e', NULL , NULL), arv_criaNo('f', NULL , NULL))));

    /* Árvore construída
            a
          /   \
         b     c
          \   / \
           d e   f
    */

    printf("Arvore completa em ordem simetrica\n");
    arv_imprime(arv);

    printf("\n\nResultado de sucessivas buscas com as letras do alfabeto\n");
    for(int i = 97; i <= 127; i++){
        ArvNo* no = arv_busca(arv, i);
        if(no != NULL)
            printf("%c ", no->info);
    }

    arv_libera(arv);

    return 0;
}
