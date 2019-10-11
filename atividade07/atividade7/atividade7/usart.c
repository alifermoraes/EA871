/**
 * EA871 T
 * Atividade07 - Transmissão e Recepção Serial com Interrupções
 *
 * Alifer Willians de Moraes
 * RA: 165334
 *
 * Funções de configuração da USART e transmissão de dados.
 */

#include "usart.h"

void USART_Init(uint16_t ubrr) {
   /* Configura o BAUD Rate. */
   UBRR0H = (uint8_t) ((ubrr >> 8) & 0xF);
   UBRR0L = (uint8_t) (ubrr & 0xFF);

       
}
