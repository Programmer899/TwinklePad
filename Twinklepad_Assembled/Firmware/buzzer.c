#include "buzzer.h"
#include "hardware/pwm.h"
#include "pico/stdlib.h"

#define BUZZER_PIN 18

#define NOTE_C4 262
#define NOTE_D4 294
#define NOTE_E4 330
#define NOTE_F4 349
#define NOTE_G4 392
#define NOTE_A4 440
#define NOTE_B4 494

static uint slice;

void buzzer_init() {
    gpio_set_function(BUZZER_PIN, GPIO_FUNC_PWM);
    slice = pwm_gpio_to_slice_num(BUZZER_PIN);

    pwm_set_enabled(slice, true);
}

void buzzer_play_freq(uint freq) {
    if (freq == 0) {
        pwm_set_gpio_level(BUZZER_PIN, 0);
        return;
    }

    uint32_t clock = 125000000; // 125 MHz
    uint32_t divider = 100;
    uint32_t top = clock / (divider * freq);

    pwm_set_clkdiv(slice, divider);
    pwm_set_wrap(slice, top);
    pwm_set_gpio_level(BUZZER_PIN, top / 2); // 50% duty
}

void buzzer_stop() {
    pwm_set_gpio_level(BUZZER_PIN, 0);
}
