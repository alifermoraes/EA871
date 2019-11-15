/**
 * EA871 T
 * Atividade09 - Modulação por largura de pulso (PWM)
 *
 * Alifer Willians de Moraes
 * RA: 165334
 *
 * Funções para configurações do TIMER2.
 */

#include "timer2.h"

void timer2_config(void) {
    /* Habilita operação fast PWM do TIMER2 com TOP em OCR2A. */
    TCCR2A |= 0x03;
    TCCR2B |= 0x08;

    TCCR2A |= 0xA0; /* Clear OC2B on Compare Match. */
    TIMSK2 |= 0x01; /* Timer/Counter2 Overflow Interrupt Enable. */
    TCCR2B |= 0x06;	/* Prescaler = 256. */

    /* Prescaler setado em 256 -> clock = 62.500 Hz -> 250 cycles = 4 ms. */

    OCR2A = 250; 
    OCR2B = 0;
}
