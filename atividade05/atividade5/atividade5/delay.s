.GLOBAL DELAY

DELAY:
    /* Salva o valor inicial dos registradores na pilha */
    PUSH R16
    PUSH R17
    PUSH R24
    PUSH R25

    /* Necessario incrementar R25 pois o loop sera executado R25 - 1 vezes */
    INC R25

    /* Valores iniciais para um atraso base de aproximadamente 16_000 ciclos
     * Numero total de ciclos = ((R16 - 1) * 3 + 2) + ((254 * 3 + 2) + 3) * (R17 - 1)
     * R16 = 219 e R17 = 21 => 15996 ciclos + 2 ciclos de LDI = 15998 ciclos.
     */
BASE_DELAY:
    LDI R16, 219
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

    /* Restaura os valores dos registradores */
    POP R25
    POP R24
    POP R17
    POP R16
RET