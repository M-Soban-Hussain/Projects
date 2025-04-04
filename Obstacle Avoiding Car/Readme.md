# 🚗 Obstacle Avoiding Car 🤖

An Arduino-powered robot car that senses and avoids obstacles all by itself! This is a beginner-friendly robotics project that’s both fun and educational.  

---

## 🔧 Components Used

- 🧠 **Arduino Uno**  
- ⚙️ **L298N Motor Driver Module**  
- 🌊 **HC-SR04 Ultrasonic Sensor**  
- 🔩 **2 Gear Motors**  
- 🔌 **Lots of Jumper Wires**  
- 🔋 **Two 9V Batteries**  

---

## 📷 Circuit Diagram

A neat and easy-to-follow **circuit diagram** is included in this repo to help you connect everything the right way! 🧾🛠️

---

## 🛠️ Step-by-Step Assembly

### 1. 🔋 Power Setup
- Connect **2× 9V batteries in series**
- Connect their **+ve** to the **12V pin** of the motor driver
- Connect their **-ve** to the **GND** pin of the motor driver

### 2. 🔗 Common Ground
- Short the **GND of the Arduino** with the **GND of the Motor Driver**  
✅ **This step is crucial for proper communication!**

### 3. ⚙️ Motor Connections
- Connect both motors to the motor driver:
  - Motor wires → **+ve to +ve**, **-ve to -ve**

### 4. 🎮 Control Pins
- Connect the **IN1–IN4 pins** of the motor driver to Arduino:
  - IN1 → D7  
  - IN2 → D6  
  - IN3 → D5  
  - IN4 → D4  

### 5. 📡 Sensor Wiring
- VCC → Arduino 5V  
- GND → Arduino GND  
- TRIG → D9  
- ECHO → D8  

### 6. 🧠 Motor Driver Enable Pins
- Don’t forget to **short both ENA pins together**  
- Also short the **two ENB pins together**  
📌 (This enables both channels of the motor driver)

---

## 🧪 How It Works

- The ultrasonic sensor continuously measures the distance ahead  
- If an obstacle is detected, the car:
  - **Stops ➡ Reverses ➡ Turns ➡ Moves Forward again**  
- All this is done automatically based on sensor feedback

---

## 🖥️ Code

Upload the Arduino sketch in this repo to your board. It handles:
- Sensor input  
- Decision-making  
- Motor control

---

## 📦 Final Notes

- Make sure all grounds are connected  
- Double-check wiring before powering on  
- Have fun watching your robot dodge stuff like a pro! 😎

---
