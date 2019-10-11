/**
 * EA871 T
 * Atividade07 - Transmissão e Recepção Serial com Interrupções
 *
 * Alifer Willians de Moraes
 * RA: 165334
 *
 * Definições de funções de lista circular.
 */ 


#ifndef LIST_H
#define LIST_H

#include <stdint.h>

#define MAX_SIZE    10

typedef struct {
    uint8_t V[MAX_SIZE];
    uint8_t head;
    uint8_t size;
} List;

List list_create(void) {
    List list;

    list.head = 0;
    list.size = 0;

    return list;
}

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

#endif /* LIST_H */