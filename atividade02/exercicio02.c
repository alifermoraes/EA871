/*
 * Leia o código-fonte abaixo, correspondente a outro trecho do programa 07-funcoes.c. Ele foi escrito em linguagem C.
 * a) Encontre todas as palavras-chave que você não conhece.
 * b) Faça uma hipótese sobre o que o programa faz.
 * c) Compile e execute o programa. Ele faz o que você imaginava?
 * d) O rótulo i definido dentro da função procedimentoEscopo() se refere à mesma variável i definida na função main()? Como é possível demonstrar isso?
 */

#include <stdio.h>

void procedimentoN(int N) {
    printf("Ola, mundo! Eu sou o procedimento %d!\n", N);
}

void procedimentoEscopo(int N) {
    int i;

    i = N + 1;
    printf("Sucessor de %d: %d\n", N, i);
}

int main(void) {
    int i;
    i = 3;

    procedimentoN(i);

    printf("----\n");
    printf("Escopo:\n");
    printf("i = %d (main)\n", i);

    procedimentoEscopo(i);
    printf("i = %d (main)\n", i);
    
    return 0;
}