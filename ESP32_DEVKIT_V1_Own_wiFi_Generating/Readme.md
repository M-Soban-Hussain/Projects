# 🛠️ ESP32 WiFi Setup & Driver Installation Guide 🌐

This repository contains the code and drivers for setting up your **ESP32 Devkit V1** to create a WiFi access point with a password. It also includes a **Windows driver** to ensure your ESP32 is detected by your system and recognized by the **Arduino IDE**. 📡

---

## 📂 Contents

- **ESP32_WiFi_Code**: Code for configuring the ESP32 as a WiFi access point. 🔑📶
- **Windows_Driver**: Driver to help Windows recognize your ESP32 if it doesn't show up by default. 💻🔧

---

## 🚀 How to Use

### 1. **Upload Code to ESP32** 📤

- Open **ESP32_WiFi_Code** in the **Arduino IDE**.
- Upload the code to your **ESP32 Devkit V1**.
- Once uploaded, your ESP32 will create a WiFi network with the credentials set in the code. 🌐

### 2. **Install Driver on Windows** 🖥️

If your ESP32 is **not detected** in **Device Manager** or the **Arduino IDE**, follow these steps to install the necessary driver:

1. Open **Device Manager**.
2. Right-click the unrecognized **ESP32 device**.
3. Select **Update Driver**.
4. Choose **Browse my computer for driver software**.
5. Select the folder containing **Windows_Driver**.
6. Complete the installation by following the on-screen instructions. ✅

After installation, your ESP32 should now appear in the **Arduino IDE**. 🎉

---

## 📌 Quick Recap:
- **Code**: ESP32 creates its own WiFi network. 🌐
- **Driver**: Resolves detection issues on Windows. 💻
- **Procedure**: Simple upload + driver installation. 🔧

---

### ⚡️ Happy Coding! 🎉
