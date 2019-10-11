/**
 * EA871 T
 * Atividade07 - Transmissão e Recepção Serial com Interrupções
 *
 * Alifer Willians de Moraes
 * RA: 165334
 *
 * Funções de interação com LED RGB.
 */

#include "rgb.h"
#include <stdint.h>

uint8_t rgb_decoder(uint8_t cmd) {
    switch (cmd) {
    case 'r': case 'R':
        return RED;
    case 'g': case 'G':
        return GREEN;
    case 'b': case 'B':
        return BLUE;
    case 'y': case 'Y':
        return YELLOW;
    case 'c': case 'C':
        return CYAN;
    case 'm': case 'M':
        return MAGENTA;
    case 'w': case 'W':
        return WHITE;
    default:
        return INVALID;
    }
}
