/**
 * EA871 T
 * Atividade08 - Temporizadores
 *
 * Alifer Willians de Moraes
 * RA: 165334
 *
 * O desafio proposto nesta atividade é desenvolver um programa que faça com que dois LEDs pisquem
 * em diferentes frequências, ao mesmo tempo em que uma mensagem de texto é continuamente
 * transmitida pela UART. Mais especificamente, desejamos que o LED incorporado pisque com uma
 * frequência de 2 Hz (0,5 s aceso, 0,5 s apagado), e que um LED externo, conectado ao pino 12 da
 * placa Arduino, pisque de forma a ficar 0,78 s aceso e 0,78 s apagado.
 * 
 * A solução para a atividade deve necessariamente explorar a interrupção do timer 2 associada ao
 * modo Clear Timer on Compare Match (CTC). As especificações do temporizador (e.g., prescaler e
 * valor máximo da contagem) devem ser projetadas por cada aluno e justificadas nos comentários do
 * código-fonte. Notem que há várias maneiras de se configurar o temporizador para obter o
 * comportamento desejado do sistema.
 * 
 * No tocante à UART, vamos utilizar a mesma configuração da atividade 6. Além disso, assim como
 * feito anteriormente, após a mensagem de texto ser enviada uma vez, deve ser introduzido um
 * atraso de 5 segundos antes de reiniciar as transmissões. Apenas pedimos que todos substituam o
 * vetor de caracteres a ser transmitido pela seguinte mensagem:
 * "Atividade 8 – Interrupcoes temporizadas tratam concorrencia entre tarefas!\n"
 */

#include "config.h"
#include <avr/interrupt.h>

volatile unsigned int delay_500ms = 0;
volatile unsigned int delay_780ms = 0;
volatile unsigned int delay_5k = 0;
unsigned int i = 0;

unsigned char msg[] = "Atividade 8 - Interrupcoes temporizadas tratam concorrencia entre tarefas!\n";

/**
 * O prescaler foi configurado para obter intervalos de 1 ms. A cada 1 ms ocorre uma interrupção
 * que incrementa variáveis que servem de contadores, baseado nesses valores as tarefas são
 * executadas no momento certo.
 */
int main(void){
    config_timer();
    config_usart();
    sei();

    DDR_B |= 0x30; /* PB5 e PB4 -> saídas. */

    while(TRUE) {
        if(delay_500ms > 499) {
            delay_500ms = 0;
            delay_5k++;
            PORTB ^= 0x20;
        }

        if (delay_780ms > 779) {
            delay_780ms = 0;
            PORTB ^= 0x10;
        }
        
        if (delay_5k > 9) {
            delay_5k = 0;
            UCSR0B |= 0x20; /* Habilita interrupção registrador de dados USART vazio. */
        }
    }
}

ISR(TIMER2_COMPA_vect) {
	delay_500ms++;
	delay_780ms++;
}

ISR (USART_UDRE_vect) {
	UDR0 = msg[i];
	i++;
	
	if (!msg[i]) {
		UCSR0B &= 0xDF;
		i = 0;
	}
}
