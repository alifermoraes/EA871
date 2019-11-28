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

Waveform waveform;

volatile uint8_t i = 0, j = 0;
volatile uint16_t delay_ms = 0;
uint8_t delay_10us = 0;

volatile uint8_t waveform_received_flag = 0;
volatile uint8_t waveform_char;

int main(void) {
    
    TIMER_config();
    USART_config(UBRR);
    sei();
    waveform_get(NONE, &waveform);
    DDRB = 0x20;

    while (TRUE) {
        if (delay_ms > waveform.delay) {
            PORTB ^= 0x20;
            delay_ms = 0;
        }

        if (waveform_received_flag) {
            waveform_get(waveform_char, &waveform);
            i = 0;
            PORTB &= 0xDF;

            UCSR0B |= 0x40; /* Habilita interrupção TX Complete. */
            UDR0 = waveform.message[0];
            waveform_received_flag = 0;
        }
    }
}

ISR(TIMER2_OVF_vect) {
    OCR2A = waveform.waveform[i];
    i = (i + 1) % 200;
}

ISR(TIMER2_COMPB_vect) {
    delay_10us++;

    if (delay_10us > 99) {
        delay_ms++;
        delay_10us = 0;
    }
}

ISR(USART_TX_vect) {
    UDR0 = waveform.message[j];
    j++;

    if (!waveform.message[j]) {
        j = 1;
        UCSR0B &= 0xBF;
    }
}

ISR(USART_RX_vect) {
    waveform_received_flag = 1;
    waveform_char = UDR0;    
}