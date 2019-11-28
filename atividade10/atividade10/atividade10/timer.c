/**
 * EA871 T
 * Atividade10 - Síntese de formas de onda via PWM
 *
 * Alifer Willians de Moraes
 * RA: 165334
 *
 * Description
 */

#include "timer.h"

void TIMER_config(void) {

    TCCR2A |= 0x03; /* Habilita operação fast PWM do TIMER2 com TOP em 0xFF. */
    TCCR2A |= 0x80; /* Clear OC2A on Compare Match. */
    TCCR2B |= 0x01;	/* Prescaler = 1. */
    TIMSK2 |= 0x05; /* Timer/Counter2 Compare Match B && Overflow Interrupts Enable. */

    OCR2A = 0;
    OCR2B = 160;
}