/**
 * EA871 T
 * Atividade07 - Transmissão e Recepção Serial com Interrupções
 *
 * Alifer Willians de Moraes
 * RA: 165334
 *
 * Funções para manipular uma lista circular (buffer).
 */

#include "list.h"

void list_push(List *list, uint8_t data) {
    Node *new;

    new = malloc(sizeof(Node));
    if (!new) return;

    new->data = data;
    new->next = NULL;

    if (!list->size) {
        list->head = new;
    } else {
        list->tail->next = new;
    }

    list->tail = new;
    list->size++;
}

uint8_t list_eject(List *list) {
    Node *tmp;
    uint8_t data = 0;

    if (list->size) {
        tmp = list->head;
        data = tmp->data;
        list->head = tmp->next;
        list->size--;

        free(tmp);
    }

    return data;
}
