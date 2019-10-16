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
#include <stdlib.h>

#define MAX_SIZE    10

typedef struct node {
    uint8_t data;
    struct node *next;	
} Node;

typedef struct {
    Node *head;
    Node *tail;
    uint8_t size;
} List;

void list_push(List *list, uint8_t data);
uint8_t list_eject(List *list);

#endif /* LIST_H */
