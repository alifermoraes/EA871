/**
 * EA871 T
 * Atividade05 - Interrupções
 *
 * Alifer Willians de Moraes
 * RA: 165334
 *
 * Sub-rotina para gerar um atraso variável de acordo com o parâmetro passado pelo programa em C
 * O atraso é baseado em um atraso base de 16_000 ciclos, equivalentes a 1 milisegundo em
 * microcontroladores de 16 MHz. Esse atraso base é repetido N vezes, onde N é o parâmetro passado
 * pelo programa em C (registradores R24 (LOW) e R25 (HIGH)).
 */ 

.GLOBAL DELAY /* Torna a subrotina delay visível para o programa em C. */

DELAY:
    /* Salva o valor inicial dos registradores, que serão utilizados, na pilha. */
    PUSH R16
    PUSH R17
    PUSH R24
    PUSH R25

    /**
     * Necessário incrementar R25 para que o delay base seja executado (R24 + 256 * R25), pois essa
     * sub-rotina executa R24 + 256 * (R25 - 1) vezes. (Tratando R24 e R25 como valores
     * independentes de 8 bits)
     */
    INC R25

    /**
     * Valores iniciais para um atraso base de aproximadamente 16_000 ciclos
     * Número total de ciclos da rotina implementada: 3 * R16 + 770 * R17 - 769.
     * R16 = 198 e R17 = 21 => 15995 ciclos + 2 ciclos de LDI = 15997 ciclos.
     */
BASE_DELAY:
    LDI R16, 198
    LDI R17, 21

LOOP:
    DEC R16
    BRNE LOOP
    DEC R17
    BRNE LOOP
    DEC R24
    BRNE BASE_DELAY
    DEC R25
    BRNE BASE_DELAY

    /* Restaura os valores originais dos registradores */
    POP R25
    POP R24
    POP R17
    POP R16
RET
