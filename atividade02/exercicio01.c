/*
 * Leia o código-fonte abaixo, correspondente a um trecho do programa 07-funcoes.c. Ele foi escrito * em linguagem C.
 * a) Encontre todas as palavras-chave que você não conhece.
 * b) Faça uma hipótese sobre o que o programa faz.
 * c) Compile e execute o programa. Ele faz o que você imaginava?
 * d) O que significa void()?
 * e) Como a função procedimentoN() “sabe” que deve imprimir o valor 3 na tela?
 * f) Modifique o programa para que a função procedimentoN() imprima o valor 95, ao invés de 3.
 */

#include <stdio.h>

void procedimento(void) {
    printf("Ola, mundo! Eu sou um procedimento!\n");
}

void procedimentoN(int N) {
    printf("Ola, mundo! Eu sou o procedimento %d!\n", N);
}

int main(void) {
    int i, j;

    printf("Procedimentos:\n");
    procedimento();
    procedimentoN(2);

    // i = 3;
    i = 95;

    procedimentoN(i);

    return 0;
}