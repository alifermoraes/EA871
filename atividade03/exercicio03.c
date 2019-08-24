/**
 * Exercício 3
 * Aproveitando a montagem do exercício anterior, modifique o comportamento do
 * sistema de modo que o estado do LED seja alterado cada vez que o botão for
 * pressionado. Ou seja, se o LED estava aceso e o botão foi pressionado, o LED
 * é apagado; ou, analogamente, se o LED estava apagado e o botão foi
 * pressionado, o LED acende.
 */

#include <util/delay.h>
#include <stdint.h>

/* Ponteiros para regioes de memoria dos ports que serao utilizados */
uint8_t *ptr_portc = (uint8_t *) 0x28,
        *ptr_ddrc = (uint8_t *) 0x27,
        *ptr_pind = (uint8_t *) 0x29,
        *ptr_ddrd = (uint8_t *) 0x2A;

/* Mascaras */
uint8_t pin_d7_mask = 0x80,
        pin_c0_mask = 0x01;

/* Variaveis para monitorar o estado do botao */
uint8_t portd_actual_state = 0x00,
        portd_previous_state,

int main(void) {
	*ptr_ddrc |= 0x01; /* Seta o bit 0 do portc como saida */
	*ptr_ddrd &= 0x7F; /* Seta o bit 7 do portd como entrada */
	
	while (1) {
		portd_previous_state = portd_actual_state;
		portd_actual_state = *ptr_pind & pin_d7_mask;

		if (portd_actual_state != portd_previous_state) {
		    _delay_ms(100); /* Correcao de bouncing do botao */
		    portd_actual_state = *ptr_pind & pin_d7_mask;

		    if (!portd_actual_state) {
			    *ptr_portc ^= pin_c0_mask; /* Muda o estado do LED */
			}
		}
	}
}
