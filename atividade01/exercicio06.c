/*
 * Analise o programa abaixo.
 * a) O que as operações &, | e << fazem?
 * b) O que a notação 0x... significa?
 * c) O que deverá ser impresso na tela?
 * d) Entre com o programa em seu editor preferido, compile e execute. Sua hipótese se confirmou?
 * e) Modifique as operações (e/ou remova alguma, se preferir) para que somente os dois bits mais
 * significativos de c sejam iguais a zero, e os outros sejam iguais a 1.
 */

#include <stdio.h>

int main() {
    unsigned char c = 0xF3;

    /*
     * c = c & 0x01;
     * c = c << 3;
     * c = c | 0x06;
     */

    c |= 0xFF;
    c >>= 2;

    printf("%d\n", c);
    return 0;
}