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

#include <stdint.h>
#include "button.h"

uint8_ptr portd = 0x2B,
          ddrd = 0x2A,
          pinc = 0x26,
          ddrc = 0x27;

uint8_t pin_c0_mask = 0x01;

int counter = 0,
    digit;

int main(void)
{
    *ddrd |= 0xFE; /* Seta os pinos 1-7 do portd como saidas */
    *ddrc &= 0xFE ; /* Seta o pino 0 do portc como entrada */

    while (TRUE)
    {
        if (is_button_pressed(pinc, pin_c0_mask)) {
            counter++;
            digit = counter % 10;

            switch (digit)
            {
            case 0:
                *portd &= 0x00;
                *portd |= ZERO;
                break;
            case 1:
                *portd &= 0x00;
                *portd |= ONE;
                break;
            case 2:
                *portd &= 0x00;
                *portd |= TWO;
                break;
            case 3:
                *portd &= 0x00;
                *portd |= THREE;
                break;
            case 4:
                *portd &= 0x00;
                *portd |= FOUR;
                break;
            case 5:
                *portd &= 0x00;
                *portd |= FIVE;
                break;
            case 6:
                *portd &= 0x00;
                *portd |= SIX;
                break;
            case 7:
                *portd &= 0x00;
                *portd |= SEVEN;
                break;
            case 8:
                *portd &= 0x00;
                *portd |= EIGHT;
                break;
            case 9:
                *portd &= 0x00;
                *portd |= NINE;
                break;
            default:
                break;
            }
        }
    }
}

