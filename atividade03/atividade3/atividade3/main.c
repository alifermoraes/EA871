/**
 * Atividade03 - GPIO
 *
 * Alifer Willians de Moraes
 * RA: 165334
 *
 * O desafio proposto nesta atividade e desenvolver um programa que faca com que
 * o microcontrolador ATMega328P conte quantas vezes um botao tactil
 * (push-button) foi pressionado, exibindo o valor atual da contagem em um
 * display de 7 segmentos.
 * Por  simplicidade, vamos exibir somente um  digito, de maneira que a contagem
 * estara limitada ao intervalo de 0 a 9. Ou seja, caso a contagem ultrapasse o
 * valor 9, ela deve ser reiniciada a partir de 0.
 */ 

#include "digits.h"
#include <util/delay.h>

/* Ponteiros para os enderecos que serao usados */
uint8_ptr ucsr0b = (uint8_ptr) 0xC1,
		  portd = (uint8_ptr) 0x2B,
          ddrd = (uint8_ptr) 0x2A,
		  portc = (uint8_ptr) 0x28,
          ddrc = (uint8_ptr) 0x27,
          pinc = (uint8_ptr) 0x26;

uint8_t pin_c0_mask = 0x01,
		actual_state = 0x00,
		previous_state;
		
void startup(void) {
	*ucsr0b &= 0xF7; /* Desabilita a funcao UART do pino 1 do port D (TX) */
	*ddrd |= 0xFE; /* Seta os pinos 1-7 do portd como saidas */
	*ddrc &= 0xFE; /* Seta o pino 0 do portc como entrada */
	*portc |= 0x01; /* Habilita o resistor de pull-up do pino 0 do port C */

	/* Inicia o display exibindo o valor zero */
	*portd &= 0x01; /* Apaga os segmentos do display */
	*portd |= ZERO; /* Seta os bits dos segmentos referentes ao digito 0 */
}

int main(void)
{	
	unsigned int counter = 0;

	startup();

    while (TRUE)
    {
	    previous_state = actual_state;
	    actual_state = *pinc & pin_c0_mask;
		
		/**
		 * Se o estado anterior for diferente do estado atual, quer dizer que
		 * o botao foi pressionado
		 */
	    if (actual_state != previous_state) {
		    /* Debouncing */
			_delay_ms(50);
		    actual_state = *pinc & pin_c0_mask;
			
			/* Se o botao foi realmente pressionado, incrementa a contagem */
		    if (!actual_state) {
			    counter++;
			    display_digit((counter % 10), portd);
		    }
	    }
	}	
}
