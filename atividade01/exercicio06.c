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
    unsigned char c1 = 0xF3;
    char c2 = 0xF3;

    /*
     * c = c & 0x01;
     * c = c << 3;
     * c = c | 0x06;
     */
    printf("c1 = %2x\n", c1);
    printf("c2 = %2x\n", c2);
    c1 |= 0xFF;
    c1 >>= 2;

    c2 |= 0xFF;
    c2 <<= 2;

    printf("c1 = %2x\n", c1);
    printf("c2 = %2x\n", c2);

    printf("%d\n", c1);
    printf("%d\n", c2);
    return 0;
}