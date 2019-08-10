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