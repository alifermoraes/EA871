/*
 * O programa abaixo corresponde ao código-fonte 09-vetores.c.
 * a) Encontre todas as palavras-chave que você não conhece.
 * b) Faça uma hipótese sobre o que o programa faz.
 * c) Compile e execute o programa. Ele faz o que você imaginava?
 */

#include <stdio.h>
#include <limits.h>

#define TAMANHO_VETOR 5

void imprimir_vetor(int vetor[], int N) {
    int i;

    for (i = 0; i < N; i++) {
        printf("%d\t", vetor[i]);
    }

    printf("\n");
}

void ler_vetor(int vetor[], int N) {
    int i;
    int j;

    for (i = 0; i < N; i++) {
        scanf("%d", &j);
        vetor[i] = j;
    }
}

int produto_interno(int vetor1[], int vetor2[], int N) {
    int p = 0;
    int i;

    for (i = 0; i < N; i++) {
        p += (vetor1[i] * vetor2[i]);
    }

    return p;
}

int main(void) {
    int vetor_base[] = {1, 2, 6, 3, 5};
    int meu_vetor[TAMANHO_VETOR];

    ler_vetor(meu_vetor, TAMANHO_VETOR);
    printf("Vetor lido! Imprimindo...\n");
    imprimir_vetor(meu_vetor, TAMANHO_VETOR);
    printf("Produto interno com vetor-base: %d\n", produto_interno(vetor_base, meu_vetor, TAMANHO_VETOR));

    return 0;
}