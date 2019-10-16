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

uint8_t rgb_decoder(uint8_t command) {
    switch (command) {
    case 'b': case 'B':
        return BLUE;
    case 'c': case 'C':
        return CYAN;
    case 'g': case 'G':
        return GREEN;
    case 'm': case 'M':
        return MAGENTA;
    case 'r': case 'R':
        return RED;
    case 'w': case 'W':
        return WHITE;
    case 'y': case 'Y':
        return YELLOW;
    default:
        return INVALID;
    }
}
