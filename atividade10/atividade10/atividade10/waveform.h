/**
 * EA871 T
 * Atividade10 - Síntese de formas de onda via PWM
 *
 * Alifer Willians de Moraes
 * RA: 165334
 *
 * Description
 */

#ifndef WAVEFORM_H
#define WAVEFORM_H

#include <stdint.h>

#define NONE        0
#define SINE        1
#define TRIANGLE    2
#define SAWTOOTH    3
#define AM          4

#define TRUE        1

typedef struct waveform {
    uint8_t *waveform;
    uint8_t *message;
    uint16_t delay;
} Waveform;

void waveform_get(int wf, Waveform *waveform);

#endif /* WAVEFORM_H */