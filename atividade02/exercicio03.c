/*
 * O programa abaixo contém uma função que recebe ponteiros como parâmetros. Ele foi extraído de 07-
 * funcoes.c.
 * a) Encontre todas as palavras-chave que você não conhece.
 * b) Faça uma hipótese sobre o que o programa faz.
 * c) Compile e execute o programa. Ele faz o que você imaginava?
 */

#include <stdio.h>

void procedimento_ref(int *N, int M) {
    (*N) = (*N) + 1;
    M = M + 1;
}

int main(void) {
    int i, j;

    i = 0;
    j = 0;

    procedimento_ref(&i, j);
    printf("i = %d, j = %d\n", i, j);

    return 0;
}