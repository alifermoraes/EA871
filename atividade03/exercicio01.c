/**
 * Exercício 1
 * Neste exercício, o objetivo é utilizar uma GPIO como saída para acender um
 * LED externo, o qual deve ser conectado ao pino 23 do microcontrolador
 * ATMega328P.
 * a) Use  o  diagrama  de  pinagem  da  placa  de desenvolvimento  Arduino  UNO
 * para  identificar (1) o terminal a ser empregado dentre os conectores de
 * acesso ao ATMega328P, assim como (2) a porta e o bit correspondente que
 * devem ser utilizados para o funcionamento desejado.
 * b) Quais registradores de configuração da porta devem ser utilizados?
 * c) Consultando o manual do fabricante, obtenha os endereços de memória
 * associados a cada um dos registradores.
 * d) Monte o circuito e escreva o programa que faça com que o LED permaneça
 * aceso.
 */

#include <avr/io.h>
#include <stdint.h>    

uint8_t * ptr_portc = (uint8_t *) 0x28;
uint8_t * ptr_ddrc = (uint8_t *) 0x27;

int main(void) {


    /* Seta o bit 0 do portc como saida */
    *ptr_ddrc |= 0x01;

    while (1) {
        /* Seta o bit 0 do portc em nivel logico alto */
        *ptr_portc |= 0x01;
    }
}
