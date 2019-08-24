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

#include <util/delay.h>
#include <stdint.h>
#include "button.h"

int is_button_pressed(uint8_ptr pin_button, uint8_t MASK) {
	uint8_t actual_state = 0x00,
			previous_state;

	previous_state = actual_state;
	actual_state = pin_button & MASK;

	if (actual_state != previous_state) {
		_delay_ms(100);
		actual_state = pin_button & MASK;

		if (!actual_state) {
			return 1;
		} else {
			return 0;
		}
	}
} 
