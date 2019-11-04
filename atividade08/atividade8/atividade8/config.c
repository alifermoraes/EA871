/**
 * EA871 T
 * Atividade08 - Temporizadores
 *
 * Alifer Willians de Moraes
 * RA: 165334
 *
 * Funções para configurações de USART e TIMER2.
 */ 

#include "config.h"

void config_usart(void) {
    /* Configura o BAUD Rate = 38400. */
    UBRR0H = 0;
    UBRR0L = 25;

    UCSR0A &= 0xDC; /* Desabilita os modos de transmissão double speed e multi processador. */

    /** 
     * Desabilita interrupções USART.
     * Habilita Tx.
     */
    UCSR0B &= 0x1F;
    UCSR0B |= 0x08;   

    /**
     * Modo assíncrono.
     * Habilita bit de paridade - Paridade ímpar.
     * 1 stop bit.
     */
    UCSR0C &= 0x3E;
    UCSR0C |= 0x30;
    UCSR0C &= 0xF7;

    /* Frame com 8 bits de dados. */
    UCSR0B &= 0xFB;
    UCSR0C |= 0x06;
}

void config_timer(void) {
    TCCR2A &= 0xFC; /* Habilita operação normal do TIMER2 */
    TCCR2A |= 0x80; /* Clear Timer on Compare Match */
    TIMSK2 |= 0x02; /* Timer/Counter0 Output Compare Match A Interrupt Enable. */
    TCCR2B |= 0x04;	/* Prescaler = 64. */
    OCR2A = 250; /* Prescaler setado em 64 -> clock = 250KHz -> 1 ms = 250 ciclos (OCR0A = 250) */
}
