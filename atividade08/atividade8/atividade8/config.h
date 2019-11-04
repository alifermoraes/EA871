/**
 * EA871 T
 * Atividade08 - Temporizadores
 *
 * Alifer Willians de Moraes
 * RA: 165334
 *
 * Definições para configurações de USART e TIMER2.
 */ 

#ifndef CONFIG_H
#define CONFIG_H

#include <stdint.h>

/* Endereços de memória para configuração da USART. */
#define UDR0    (*((uint8_ptr) 0xC6))
#define UBRR0H  (*((uint8_ptr) 0xC5))
#define UBRR0L  (*((uint8_ptr) 0xC4))
#define UCSR0C  (*((uint8_ptr) 0xC2))
#define UCSR0B  (*((uint8_ptr) 0xC1))
#define UCSR0A  (*((uint8_ptr) 0xC0))

/* Endereços de memória para configuração do TIMER2. */
#define TCCR2A  (*((uint8_ptr) 0xB0))
#define TCCR2B  (*((uint8_ptr) 0xB1))
#define OCR2A   (*((uint8_ptr) 0xB3))
#define TIMSK2  (*((uint8_ptr) 0x70))

#define DDR_B   (*((uint8_ptr) 0x24))
#define TRUE 1

typedef uint8_t* uint8_ptr;

void config_usart(void);
void config_timer(void);

#endif /* CONFIG_H */