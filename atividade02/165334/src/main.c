/* 
 * Teste de um buffer circular
 *
 * Este programa serve para implementar e testar uma implementacao de buffer
 * circular
 */

#include <stdio.h>

char buffer[5];
int indice = 0;

void adicionar_buffer(char c) {
    if (indice <= 4) {
        buffer[indice] = c;
        indice++;
    }
}

void remover_buffer(void) {
  int i;

    if (indice > 0) {
        for (i = 0; i < indice; i++) {
        buffer[i] = buffer[i + 1];
        }

        indice--;
    }
}

void imprimir_buffer(void) {
    int i;

    if (indice > 0) {
    for (i = 0; i < indice - 1; i++) {
        printf("%c ", buffer[i]);
    }

        printf("%c", buffer[i]);
    }

    printf("\n");
}

int main(void) {
    char c;

    do {
        scanf("%c", &c);

        if (c >= 48 && c <= 57) { /* Checa se c é um dígito entre 0 e 9 */
        adicionar_buffer(c);
        imprimir_buffer();
        } else if ((c >= 65 && c <= 90) || (c >= 97 && c <= 122)) { /* Checa se c é uma letra a-z ou A-Z */
        remover_buffer();
        imprimir_buffer();
        }

    } while (c != '\n');

    return 0;
}
