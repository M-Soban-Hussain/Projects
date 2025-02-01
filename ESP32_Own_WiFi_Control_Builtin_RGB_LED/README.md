---

### 🚀 **Steps to Set Up and Control Your ESP32**
---
1. **Download & Install Arduino IDE**  
   📥 Visit the official site and download the latest version:  
   [Arduino IDE Download](https://www.arduino.cc/en/software)  

2. **Install ESP32 Board**  
   🛠️ Open Arduino IDE. Go to:  
   **Tools > Board > Boards Manager**  
   🔍 Search for **ESP32 by Espressif** and install the latest version.

3. **Upload the Code**  
   📂 Upload the "main code" file from your folder to the **ESP32-S3-WROOM-1**.

4. **Check the Tools Menu**  
   🔧 Refer to the image for the changes made in the **Tools menu** in Arduino IDE.

5. **LED Pin Configuration**  
   💡 The code uses **LED_BUILTIN** (onboard LED).  
   If your ESP32 doesn't have an onboard LED or it's on a different pin, change it to:
   
   ```
   const int ledPin = 2;  // or your specific LED pin
   ```

7. **Connect to ESP32's WiFi Network**  
   🌐 The ESP32 creates a WiFi network:  
   **SSID**: ESP32-Access-Point  
   **Password**: 123456789

8. **Connect from Your Phone/Laptop**  
   📱💻 Connect to **ESP32-Access-Point** using the password.  
   Then, open a web browser and go to:
   
   `192.168.4.1`

10. **Control the LED**  
   🌟 You'll see two links on the webpage:  
   ➡️ **Turn LED ON**  
   ➡️ **Turn LED OFF**

   Clicking these links will control the LED on your ESP32.

---

### ✅ **That's it!**  
Have a great day! 🌞  
May Allah bless you. 🙏

--- 
