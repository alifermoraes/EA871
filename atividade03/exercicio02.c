/**
 * Exercício 2
 * Agora, vamos acrescentar ao projeto um botão táctil, de modo a controlar o
 * acionamento do LED. No caso, somente enquanto o botão estiver pressionado é
 * que o LED deve acender. A fim de exercitarmos um pouco mais o uso de GPIOs,
 * vamos utilizar o pino 13 do microcontrolador para a conexão com o botão.
 * a) Use  o  diagrama  de  pinagem  da  placa  de  desenvolvimento  Arduino
 * UNO  para  identificar (1) o terminal a ser empregado dentre os conectores
 * de acesso ao ATMega328P, assim como (2) a porta e o bit correspondente que
 * devem ser utilizados para o funcionamento desejado.
 * b) Quais registradores de configuração da porta devem ser utilizados?
 * c) Consultando o manual do fabricante, obtenha os endereços de memória
 * associados a cada um dos registradores.
 * d) Monte o circuito e escreva o programa que implemente o comportamento
 * desejado.
 */

#include <stdint.h>

/* Ponteiros para regioes de memoria dos ports que serao utilizados */
uint8_t * ptr_portc = (uint8_t *) 0x28;
uint8_t * ptr_ddrc = (uint8_t *) 0x27;
uint8_t * ptr_pind = (uint8_t *) 0x29;
uint8_t * ptr_ddrd = (uint8_t *) 0x2A;

/* Mascaras */
uint8_t pin_d7_mask = 0x80;
uint8_t pin_c0_mask = 0x01;

int main(void) {

	*ptr_ddrc |= 0x01; /* Seta o bit 0 do portc como saida */
	*ptr_ddrd &= 0x7F; /* Seta o bit 7 do portd como entrada */
	
	while (1) {
		if (*ptr_pind & pin_d7_mask) {
			*ptr_portc &= ~pin_c0_mask; /* Apaga o LED */
		} else {
			*ptr_portc |= pin_c0_mask; /* Acende o LED */
		}
	}
}
