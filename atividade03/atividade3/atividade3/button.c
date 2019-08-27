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

#include "button.h"
#include <stdint.h>
#include <util/delay.h>

/**
 * Funcao que checa se um dado botao foi pressionado.
 * 
 * Parametros:
 * - MASK: mascara referente ao pino no qual o botao esta conectado.
 * - pin_button: ponteiro contendo o endereco do PIN do port no qual o botao
 * esta conectado.
 * 
 * Retorno: retorna 1 se o botao foi pressionado.
 */

int is_button_pressed(uint8_t MASK, uint8_ptr pin_button) {
	uint8_t actual_state = 0x00,
			previous_state;

	while (TRUE) {
		previous_state = actual_state;
		actual_state = *pin_button & MASK;

		if (actual_state != previous_state) {
			_delay_ms(50);
			actual_state = *pin_button & MASK;

			if (!actual_state) {
				return TRUE;
			}
		}
	}
}

/**
 * Funcao que exibe no display de 7 segmentos o digito correspondente
 * 
 * Parametros:
 * - digit: digito que sera exibido no display.
 * - port: ponteiro para o endereco do port onde os leds do display estao
 * conectados
 */
void display_digit(int digit, uint8_ptr port) {
	        switch (digit) {
        case 0:
            *port &= 0x00;
            *port |= ZERO;
            break;
        case 1:
            *port &= 0x00;
            *port |= ONE;
            break;
        case 2:
            *port &= 0x00;
            *port |= TWO;
            break;
        case 3:
            *port &= 0x00;
            *port |= THREE;
            break;
        case 4:
            *port &= 0x00;
            *port |= FOUR;
            break;
        case 5:
            *port &= 0x00;
            *port |= FIVE;
            break;
        case 6:
            *port &= 0x00;
            *port |= SIX;
            break;
        case 7:
            *port &= 0x00;
            *port |= SEVEN;
            break;
        case 8:
            *port &= 0x00;
            *port |= EIGHT;
            break;
        case 9:
            *port &= 0x00;
            *port |= NINE;
            break;
        default:
            *port &= 0x00;
            *port |= ZERO;
            break;
        }
}