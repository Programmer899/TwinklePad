#include <stdio.h>
#include "pico/stdlib.h"

#include "matrix.h"
#include "usb_hid.h"
#include "modes.h"
#include "rgb.h"
#include "buzzer.h"
#include "display.h"
#include "encoder.h"

Mode current_mode = MODE_NORMAL;
uint8_t lastMode;

Encoder encLeft;
Encoder encRight;

int main() {
  stdio_init_all();

  matrix_init();
  usb_hid_init();
  modes_init();
  rgb_init();
  buzzer_init();
  display_init();

  encoder_init(&encLeft, 13, 14);
  encoder_init(&encRight, 11, 12);

  uint8_t mode = modes_get();
  rgb_update(mode);
  display_update(mode);

  while (true) {
    //tud_task();

    matrix_scan();

    uint8_t mode = modes_get();

    encoder_update(&encLeft);
    encoder_update(&encRight);

    if (encLeft.updated) {
      printf("Left encoder: %d\n", encLeft.value);
      encLeft.updated = 0;
    }

    if (encRight.updated) {
      printf("Right encoder: %d\n", encRight.value);
      encRight.updated = 0;
    }

    // Only execute if switched mode
    if (lastMode != mode) {
      lastMode = mode;
      rgb_update(mode);
      display_update(mode);
      buzzer_stop();
    }

    if (mode == MODE_MUSIC) {
      int note = matrix_get_note();

      if (note > 0) {
        buzzer_play_freq(note * ((float)encLeft.value / (float)100));
      } else {
        buzzer_stop();
      }
    } else {
      uint8_t keys[6];
      matrix_get_keys(keys, mode);
      usb_hid_send(keys);
    }
    // sleep_ms(1);
    sleep_us(500);
  }
}
