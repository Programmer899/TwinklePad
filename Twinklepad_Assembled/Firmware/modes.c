#include "modes.h"
#include "hardware/gpio.h"
//#include "tusb.h"

#define PIN_LEFT 20
#define PIN_RIGHT 21

void modes_init() {
    gpio_init(PIN_LEFT);
    gpio_set_dir(PIN_LEFT, GPIO_IN);
    gpio_pull_down(PIN_LEFT);

    gpio_init(PIN_RIGHT);
    gpio_set_dir(PIN_RIGHT, GPIO_IN);
    gpio_pull_down(PIN_RIGHT);
}

uint8_t modes_get() {
    if (gpio_get(PIN_LEFT)) return MODE_MUSIC;
    if (gpio_get(PIN_RIGHT)) return MODE_CALC;
    return MODE_NORMAL;
}

static const uint8_t keymaps[3][5][4] = {
    // NORMAL
    // {
    //     {0}, // Only encoders
    //     {HID_KEY_Q, HID_KEY_W, HID_KEY_E, HID_KEY_R},
    //     {HID_KEY_A, HID_KEY_S, HID_KEY_D, HID_KEY_F},
    //     {HID_KEY_Z, HID_KEY_X, HID_KEY_C, HID_KEY_V},
    //     {HID_KEY_1, HID_KEY_2, HID_KEY_3, HID_KEY_4}
    // },
    {0},

    // MUSIC (unused here)
    {0},

    // CALC
    // {
    //     {0}, // Only encoders
    //     {HID_KEY_KP_1, HID_KEY_KP_2, HID_KEY_KP_3, 0},
    //     {HID_KEY_KP_4, HID_KEY_KP_5, HID_KEY_KP_6, 0},
    //     {HID_KEY_KP_7, HID_KEY_KP_8, HID_KEY_KP_9, 0},
    //     {0}
    // }
    {0}
};

uint8_t keymap_get(uint8_t mode, uint8_t row, uint8_t col) {
    return keymaps[mode][row][col];
}
