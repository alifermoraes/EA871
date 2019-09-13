/**
 * Atividade03 - GPIO
 *
 * Alifer Willians de Moraes
 * RA: 165334
 *
 * Nesta atividade, teremos o cuidado de preparar a sub-rotina de atraso de tal maneira que ela
 * possa ser futuramente incorporada a projetos desenvolvidos em linguagem C sem maiores
 * dificuldades. Por isso, seguiremos a convenção de passagem de parâmetros adotada pelo compilador
 * C do Atmel Studio. No caso, a sub-rotina deve receber como entrada um valor de 16 bits (sem
 * sinal) que especifica o tempo de atraso em milissegundos (e.g., um valor igual a 1000 deve levar
 * a rotina a produzir um atraso de 1 segundo). Este valor deve ser recebido pela sub-rotina
 * através do par de registradores r25:r24.
 * Por fim, escreva um programa em Assembly que faça com que um LED pisque com um período de 1
 * segundo. Ou seja, o LED deve permanecer aceso por 0,5 segundo, ficando apagado por 0,5 segundo em
 * seguida. Por simplicidade, vamos utilizar o próprio LED incorporado presente no Arduino UNO, o
 * qual pode ser acionado pelo bit 5 da porta B (PB5).
 */

.DEF B0=R16
.DEF CYC1=R17
.DEF CYC2=R18
.DEF CYC3=R19

.CSEG

.ORG 0x0000
JMP main

.ORG 0x0034
main:
	LDI B0, 0x01
	OUT DDRB, B0

whiletrue:
	SBI PORTB, 0
	CALL delay
	CBI PORTB, 0
	CALL delay
	RJMP whiletrue

 /* Subrotina para atraso. Gasta aproximadamente 8 milhoes de ciclos de CPU (500ms para 16 MHz) */
delay:
	/* Salva os valores originas dos registradores usados na pilha */
	PUSH CYC3
	PUSH CYC2
	PUSH CYC1

	/* Seta os valores para consumir os ciclos necessarios de CPU */
	LDI CYC3, 41
	LDI CYC2, 150
	LDI CYC1, 128

cycles:
	DEC CYC1
	BRNE cycles
	DEC CYC2
	BRNE cycles
	DEC CYC3
	BRNE cycles

	/* Restaura os valores originais dos registradores*/
	POP CYC1
	POP CYC2
	POP CYC3

	RET /* retorna da subrotina delay */