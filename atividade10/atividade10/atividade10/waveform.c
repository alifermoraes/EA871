/**
 * EA871 T
 * Atividade10 - Síntese de formas de onda via PWM
 *
 * Alifer Willians de Moraes
 * RA: 165334
 *
 * Description
 */

#include "waveform.h"

waveform sine {{}, "Onda senoidal\n"};
waveform triangle {{}, "Onda triangular\n"};
waveform sawtooth {{}, "Onda dente-de-serra\n"};
waveform am {{128, 141, 155, 168, 181, 192, 203, 211, 218, 223, 226, 226, 223, 218, 211, 201, 189, 176, 161, 145, 128, 110, 93, 76, 60, 46, 34, 23, 16, 10, 8, 9, 13, 19, 29, 41, 55, 71, 89, 108, 127, 147, 166, 185, 202, 217, 230, 241, 249, 253, 255, 253, 249, 241, 230, 217, 202, 185, 166, 147, 128, 108, 89, 71, 55, 41, 29, 19, 13, 9, 8, 10, 16, 23, 34, 46, 60, 76, 93, 110, 127, 145, 161, 176, 189, 201, 211, 218, 223, 226, 226, 223, 218, 211, 203, 192, 181, 168, 155, 141, 128, 114, 102, 91, 81, 72, 65, 60, 57, 55, 56, 58, 62, 67, 73, 81, 90, 99, 108, 118, 127, 137, 145, 153, 160, 166, 171, 175, 177, 178, 178, 177, 174, 171, 166, 161, 155, 148, 142, 135, 128, 121, 114, 108, 102, 97, 93, 89, 87, 86, 85, 86, 87, 89, 93, 97, 102, 108, 114, 121, 127, 135, 142, 148, 155, 161, 166, 171, 174, 177, 178, 178, 177, 175, 171, 166, 160, 153, 145, 137, 128, 118, 108, 99, 90, 81, 73, 67, 62, 58, 56, 55, 57, 60, 65, 72, 81, 91, 102, 114}, "Onda AM\n"};

waveform *waveform_get(int waveform) {
    switch(waveform) {
    case SINE:
        return &sine;
        break;
    case TRIANGLE:
        return &triangle;
        break;
    case SAWTOOTH:
        return &sawtooth;
        break;
    case AM:
        return &am;
        break;
    default:
        return NULL;
        break;
    }
}