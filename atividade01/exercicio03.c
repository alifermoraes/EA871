#include <stdio.h>

int main() {
    int a, b, c; /* Vamos utilizar estas variaveis para fazer testes */
    float x, y, z; /* Tambem vamos testar coisas com estas variaveis */
    
    printf("Comparacao - int com int\n");
    
    a = 0;
    
    if (0 == 0) {
        printf("0 == 0\n");
    }
    if (a == 0) {
        printf("a == 0\n");
    }
    if (a == 1) {
        printf("a == 1\n");
    } else {
        printf("a != 1\n");
    }
    
    printf("\n");printf("Comparacao - int com float\n");
    
    x = 0.0;
    y = 0.5;
    
    if (0.0 == 0.0) {
        printf("0.0 == 0.0\n");
    }
    if (x == 0.0) {
        printf("x == 0.0\n");
    }
    if (a == x) {
        printf("0 == 0.0\n");
    }
    if (a == y) {
        printf("0 == 0.5\n");
    }
    
    printf("\n");
    return 0;
}
