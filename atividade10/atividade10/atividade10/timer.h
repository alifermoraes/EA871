/**
 * EA871 T
 * Atividade10 - Síntese de formas de onda via PWM
 *
 * Alifer Willians de Moraes
 * RA: 165334
 */

#ifndef TIMER_H
#define TIMER_H

#include <stdint.h>

/* Endereços de memória para configuração do TIMER2. */
#define TCCR2A  (*((uint8_ptr) 0xB0))
#define TCCR2B  (*((uint8_ptr) 0xB1))
#define OCR2A   (*((uint8_ptr) 0xB3))
#define OCR2B   (*((uint8_ptr) 0xB4))
#define TIMSK2  (*((uint8_ptr) 0x70))

typedef uint8_t* uint8_ptr;

void TIMER_config(void);

#endif /* TIMER_H */