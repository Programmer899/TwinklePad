#include <stdio.h>
#include "matrix.h"
#include "hardware/gpio.h"
#include "modes.h"

static const uint8_t rows[5] = {10, 9, 8, 7, 6};
static const uint8_t cols[4] = {5, 4, 3, 2};

static bool keys[5][4];

void matrix_init() {
  for (uint8_t r = 0; r < 5; r++) {
    gpio_init(rows[r]);
    gpio_set_dir(rows[r], GPIO_IN);
    gpio_pull_down(rows[r]);
  }

  for (uint8_t c = 0; c < 4; c++) {
    gpio_init(cols[c]);
    gpio_set_dir(cols[c], GPIO_OUT);
  }
}

void matrix_scan() {
  for (uint8_t c = 0; c < 4; c++) {
    gpio_put(cols[c], 1);

    for (uint8_t r = 0; r < 5; r++) {
      keys[r][c] = gpio_get(rows[r]);
    }

    gpio_put(cols[c], 0);
  }
}

extern uint8_t keymap_get(uint8_t mode, uint8_t r, uint8_t c);

void matrix_get_keys(uint8_t *out, uint8_t mode) {
  uint8_t idx = 0;

  for (uint8_t c = 0; c < 4; c++) {
    for (uint8_t r = 0; r < 5; r++) {
      if (keys[r] && idx < 6) {
        out[idx++] = keymap_get(mode, r, c);
      }
    }
  }

  while (idx < 6) out[idx++] = 0;
}

uint16_t matrix_get_note() {
  static const uint16_t notes[5][4] = {
    {0, 0, 0, 0}, // Only encoders
    {262, 294, 330, 349},
    {392, 440, 494, 523},
    {0, 0, 0, 0},
    {0, 0, 0, 0}
  };

  for (uint8_t c = 0; c < 4; c++) {
    for (uint8_t r = 0; r < 5; r++) {
      if (keys[r][c]) return notes[r][c];
    }
  }

  return 0;
}
