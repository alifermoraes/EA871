/**
 * EA871 T
 * Atividade05 - Interrupções
 *
 * Alifer Willians de Moraes
 * RA: 165334
 *
 * Definições de ponteiros e funções para utilizar comunicação usart do atmega328p
 */ 

#ifndef USART_H
#define USART_H

#include <stdint.h>

#define F_CPU 16000000UL
#define FOSC F_CPU
#define BAUD 9600
#define MYUBRR ((FOSC/(16 * BAUD)) - 1)

#define UDR0 (*((v_uint8_ptr) 0xC6))
#define UBRR0H (*((v_uint8_ptr) 0xC5))
#define UBRR0L (*((v_uint8_ptr) 0xC4))
#define UCSR0C (*((v_uint8_ptr) 0xC2))
#define UCSR0B (*((v_uint8_ptr) 0xC1))
#define UCSR0A (*((v_uint8_ptr) 0xC0))

#define TRUE 1

typedef volatile uint8_t* v_uint8_ptr;
typedef uint8_t* uint8_ptr;

char message[] = "Some message";
char success[] = "Mensagem transmitida com sucesso!\n";

void USART_Init(uint16_t ubrr);
void USART_Transmit(uint8_t data);

#endif /* USART_H */