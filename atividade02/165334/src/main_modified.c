/* 
 * Teste de um buffer circular
 *
 * Este programa serve para implementar e testar uma implementacao de buffer
 * circular
 */

#include <stdio.h>

/* Estrutura de dados para armazenar o vetor buffer[] e seu índice */
typedef struct {
    char buffer[5];
    int indice;
} Buffer;

/* Define um nome alternativo para a declaração de um ponteiro para a struct Buffer */
typedef Buffer * ptr_buffer;

void adicionar_buffer(ptr_buffer buffer, char c) {
    int indice = buffer->indice;

    if (indice < 5) {
        buffer->buffer[indice] = c;
        buffer->indice++;
    }
}

void remover_buffer(ptr_buffer buffer) {
  int i;
  int indice = buffer->indice;

    if (indice > 0) {
        for (i = 0; i < indice; i++) {
        buffer->buffer[i] = buffer->buffer[i + 1];
        }

        buffer->indice--;
    }
}

void imprimir_buffer(ptr_buffer buffer) {
    int i;
    int indice = buffer->indice;

    if (indice > 0) {
    for (i = 0; i < indice - 1; i++) {
        printf("%c ", buffer->buffer[i]);
    }

        printf("%c", buffer->buffer[i]);
    }

    printf("\n");
}

int main(void) {
    char c;
    Buffer buffer = {0, };
    ptr_buffer ptr_buffer;


    ptr_buffer = &buffer;

    do {
        scanf("%c", &c);

        if (c >= 48 && c <= 57) { /* Checa se c é um dígito entre 0 e 9 */
        adicionar_buffer(ptr_buffer, c);
        imprimir_buffer(ptr_buffer);
        } else if ((c >= 65 && c <= 90) || (c >= 97 && c <= 122)) { /* Checa se c é uma letra a-z ou A-Z */
        remover_buffer(ptr_buffer);
        imprimir_buffer(ptr_buffer);
        }
    } while (c != '\n');

    return 0;
}
