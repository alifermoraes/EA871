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

#endif /* LIST_H */
