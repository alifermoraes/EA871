/*
 * Leia o código-fonte abaixo, correspondente a um trecho do programa 04-entradas_saidas.c.
 * a) Encontre todas as palavras-chave que você não conhece.
 * b) Um dos parâmetros da instrução scanf tem um símbolo &. O que ele significa?
 * c) Faça uma hipótese sobre o que o programa faz.
 * d) Compile e execute o programa. Ele fez que você imaginava?
 * e) Modifique o programa para que ele escreva “PASSOU” caso o número digitado pelo usuário seja
 * maior ou igual a 5, e “REPROVOU” caso o número seja menor que 5.
*/

#include <stdio.h>

int main() {
    int a;
    float b;

    printf("Digite um inteiro e entao ENTER\n");
    scanf("%d", &a);
    
    if (a >= 5) {
        printf("Passou!\n");
    } else {
        printf("Reprovou!\n");
    }
    
    return 0;
}