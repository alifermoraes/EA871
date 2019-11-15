/**
 * EA871 T
 * Atividade09 - Modulação por largura de pulso (PWM)
 *
 * Alifer Willians de Moraes
 * RA: 165334
 *
 * O desafio proposto nesta atividade é desenvolver um programa que faça com que a intensidade
 * luminosa de um LED seja controlada por um sinal PWM. Mais especificamente, desejamos que a
 * intensidade cresça em, aproximadamente, 1 segundo desde a mínima até a máxima, de maneira que
 * enxerguemos o LED acendendo aos poucos. Então, uma vez atingida a máxima intensidade, devemos
 * reduzi-la até o valor mínimo também em um intervalo de, aproximadamente, 1 segundo.  A fim de
 * permitir uma visualização suave do aumento da intensidade do LED (processo de fade in), o
 * registrador que controla o duty cycle do sinal PWM deve ser progressivamente incrementado desde
 * 0 até seu valor máximo durante o intervalo de 1 segundo. Um raciocínio análogo vale para o
 * processo de redução da intensidade do LED (fade out).
 * 
 * As especificações do temporizador (e.g., prescaler, valor máximo da contagem, etc.) devem ser
 * projetadas por cada aluno e justificadas nos comentários do código-fonte. Notem que há mais de
 * uma maneira de se configurar o temporizador para atingir o comportamento desejado do sistema.
 * 
 * Somente o temporizador 2 poderá ser utilizado na atividade, sendo que o modo de operação
 * explorado deve ser o Fast PWM.
 * 
 * Observação: é possível usar o modo Fast PWM do timer 2 com a contagem avançando desde 0 até 255,
 * ou com a contagem partindo de 0 até o valor armazenado em OCR2A.
 */

/**
 * As configurações de prescaler, timer2 TOP = OCR2A = 250, fazem com que ocorra a interrupção de
 * overflow do timer2 a cada 250 ciclos, com prescaler definido como 256, 250 ciclos equivalem à
 * 4 ms. Essa interrupção é utilizada para incrementar o valor de OCR2B que é usado como PWM, como
 * o valor de TOP é 250, OCR2A é incrementado até esse valor, portanto: 4 ms x 250 = 1 s.
 */

#include "timer2.h"
#include <avr/interrupt.h>

int8_t direction = 1;

int main(void) {
    DDR_D |= 0x08; /* PORTD Pin3 (OCR2B) definido como saída. */
    timer2_config();
    sei();

    while (TRUE) {
        if ((OCR2B > 249 && direction == 1) || (OCR2B < 1 && direction == -1)) {
            direction *= -1;
        }
    }
}

ISR (TIMER2_OVF_vect) {
    OCR2B += direction;
}
