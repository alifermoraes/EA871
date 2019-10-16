/**
 * EA871 T
 * Atividade07 - Transmissão e Recepção Serial com Interrupções
 *
 * Alifer Willians de Moraes
 * RA: 165334
 *
 * O desafio proposto nesta atividade é desenvolver um programa que utilize o receptor da UART para
 * criar um sistema de acionamento de um LED RGB a partir de comandos fornecidos pelo teclado. Além
 * disso, também vamos utilizar o transmissor da UART para encaminhar mensagens de confirmação e
 * status.
 */

#include "usart.h"
#include "list.h"
#include "rgb.h"
#include <avr/interrupt.h>
#include <util/delay.h>

/* PORTB registers. */
#define DDR_B	(*((uint8_ptr) 0x24))
#define PORT_B	(*((uint8_ptr) 0x25))

uint8_t message[9][37] = {"Vazio!\n",
                          "Comando: Acender LED - cor vermelha\n",
                          "Comando: Acender LED - cor verde\n",
                          "Comando: Acender LED - cor amarela\n",
                          "Comando: Acender LED - cor azul\n",
                          "Comando: Acender LED - cor magenta\n",
                          "Comando: Acender LED - cor ciano\n",
                          "Comando: Acender LED - cor branca\n",
                          "Comando incorreto\n"};

List list = {NULL, NULL, 0};
uint8_t data, i = 1;

void startup(void);

int main(void) {

    startup();
    USART_Init(UBRR);

    while (TRUE) {
        if (list.size) { /* Se houver algum valor no buffer */
            /**
             * Remove o primeiro item do buffer circular e converte seu valor em sua respectiva
             * instrução.
             */
            data = rgb_decoder(list_eject(&list));
            PORT_B |= data;
            UDR0 = message[data][0];
        } else { /* Buffer vazio. */
            data = EMPTY;
            UDR0 = message[data][0];
        }

        UCSR0B |= 0x40; /* Habilita interrupção TX Complete. */
        _delay_ms(200);
        PORT_B &= 0xF8; /* Apaga o LED RGB. */
    }
}

ISR (USART_TX_vect) {
    UDR0 = message[data][i];
    i++;
	
    if (!message[data][i]) {
        UCSR0B &= 0xBF; /* Desabilita interrupção TX Complete. */
        i = 1;
    }
}

ISR (USART_RX_vect) {
    list_push(&list, UDR0); /* Adiciona o dado recebido via USART ao buffer circular. */
}

void startup(void) {
    DDR_B |= 0x07; /* Define PB0, PB1 e PB2 como saída. */
    PORT_B &= 0xF8; /* Inicia o LED RGB apagado. */

    sei(); /* Habilita interrupções. */
}
