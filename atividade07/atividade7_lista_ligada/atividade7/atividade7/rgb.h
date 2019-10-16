/**
 * EA871 T
 * Atividade07 - Transmissão e Recepção Serial com Interrupções
 *
 * Alifer Willians de Moraes
 * RA: 165334
 *
 * Definições de funções de interação com o LED RGB.
 */ 

#include <stdint.h>

#ifndef RGB_H
#define RGB_H

#define EMPTY	0x00
#define RED     0x01
#define GREEN   0x02
#define BLUE    0x04
#define YELLOW  0x03
#define MAGENTA 0x05
#define CYAN    0x06
#define WHITE   0x07
#define INVALID 0x08

uint8_t rgb_decoder(uint8_t command);

#endif /* RGB_H */
