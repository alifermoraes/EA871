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

.DEF BMASK = R16
.DEF DL1 = R17
.DEF DL2 = R18
.DEF PRMLO = R24
.DEF PRMHI = R25

.CSEG

.ORG 0x0000
JMP MAIN
.ORG 0x0034

MAIN:
    /* Define o valore de R25:R24 para simular o parâmetro que será passado pelo programa em C */
    LDI PRMLO, 0xF4
    LDI PRMHI, 0x01

    /* Seta o portb como saida */
    LDI BMASK, 0x20
    OUT DDRB, BMASK

WHILETRUE:
    SBI PORTB, 5
    CALL DELAY
    CBI PORTB, 5
    CALL DELAY
    RJMP WHILETRUE

DELAY:
    /* Salva o valor inicial dos registradores, que serão utilizados, na pilha. */
    PUSH DL1
    PUSH DL2
    PUSH PRMLO
    PUSH PRMHI

    /*
     * Necessário incrementar R25 para que o delay base seja executado (R24 + 256 * R25), pois essa
     * sub brotina executa R24 + 256 * (R25 -1) vezes. (Tratando R24 e R25 como valores
     * independentes de 8 bits).
     */
    INC PRMHI

    /* Valores iniciais para um atraso base de aproximadamente 16_000 ciclos
     * Número total de ciclos da rotina implementada: ((R17 - 1) * 3 + 2) + ((254 * 3 + 2) + 3) * (R18 - 1)
     * R17 = 219 e R18 = 21 => 15996 ciclos + 2 ciclos de LDI = 15998 ciclos.
     */

BASE_DELAY:
    LDI DL1, 219
    LDI DL2, 21

LOOP:
    DEC DL1
    BRNE LOOP
    DEC DL2
    BRNE LOOP
    DEC PRMLO
    BRNE BASE_DELAY
    DEC PRMHI
    BRNE BASE_DELAY

    /* Restaura os valores originais dos registradores */
    POP PRMHI
    POP PRMLO
    POP DL2
    POP DL1
RET
