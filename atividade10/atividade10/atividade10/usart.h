/**
 * EA871 T
 * Atividade10 - Síntese de formas de onda via PWM
 *
 * Alifer Willians de Moraes
 * RA: 165334
 *
 * Description
 */

#ifndef USART_H
#define USART_H

#include <stdint.h>

#define F_CPU   16000000UL
#define FOSC    F_CPU
#define BAUD    9600U
#define UBRR    (FOSC/BAUD/16 - 1)

/* USART registers. */
#define UDR0    (*((uint8_ptr) 0xC6))
#define UBRR0H  (*((uint8_ptr) 0xC5))
#define UBRR0L  (*((uint8_ptr) 0xC4))
#define UCSR0C  (*((uint8_ptr) 0xC2))
#define UCSR0B  (*((uint8_ptr) 0xC1))
#define UCSR0A  (*((v_uint8_ptr) 0xC0))

typedef volatile uint8_t* v_uint8_ptr;
typedef uint8_t* uint8_ptr;

void USART_config(uint16_t ubrr);

#endif /* USART_H */