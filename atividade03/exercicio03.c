/**
 * Exercício 3
 * Aproveitando a montagem do exercício anterior, modifique o comportamento do
 * sistema de modo que o estado do LED seja alterado cada vez que o botão for
 * pressionado. Ou seja, se o LED estava aceso e o botão foi pressionado, o LED
 * é apagado; ou, analogamente, se o LED estava apagado e o botão foi
 * pressionado, o LED acende.
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