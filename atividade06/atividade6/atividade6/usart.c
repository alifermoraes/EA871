/**
 * EA871 T
 * Atividade05 - Interrupções
 *
 * Alifer Willians de Moraes
 * RA: 165334
 *
 * O desafio proposto nesta atividade é desenvolver um programa que utilize a USART, configurada de
 * acordo com as especificações do exercício 2 feito em sala de aula, para transmitir
 * indefinidamente uma sequência de caracteres pré-definida ao computador.
 * Cada aluno pode utilizar a sua própria cadeia de caracteres para testar seu programa, mas
 * deixamos aqui uma sugestão inspiradora:
 * char msg[] = " Out of the night that covers me,\n
 *                Black as the Pit from pole to pole,\n
 *                I thank whatever gods may be\n
 *                For my unconquerable soul.\n\n
 *
 *                In the fell clutch of circumstance\n
 *                I have not winced nor cried aloud.\n
 *                Under the bludgeonings of chance\n
 *                My head is bloody, but unbowed.\n\n
 * 
 *                Beyond this place of wrath and tears\n
 *                Looms but the Horror of the shade,\n
 *                And yet the menace of the years\n
 *                Finds, and shall find, me unafraid.\n\n
 * 
 *                It matters not how strait the gate,\n
 *                How charged with punishments the scroll.\n
 *                I am the master of my fate:\n
 *                I am the captain of my soul.\n";
 *
 * Cada vez que a sequência inteira de caracteres for transmitida, o programa deve enviar logo em
 * seguida uma mensagem de confirmação: " Mensagem transmitida com sucesso! ". Após isso, antes de
 * reiniciar as transmissões, deve ser introduzido um atraso de 5 segundos. Para melhorar a
 * visualização, entre as transmissões do texto e da confirmação (e da confirmação e do próximo
 * texto), envie um \n.
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

   /* Desabilita modo de paridade */
   UCSR0C &= 0xCF;

   /* 1 stop bit */
   UCSR0C &= 0xF7;

   /* Frame com 8 bits de dados */
   UCSR0B &= 0xFB;
   UCSR0C |= 0x06;
}

void USART_Transmit(uint8_t data) {
   /* Espera o buffer ficar vazio. */
   while (!(UCSR0A & 0x20));

   /* Carregad o dado no buffer e envia-o. */
   UDR0 = data;
}
