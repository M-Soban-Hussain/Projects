
---

# Arduino GPS Location Tracker

This project uses **Arduino UNO** and **NEO-6M GPS module** to track real-time GPS location. The code is written in **Arduino IDE**.

## Features

* Real-time GPS location tracking
* Data output on Serial Monitor
* Screenshot of location output (blurred for privacy)
* Complete circuit diagram included

## Components Used

* Arduino UNO
* NEO-6M GPS Module
* Jumper wires
* USB cable

## Circuit Connections

| NEO-6M GPS Pin | Arduino UNO Pin |
| -------------- | --------------- |
| GND            | GND             |
| VCC            | 5V              |
| TX             | 8               |
| RX             | 9               |

## Folder Contents

* `code/` — Arduino code
* `circuit_diagram/` — Circuit wiring image
* `serial_monitor/` — Screenshot of Serial Monitor output
* `GPSNEO6M_Library/` — GPS library for Arduino IDE

## Note

* Location data is blurred for privacy.
* Add the `GPSNEO6M_Library` to your Arduino IDE before uploading the code.
* Visit https://www.youtube.com/watch?v=GYYpqHZIG1A for Detailed Video.

---
