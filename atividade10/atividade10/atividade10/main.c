/**
 * EA871 T
 * Atividade10 - Síntese de formas de onda via PWM
 *
 * Alifer Willians de Moraes
 * RA: 165334
 *
 * O desafio proposto nesta atividade é desenvolver um programa que gere um sinal PWM cuja largura
 * de pulso em cada período represente o valor de uma amostra de uma forma de onda analógica, a
 * qual pode ser reconstruída por meio de uma filtragem do tipo passa-baixas.
 *
 * O usuário pode selecionar a forma de onda que deseja gerar por meio de comandos enviados pela
 * porta serial:
 * - Onda senoidal          =>  comando: 's';   mensagem: "Onda senoidal\n";
 * - Onda triangular        =>  comando: 't';   mensagem: "Onda triangular\n";
 * - Onda dente-de-serra    =>  comando: 'd';   mensagem: "Onda dente-de-serra\n";
 * - Onda AM                =>  comando: 'a';   mensagem: "Onda AM\n";
 * - Sem forma de onda      =>  comando: '¹';   mensagem: "Nenhuma forma de onda selecionada\n";
 * ¹ := Qualquer outro comando.
 *
 * Uma vez selecionado um comando, o programa deve responder através da porta serial com uma
 * mensagem de confirmação (uma única vez) conforme indicado na Tabela 1. Tanto a recepção de
 * comandos quanto a transmissão de mensagens deve ser baseada em interrupções.
 *
 * A frequência de amostragem (i.e., o número de amostras coletadas por segundo) corresponde à
 * própria frequência do sinal PWM, e deve ser igual a 62,5 kHz. Além disso, devem ser geradas 200
 * amostras por período, em intervalos de tempo regulares, para cada forma de onda.
 * 
 * O LED incorporado também deve ser acionado para indicar qual a forma de onda selecionada,
 * piscando de acordo com as seguintes especificações:
 *
 * - Onda senoidal:       1 s aceso, 1 s apagado;
 * - Onda triangular:     500 ms aceso, 500 ms apagado;
 * - Onda dente-de-serra: 250 ms aceso, 250 ms apagado;
 * - Onda AM:             125 ms aceso, 125 ms apagado;
 * - Sem forma de onda Apagado;
 * 
 * As especificações do temporizador (e.g., prescaler, valor máximo da contagem, etc.) devem ser
 * justificadas nos comentários do código-fonte. Somente o temporizador 2 poderá ser utilizado na
 * atividade, sendo que o modo de operação explorado deve ser o Fast PWM.
 */

#include "timer.h"
#include "usart.h"
#include "waveform.h"
#include <avr/interrupt.h>

int main(void) {
    
    TIMER_config();
    USART_config(UBRR);
    sei();

    while (TRUE) {
        /* Repeat */
    }
}

ISR(TIMER2_COMPB_vect) {

}

ISR(USART_TX_vect) {

}

ISR(USART_RX_vect) {

}