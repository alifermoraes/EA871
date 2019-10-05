/**
 * EA871 T
 * Atividade05 - Interrupções
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
   UCSR0A &= 0xFC;
   
   /* Desabilita interrupções. */
   UCSR0B &= 0x1F;
   
   /* Habilita Tx. */
   UCSR0B |= 0x08;

   /* Modo assíncrono. */
   UCSR0C &= 0x3E;

   /* Habilita bit de paridade - Paridade ímpar. */
   UCSR0C |= 0x30;

   /* 1 stop bit */
   UCSR0C &= 0xF7;

   /* Frame com 8 bits de dados */
   UCSR0B &= 0xFB;
   UCSR0C |= 0x06;
}

void USART_Transmit(uint8_t data) {
   /* Espera o buffer ficar vazio. */
   while (!(UCSR0A & 0x20));

   /* Carrega o dado no buffer e envia-o. */
   UDR0 = data;
}
