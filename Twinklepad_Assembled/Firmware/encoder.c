#include "encoder.h"
#include "pico/stdlib.h"

void encoder_init(Encoder *enc, uint8_t pinA, uint8_t pinB) {
  enc->pinA = pinA;
  enc->pinB = pinB;

  gpio_init(pinA);
  gpio_set_dir(pinA, GPIO_IN);
  gpio_pull_up(pinA);

  gpio_init(pinB);
  gpio_set_dir(pinB, GPIO_IN);
  gpio_pull_up(pinB);

  enc->lastA = gpio_get(pinA);
  enc->value = 0;
  enc->updated = 0;
}

void encoder_update(Encoder *enc) {
  uint8_t A = gpio_get(enc->pinA);
  uint8_t B = gpio_get(enc->pinB);

  // Only trigger on rising edge
  if (A != enc->lastA && A == 1) {
    enc->updated++;

    if (B != A) {
      enc->value--;   // counter-clockwise
    } else {
      enc->value++;   // clockwise
    }
  }

  enc->lastA = A;
}
