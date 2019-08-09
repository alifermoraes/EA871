#include <stdio.h>

int main() {
	/* Neste programa, declararemos algumas variaveis:*/

	char c0, c1, c2, c3; /* C permite a declaracao de varias variaveis numa unica sequencia */
	int i0, i1, i2, i3;
	float f0, f1, f2, f3;
	
	/* Vamos atribuir alguns valores e escreve-los na tela */
	c0 = 'd';
	i0 = 50;
	f0 = 50.0;

	/* Atencao a sintaxe do printf para escrever variaveis na tela!
	coloque um %c, %d ou %f para marcar, na string, as posicoes em que as
	variaveis serao escritas; apos, declare quais serao essas variaveis que
	serao escritas - na ordem que aparecem na string! */
	printf("Atribui os valores %c, %d e %f as minhas variaveis!\n", c0, i0, f0);
	
	/* Teste de aritmetica */
	printf("Aritmetica com int (+ - * / 3): %d, %d, %d, %d\n", i0+3, i0-3, i0*3, i0/3);
	printf("Aritmetica com float (+ - * / 3): %.2f, %.2f, %.2f, %.2f\n", f0+3, f0-3, f0*3, f0/3);
	printf("Aritmetica com char (+ - * / 3): %c, %c, %c, %c\n", c0+3, c0-3, c0*3, c0/3);

	/* Mas, lembre que char eh um tipo inteiro! Entao, o codigo seguinte eh valido: */
	printf("Aritmetica com char (+ - * / 3): %d, %d, %d, %d\n", c0+3, c0-3, c0*3, c0/3);
	return 0;
}
