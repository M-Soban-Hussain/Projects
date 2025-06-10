# 🔐 RFID + Fingerprint Access System using ESP32

A complete access system using **ESP32**, **Fingerprint Sensor**, **RFID**, **4x4 Keypad**, **Buzzer**, and **I2C LCD**.

---

## 📌 See Circuit Diagram

All hardware connections are shown in the provided **circuit diagram**.

---

## ⚙️ Working

- 🔢 **S1–S9** → Numbers 1 to 9  
- 🔟 **S10** → Number 0  
- ⬅️ **S11** → "Previous" (navigate FP ID list)  
- ➡️ **S12** → "Next" (navigate FP ID list)  
- ⌫ **S13** → Backspace  
- 📝 **S14** → Start Fingerprint Enrollment  
- 📃 **S15** → Show Fingerprint ID list  
- 🗑️ **S16** → Delete **all** stored Fingerprint IDs  

---

## 🧠 Notes

- RFID tag checking is supported ✅  
- To add your own RFID tags ➡️ replace them in the code (no enrollment needed)  
- Fingerprint **enrollment** is supported via button **S14** only  
- Currently, **RFID has no enrollment** functionality
