#ifndef ENCODER_H
#define ENCODER_H

#include "pico/stdlib.h"
#include <stdbool.h>

// Struct for one encoder
typedef struct {
    uint8_t pinA;
    uint8_t pinB;

    uint8_t lastA;

    uint32_t value;
    bool updated;
} Encoder;

void encoder_init(Encoder *enc, uint8_t pinA, uint8_t pinB);
void encoder_update(Encoder *enc);

#endif
