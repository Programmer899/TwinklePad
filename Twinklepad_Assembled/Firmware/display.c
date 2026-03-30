#include "display.h"
#include "ssd1306.h"
#include "hardware/i2c.h"
#include "pico/stdlib.h"
#include <string.h>

#include "modes.h"

#define I2C_PORT i2c0
#define SDA_PIN 16
#define SCL_PIN 17

ssd1306_t disp;

void display_init() {
    i2c_init(I2C_PORT, 400000);

    gpio_set_function(SDA_PIN, GPIO_FUNC_I2C);
    gpio_set_function(SCL_PIN, GPIO_FUNC_I2C);

    gpio_pull_up(SDA_PIN);
    gpio_pull_up(SCL_PIN);

    ssd1306_init(&disp, 128, 32, 0x3C, I2C_PORT);

    ssd1306_clear(&disp);
    ssd1306_show(&disp);
}

static const char* mode_to_string(int mode) {
    switch (mode) {
        case MODE_NORMAL: return "NORMAL";
        case MODE_MUSIC:  return "MUSIC";
        case MODE_CALC:   return "CALC";
        default:          return "UNKNOWN";
    }
}

void display_update(int mode) {
    ssd1306_clear(&disp);

    // Title (small)
    ssd1306_draw_string(&disp, 0, 0, 1, "MODE:");

    // Big text (center-ish)
    const char* text = mode_to_string(mode);

    // crude centering for 128x32
    int x = (128 - strlen(text) * 6) / 2;
    int y = 16;

    ssd1306_draw_string(&disp, x, y, 2, text);

    ssd1306_show(&disp);
}
