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

#ifndef DIGITS_H_
#define DIGITS_H_

#include <stdint.h>

/**
 * Define os bits do port que serao acionados para formar cada digito no
 * display de sete segmentos. bit1 = a, bit2 = b, ... , bit 7 = g
 */
#define ZERO    0x7E /* 0111 1110 - segmentos do display: a, b, c, d, e, f */
#define ONE     0x0C /* 0000 1100 - segmentos do display: b, c */
#define TWO     0xB6 /* 1011 0110 - segmentos do display: a, b, d, e, g */
#define THREE   0x9E /* 1001 1110 - segmentos do display: a, b, c, d, g */
#define FOUR    0xCC /* 1100 1100 - segmentos do display: b, c, f, g */
#define FIVE    0xDA /* 1101 1010 - segmentos do display: a, c, d, f, g */
#define SIX     0xFA /* 1111 1010 - segmentos do display: a, c, d, e, f, g */
#define SEVEN   0x0E /* 0000 1110 - segmentos do display: a, b, c */
#define EIGHT   0xFE /* 1111 1110 - segmentos do display: a, b, c, d, e, f, g */
#define NINE    0xDE /* 1101 1110 - segmentos do display: a, b, c, d, f, g */

#define F_CPU 16000000
#define TRUE 1

/**
 * Define um novo nome para ponteiros do tipo uint8_t
 * uint8_t é um tipo de dado de 8 bits (unsigned char)
 */
typedef uint8_t * uint8_ptr;

void display_digit(int, uint8_ptr);

#endif /* DIGITS_H_ */