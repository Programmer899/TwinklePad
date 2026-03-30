#include "rgb.h"
#include "hardware/pio.h"
#include "ws2812.pio.h"

#define RGB_PIN 15
#define NUM_LEDS 16

static PIO pio = pio0;
static int sm = 0;

static inline void put_pixel(uint32_t pixel_grb) {
    pio_sm_put_blocking(pio, sm, pixel_grb << 8u);
}

static inline uint32_t urgb(uint8_t r, uint8_t g, uint8_t b) {
    return ((uint32_t)g << 16) |
           ((uint32_t)r << 8) |
           (uint32_t)b;
}

void rgb_init() {
    uint offset = pio_add_program(pio, &ws2812_program);
    ws2812_program_init(pio, sm, offset, RGB_PIN, 800000, false);
}

void rgb_update(int mode) {
    uint32_t color;

    switch (mode) {
        case 0: color = urgb(0, 0, 50); break;
        case 1: color = urgb(50, 0, 50); break;
        case 2: color = urgb(0, 50, 0); break;
        default: color = urgb(10, 10, 10);
    }

    for (int i = 0; i < NUM_LEDS; i++) {
        put_pixel(color);
    }
}
