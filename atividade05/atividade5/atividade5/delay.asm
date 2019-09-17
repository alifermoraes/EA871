.GLOBAL DELAY

.CSEG
.ORG 0x0000
JMP DELAY
.ORG 0x0034

DELAY:
    /* Salva o valor inicial dos registradores na pilha */
    PUSH R16
    PUSH R17
    PUSH R24
    PUSH R25

    /* Valores iniciais para um atraso base de aproximadamente 16_000 ciclos
     * Numero total de ciclos = ((R16 - 1) * 3 + 5) + (254 * 3 + 5) * (R17 - 1)
     */
    LDI R16, 219
    LDI R17, 21
    INC R25

LOOP:
    DEC R16
    BRNE LOOP
    DEC R17
    BRNE LOOP
    LDI R16, 219
    LDI R17, 21
    DEC R24
    BRNE LOOP
    DEC R25
    BRNE LOOP

    /* Restaura os valores dos registradores */
    POP R25
    POP R24
    POP R17
    POP R16
RET