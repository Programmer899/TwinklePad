# HackPad

A compact, custom-built macro keypad powered by the Raspberry Pi Pico W.  
Designed for flexibility, HackPad combines a 4x4 key matrix, rotary encoders, RGB lighting, and a small OLED display into a multi-mode input device.

---

## ✨ Features

- 🔢 **4x4 Mechanical Key Matrix**  
  Customizable inputs for macros, shortcuts, or tools

- 🎛️ **Dual Rotary Encoders**  
  Smooth control for volume, navigation, or parameter tuning

- 🌈 **Per-Key RGB (SK6812)**  
  Individually addressable lighting for feedback and effects

- 🖥️ **128x32 OLED Display**  
  Displays current mode and system status

- 🔊 **Piezo Buzzer**  
  Audio feedback and simple tone generation

- 🔌 **USB HID Support (TinyUSB)**  
  Acts as a keyboard or macro pad when connected to a computer

---

## 🎮 Modes

HackPad includes multiple operating modes, switchable via a hardware toggle:

- **Normal Mode**  
  Standard macro pad behavior (keyboard shortcuts, commands)

- **Music Mode**  
  Keys act as notes (C, D, E, etc.) with sound output via piezo

- **Calc Mode**  
  Intended for calculator-style input and numeric operations

The current mode is shown on the OLED display.

---

## 🧠 Firmware Overview

The firmware is written in C using the Pico SDK and is structured into modular components:

- `matrix` – Key scanning and input handling  
- `encoder` – Rotary encoder processing  
- `display` – OLED rendering (mode + UI)  
- `rgb` – LED control  
- `usb` – HID communication via TinyUSB  

---

## 🛠️ Hardware

- Raspberry Pi Pico W  
- 4x4 MX-style switches  
- 2× Rotary encoders (with push buttons)  
- SK6812 Mini-E LEDs  
- SSD1306 128x32 OLED  
- Piezo buzzer  
- 3-position mode switch  

---

## 📷 Preview

![HackPad Preview](assets/Clean_TwinklePad_V8.png)

---

## 🚀 Getting Started

1. Build with Pico SDK (CMake + Ninja)
2. Flash the `.uf2` file to the Pico
3. Connect via USB and start using HackPad

---

## 📌 Notes

This is a custom project and may evolve over time.  
Feel free to modify firmware and hardware to suit your needs.
