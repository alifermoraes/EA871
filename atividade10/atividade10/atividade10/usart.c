/**
 * EA871 T
 * Atividade10 - Síntese de formas de onda via PWM
 *
 * Alifer Willians de Moraes
 * RA: 165334
 */

#include "usart.h"

void USART_config(uint16_t ubrr) {
   /* Configura o BAUD Rate. */
   UBRR0H = (uint8_t) ((ubrr >> 8) & 0xF);
   UBRR0L = (uint8_t) (ubrr & 0xFF);
   /* Configura o BAUD Rate. */
   UBRR0H = (uint8_t) ((ubrr >> 8) & 0xF);
   UBRR0L = (uint8_t) (ubrr & 0xFF);

   /* Desabilita os modos de transmissão double speed e multi processador. */
   UCSR0A &= 0xDC;
   
   /**
    * Habilita interrupção Receive Complete.
    * Habilita Tx e Rx.
    */
   UCSR0B |= 0x80;
   UCSR0B |= 0x18;

   /**
    * Modo assíncrono.
    * Desabilita bit de paridade
    * 2 stop bits
    */
   UCSR0C &= 0x3E;
   UCSR0C &= 0xCF;
   UCSR0C |= 0x08;

   /* Frame com 8 bits de dados */
   UCSR0B &= 0xFB;
   UCSR0C |= 0x06;
}