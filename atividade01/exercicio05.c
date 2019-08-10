#include <stdio.h>

int main() {
    int i;
    int f;

    printf("Loops\n");
    printf("1) Contando de 1 a 15\n");

    i = 0;
    
    do {
        i++;
        printf("%d\t", i);
    } while (i < 15);

    printf("\n\n");
    printf("2) Calculando fatorial de 5\n");

    i = 5;
    f = 1;

    while (i > 0) {
        f *= i;
        i--;
    }

    printf("O fatorial de 5 eh %d\n\n", f);
    printf("3) Imprimindo um tabuleiro de xadrez\n");
    printf("1 = casa branca, 0 = casa preta\n");

    for (i = 0; i < 8; i++) {
        for (f = 0; f < 8; f++) {
            printf("%d\t", ((i + f + 1) % 2)); /* Exercicio: explique porque (i + f + 1 ) % 2 */
        }

        printf("\n\n");
    }

    printf("4) Imprimindo uma piramide com 10 andares\n");

    for (i = 0; i < 10; i++) { /* Para cada andar */
        for (f = 0; f <= i; f++) { /* Exercicio: porque precisamos de f<=i e não f<i ? */
            printf("* ");
        }

        printf("\n");
    }

    printf("---\n");
    return 0;
}