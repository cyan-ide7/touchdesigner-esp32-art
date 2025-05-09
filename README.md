﻿# 🔥 Real-Time Fire Particle Art with ESP32 & TouchDesigner

This project blends **interactive art** with **physical computing**, using an **ESP32**, **ultrasonic sensor**, **sound sensor**, and **TouchDesigner** to control a dynamic fire particle system.

---

## 🎨 Features

- 🔊 Fire intensity increases with **sound volume**
- 📏 Fire direction shifts based on **distance measured**
- ⚡ Real-time sensor input over **Serial (COM3, 115200 baud)**

---

## 🛠️ Hardware Used

- 🧠 [ESP32 Dev Board](https://www.espressif.com/en/products/socs/esp32)
- 🎤 Sound Sensor (Analog Output)
- 📏 Ultrasonic Sensor (HC-SR04)
- 🔌 USB to Serial Connection (COM3)
- 🧰 [CP210x USB to UART Bridge VCP Drivers](https://www.silabs.com/developer-tools/usb-to-uart-bridge-vcp-drivers) (install for Windows if COM3 isn't detected)

---

## 🖥️ Software Used

- 🎛️ [TouchDesigner](https://derivative.ca/)
- 🧪 Arduino IDE with ESP32 board support

---

## 🔧 How It Works

1. **ESP32** reads:
   - 📏 Distance from the HC-SR04 ultrasonic sensor
   - 🔊 Sound level from the analog sound sensor

2. The ESP32 sends this over serial in this format:
Distance (cm): 123 | Sound Level: 89


3. **TouchDesigner** reads the data using a Serial DAT and maps:
- **Distance** → particle direction
- **Sound Level** → fire intensity

---

## 🔌 Connections & Setup

### 🔧 ESP32 to Ultrasonic Sensor (HC-SR04)

| HC-SR04 Pin | ESP32 Pin     |
|-------------|---------------|
| VCC         | 3.3V or 5V     |
| GND         | GND           |
| TRIG        | GPIO 5        |
| ECHO        | GPIO 18       |

---

### 🎤 ESP32 to Sound Sensor

| Sound Sensor Pin | ESP32 Pin     |
|------------------|---------------|
| VCC              | 3.3V or 5V     |
| GND              | GND           |
| OUT              | GPIO 34 (ADC) |

> ⚠️ Use an **analog output** sound sensor for better volume sensitivity.

---

### 💻 ESP32 to PC

- Connect ESP32 using a USB cable.
- If it's not detected, install [Silicon Labs CP210x drivers](https://www.silabs.com/developer-tools/usb-to-uart-bridge-vcp-drivers).

---

### 🧪 TouchDesigner Serial Setup

In **TouchDesigner**:
1. Add a **Serial DAT**
2. Set the following:
- **Port**: `COM3` (or your detected port)
- **Baud Rate**: `115200`
- **Parity**: `None`
- **Data Bits**: `8`
- **Stop Bits**: `1`

---

you can change the sensor intraction from the point to transform node 



MIT License – feel free to remix and build upon it

