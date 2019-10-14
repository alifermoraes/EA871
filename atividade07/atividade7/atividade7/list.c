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
    uint8_t pos;

    if (list->size < MAX_SIZE) {
        pos = (list->head + list->size) % MAX_SIZE;
        list->V[pos] = data;
        list->size++;
    }
}

uint8_t list_eject(List *list) {
    uint8_t data = 0xFF;

    if (list->size) {
        data = list->V[list->head];
        list->head = (list->head + 1) % MAX_SIZE;
        list->size--;
    }

    return data;
}
