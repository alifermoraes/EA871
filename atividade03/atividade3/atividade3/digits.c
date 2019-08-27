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

/**
 * Funcao que exibe no display de 7 segmentos o digito correspondente
 * 
 * Parametros:
 * - digit: digito que sera exibido no display.
 * - port: ponteiro para o endereco do port onde os segmentos do display estao
 * conectados
 */
void display_digit(int digit, uint8_ptr port) {
	*port &= 0x01; /* Apaga todos os segmentos do display */
	
	switch (digit) {
    case 0:
        *port |= ZERO; /* Seta os bits dos segmentos do digito 0 */
        break;
    case 1:
        *port |= ONE; /* Seta os bits dos segmentos do digito 1 */
        break;
    case 2:
        *port |= TWO; /* Seta os bits dos segmentos do digito 2 */
        break;
    case 3:
        *port |= THREE; /* Seta os bits dos segmentos do digito 3 */
        break;
    case 4:
        *port |= FOUR; /* Seta os bits dos segmentos do digito 4 */
        break;
    case 5:
        *port |= FIVE; /* Seta os bits dos segmentos do digito 5 */
        break;
    case 6:
        *port |= SIX; /* Seta os bits dos segmentos do digito 6 */
        break;
    case 7:
        *port |= SEVEN; /* Seta os bits dos segmentos do digito 7 */
        break;
    case 8:
        *port |= EIGHT; /* Seta os bits dos segmentos do digito 8 */
        break;
    case 9:
        *port |= NINE; /* Seta os bits dos segmentos do digito 9 */
        break;
    default:
        *port |= ZERO; /* Seta os bits dos segmentos do digito 0 */
        break;
    }
}