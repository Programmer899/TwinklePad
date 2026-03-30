#pragma once
#include <stdint.h>

typedef enum {
    MODE_MUSIC = 0,
    MODE_NORMAL = 1,
    MODE_CALC = 2
} Mode;

void modes_init();
Mode modes_get();

uint8_t keymap_get(uint8_t mode, uint8_t row, uint8_t col);
