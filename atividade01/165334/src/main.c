/* Contador de bits
 *
 * Este programa conta o numero de bits em um byte
 */

#include <stdio.h>

int main() {

  unsigned char entrada;
  unsigned int tmp;
  unsigned int n_bits;

  /* Ler entrada em hexadecimal */
  scanf("%x", &tmp);
  entrada = (unsigned char)tmp;

  n_bits = 0;

  while (tmp) {
      if (tmp & 0x01) { /* Checa se o bit menos significativo de tmp é igual à 1. Caso seja, adiciona 1 à contagem de bits */
          n_bits++;
      }

      tmp >>= 1;
  }

  /* Escrever numero de bits */
  printf("%d\n", n_bits);
  return 0;
}
