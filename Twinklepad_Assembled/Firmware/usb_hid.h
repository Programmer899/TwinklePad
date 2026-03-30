#pragma once
#include <stdint.h>

void usb_hid_init();
void usb_hid_send(uint8_t *keys);
