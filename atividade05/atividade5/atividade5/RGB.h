/**
 * EA871 T
 * Atividade05 - Interrupções
 *
 * Alifer Willians de Moraes
 * RA: 165334
 *
 * Algumas definições para tornar o código mais organizado e fácil de ler.
 */

#ifndef RGB_H_
#define RGB_H_

#include <stdint.h>

#define OFF     0x00
#define RED     0x01
#define GREEN   0x02
#define BLUE    0x04
#define YELLOW  0x03
#define MAGENTA 0x05
#define CYAN    0x06
#define WHITE   0x07

#define TRUE    1

uint8_t colors[] = {OFF, RED, GREEN, BLUE, YELLOW, MAGENTA, CYAN, WHITE};

typedef volatile uint8_t * v_uint8_ptr;
typedef uint8_t * uint8_ptr;

#endif /* RGB_H_ */
