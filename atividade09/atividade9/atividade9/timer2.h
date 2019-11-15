/**
 * EA871 T
 * Atividade09 - Modulação por largura de pulso (PWM)
 *
 * Alifer Willians de Moraes
 * RA: 165334
 *
 * Definições para configurações do TIMER2.
 */ 

#ifndef TIMER2_H
#define TIMER2_H

#include <stdint.h>

/* Endereços de memória para configuração do TIMER2. */
#define TCCR2A  (*((uint8_ptr) 0xB0))
#define TCCR2B  (*((uint8_ptr) 0xB1))
#define OCR2A   (*((uint8_ptr) 0xB3))
#define OCR2B   (*((uint8_ptr) 0xB4))
#define TIMSK2  (*((uint8_ptr) 0x70))

#define DDR_D   (*((uint8_ptr) 0x2A))
#define TRUE 1

typedef uint8_t* uint8_ptr;

void timer2_config(void);

#endif /* TIMER2_H */
