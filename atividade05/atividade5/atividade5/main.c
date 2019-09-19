/**
 * EA871 T
 * Atividade05 - Interrupções
 *
 * Alifer Willians de Moraes
 * RA: 165334
 *
 * O desafio proposto nesta atividade é desenvolver um programa que controle um LED RGB, sendo
 * sensível a comandos externos dados por dois botões. Em princípio, o estado do LED RGB será
 * alterado de forma periódica pelo microcontrolador, passando por uma sequência pré-definida de
 * estados.
 *
 * Apagado <=> Vermelho <=> Verde <=> Azul <=> Amarelo <=> Magenta <=> Ciano <=> Branco <=> Recomeça
 *
 * Amarelo: vermelho + verde.
 * Magenta: vermelho + azul.
 * Ciano: verde + azul.
 * Branco: vermelho + verde + azul.
 *
 * O fluxo dos estados pode se dar no sentido horário (setas para a direita) ou no sentido
 * anti-horário (setas para a esquerda), sendo que o LED RGB deve permanecer em cada estado e,
 * portanto, em cada uma das possíveis cores, por um intervalo de tempo controlado pelo programa.
 
 * Um dos botões, aqui denominado de botão A, terá efeito sobre a velocidade de transição entre os
 * estados. Cada vez que ele for pressionado, o intervalo de tempo que o LED permanece em cada
 * estado, i.e., em cada cor, deve ser reduzido pela metade até atingir um valor mínimo
 * (e.g., 0,125 s). Caso o usuário tente reduzir ainda mais esse tempo, ele deve ser reinicializado
 * para o tempo máximo de 1 segundo (que, a propósito, também é o tempo inicial). O outro botão,
 * denotado por botão B, controlará o sentido da transição de cores: horário ou anti-horário.
 * Ambos os botões poderão disparar interrupções externas. Porém, enquanto o botão A (velocidade)
 * estará associado à interrupção externa INT0, configurada para responder a bordas de subida, o
 * botão B (sentido) estará associado a uma interrupção do tipo pin-change. Mais especificamente,
 * escolhemos a PCINT8, gerada a partir do pino 0 da porta C, o qual está indicado no manual do
 * microcontrolador como PCINT8.
 */ 

#include "RGB.h"
#include <avr/interrupt.h>

/* Ponteiros para endereços de memória dos ports. */
uint8_ptr portb = (uint8_ptr) 0x25,
          ddrb = (uint8_ptr) 0x24,
          ddrc = (uint8_ptr) 0x27,
          ddrd = (uint8_ptr) 0x2A;

uint8_v_ptr pinc = (uint8_v_ptr) 0x26,
            pind = (uint8_v_ptr) 0x29;

/* Ponteiros para endereços de memoria para as interrupções. */
uint8_ptr eicra = (uint8_ptr) 0x69,
          eimsk = (uint8_ptr) 0x3D,
          pcicr = (uint8_ptr) 0x68,
          pcimsk1 = (uint8_ptr) 0x6C;

volatile unsigned int msec_delay = 1000;
volatile int8_t direction = 1;
uint8_t counter = 0;

void startup(void);
extern void DELAY(volatile unsigned int msec);

int main(void) {
    startup();

    while (TRUE) {
		/* Percorre o vetor que armazena as combinações de cores do LED RGB. */
		*portb &= 0xF8;
        *portb |= colors[counter % 8];
        counter += direction;
        DELAY(msec_delay);
    }
}

/* 
 * Com a utilização do Schmitt trigger para corrigir o problema de debouncing do botão, o sinal
 * lido pelos pinos conectados ao botão é 0 quando o botão não é pressionado e 1 quando o botão
 * é pressionado.
 */

/* Lida com a interrupção INT0 (velocidade). */
ISR(INT0_vect) {
    if (msec_delay <= 125) {
        msec_delay = 1000;
    } else {
        msec_delay /= 2;
    }
}


/* Lida com a interrupção PCINT8 (direção). */
ISR(PCINT1_vect){
	/*
	 * Como PCINT gera interrupção sempre que há mudança no estado lógico, é necessário corrigir
	 * via software para que essa interrupção ocorra apenas ao apertar o botão e não ao solta-lo.
	 */
    if (*pinc & 0x01) {
        direction *= -1;
    }
}


void startup(void) { /* Executa as instruções para configuração inicial do microcontrolador. */
	/* Configurações de interrupções. */
	*eimsk |= 0x01; /* Habilita interrupção por INT0. */
	*eicra |= 0x03; /* Configura INT0 para gerar interrupções apenas na borda de subida. */
	*pcicr |= 0x02; /* Habilita interrupção por PCINT[8..15]. */
	*pcimsk1 |= 0x01; /* Habilita interrupção apenas em PCINT8. */
	sei(); 	/* Habilita interrupções. */
	
    /* Definições de direção dos ports (entrada/saída). */
    *ddrb |= 0x07;
    *ddrc &= 0xFE;
    *ddrd &= 0xFB;

    *portb &= 0xF8; /* Inicia com o LED RGB apagado. */
}
