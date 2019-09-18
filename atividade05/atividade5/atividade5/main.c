/*
 * atividade5.c
 *
 * Created: 13/09/2019 11:25:11
 * Author : Alifer
 */ 

#include "RGB.h"
#include <avr/interrupt.h>

/* Ponteiros para enderecos de memoria dos ports */
uint8_ptr portb = (uint8_ptr) 0x25,
          ddrb = (uint8_ptr) 0x24,
          ddrc = (uint8_ptr) 0x27,
          ddrd = (uint8_ptr) 0x2A;

uint8_v_ptr pinc = (uint8_v_ptr) 0x26,
            pind = (uint8_v_ptr) 0x29;

/* Ponteiros para enderecos de memoria para as interrupcoes */
uint8_ptr eicra = (uint8_ptr) 0x69,
          eimsk = (uint8_ptr) 0x3D,
          pcicr = (uint8_ptr) 0x68,
          pcimsk1 = (uint8_ptr) 0x6C;

volatile unsigned int msec_delay = 1000;
volatile uint8_t counter = 0;
volatile int8_t direction = 1;


void startup(void);
extern void DELAY(volatile unsigned int msec);

int main(void) {
    startup();

    while (TRUE) {
        *portb = colors[counter % 8];
        counter += direction;
        DELAY(msec_delay);
    }
}

ISR(INT0_vect) {
    /* Handles interrupt (speed) */
    if (msec_delay <= 125) {
        msec_delay = 1000;
    } else {
        msec_delay /= 2;
    }
}

ISR(PCINT1_vect){
    /* Handles interrupt (direction) */
    if (*pinc & 0x01) {
        direction *= -1;
    }
}

void startup(void) {
    /* Definicoes de ports como entrada ou saida */
    *ddrb |= 0x07;
    *ddrc &= 0xFE;
    *ddrd &= 0xFB;

    *portb &= 0xF8; /* Inicia com o LED RGB apagado */

    /* Configuracoes de interrupcoes */
    *eimsk |= 0x01; /* Habilita interrupcao por INT0 */
    *eicra |= 0x03; /* Borda de subida de INT0 gera interrupcao */
    *pcicr |= 0x02; /* Habilita interrupcao por PCINT[8..15]*/
    *pcimsk1 |= 0x01; /* Habilita interrupcao apenas em PCINT8 */

	sei(); 	/* Habilita interrupcoes */
}
