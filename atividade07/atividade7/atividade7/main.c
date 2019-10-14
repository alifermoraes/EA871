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

uint8_t empty[] = "Vazio!\n";
uint8_t command[8][40] = {"Comando incorreto\n",
	"Comando: Acender LED - cor vermelha\n",
	"Comando: Acender LED - cor verde\n",
	"Comando: Acender LED - cor amarela\n",
	"Comando: Acender LED - cor azul\n",
	"Comando: Acender LED - cor magenta\n",
	"Comando: Acender LED - cor ciano\n",
"Comando: Acender LED - cor branca\n"};

List list = {{},0,0};
volatile uint8_t i = 0;
uint8_t cmd, data;

void startup(void);

int main(void) {

    startup();
    USART_Init(UBRR);

    while (TRUE) {
        if (list.size) {
            data = list_eject(&list);
            data = rgb_decoder(data);
            PORT_B &= 0xF8;
            PORT_B |= data;

            while (command[data][i]) {
            }
        } else {
            while (empty[i]) {
            }
        }

        i = 0;
    }
}

ISR (USART_TX_vect) {
    UDR0 = command[data][i];
    i++;
}

ISR (USART_RX_vect) {
    cmd = UDR0;
    list_push(&list, cmd);
}

void startup(void) {
    /* Define PB0, PB1 e PB2 como saída. */
    DDR_B |= 0x07;
    PORT_B &= 0xF8;

    /* Habilita interrupções. */
    sei();
}
