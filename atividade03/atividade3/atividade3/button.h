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

#ifndef BUTTON_H_
#define BUTTON_H_

/**
 * Define os bits do port que serao acionados para formar cada digito no
 * display de sete segmentos. bit1 = a, bit2 = b, ... , bit 7 = g
 */
#define ZERO    0x7E
#define ONE     0x0C
#define TWO     0xB6
#define THREE   0x9E
#define FOUR    0xCC
#define FIVE    0xDA
#define SIX     0xFA
#define SEVEN   0x0E
#define EIGHT   0xFE
#define NINE    0xDE

#define TRUE 1

/**
 * Define um novo nome para ponteiros do tipo uint8_t
 * uint8_t é um tipo de dado de 8 bits (unsigned char)
 */
typedef uint8_t * uint8_ptr;

int is_button_pressed(uint8_ptr, uint8_t);

#endif /* BUTTON_H_ */