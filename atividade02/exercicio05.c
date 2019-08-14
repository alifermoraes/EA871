/*
 * No programa abaixo,
 * a) Faça uma hipótese sobre o que o programa faz.
 * b) Compile e execute o programa. Ele fez o que você imaginava?
 */

#include <stdio.h>

int main(void) {
    char string[] = {'a', 'b', 'c', 'd', 'e'};
    char *p1 = &(string[0]);
    char *p2 = string;

    for (int i = 0; i < 5; i++) {
        printf("*p1 = %c\t\t", *p1);
        p1++;

        printf("*p2 = %c\n", *p2);
        p2++;
    }

    return 0;
}