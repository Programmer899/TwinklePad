#pragma once
#include <stdint.h>

void matrix_init();
void matrix_scan();

void matrix_get_keys(uint8_t *out, uint8_t mode);
uint16_t matrix_get_note();
