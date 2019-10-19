/**
 * EA871 T
 * Atividade06 - Interface Serial e UART
 *
 * Alifer Willians de Moraes
 * RA: 165334
 *
 * Funções de configuração da UART e transmissão de dados.
 */

#include "usart.h"

void USART_Init(uint16_t ubrr) {
   /* Configura o BAUD Rate. */
   UBRR0H = (uint8_t) ((ubrr >> 8) & 0xF);
   UBRR0L = (uint8_t) (ubrr & 0xFF);

   /* Desabilita os modos de transmissão double speed e multi processador. */
   UCSR0A &= 0xDC;
   
   /**
    * Desabilita interrupções da USART.
    * Habilita Tx.
    */
   UCSR0B &= 0x1F;
   UCSR0B |= 0x08;

   /**
    * Modo assíncrono.
    * Habilita bit de paridade. Ímpar.
    * 1 stop bit.
    */
   UCSR0C &= 0x3E;
   UCSR0C |= 0x30;
   UCSR0C &= 0xF7;

   /* Frame com 8 bits de dados. */
   UCSR0B &= 0xFB;
   UCSR0C |= 0x06;
}

void USART_Transmit(uint8_t data) {
   /* Espera o buffer ficar vazio. */
   while (!(UCSR0A & 0x20));

   /* Carrega o dado no buffer e envia-o. */
   UDR0 = data;
}
