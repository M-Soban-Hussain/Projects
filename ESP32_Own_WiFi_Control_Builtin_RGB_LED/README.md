First, download and install the latest version of Arduino IDE from the official website by clicking here ->> https://www.arduino.cc/en/software.
Then, open Arduino IDE and go to Tools > Board > Boards Manager. Search for ESP32 by Espressif and install the latest version.
Upload the file named "main code" from the folder to the ESP32-S3-WROOM-1.
Also, refer to the provided image for the changes made in the Tools menu in Arduino IDE.
The code uses LED_BUILTIN, which refers to the onboard LED. 
On most ESP32 boards, this should work fine, but if your ESP32 doesn't have an onboard LED or it's connected to a different pin, you may need to change LED_BUILTIN to a specific pin, like:

const int ledPin = 2;  // or whatever pin your LED is connected to

The ESP32 creates a WiFi network with the SSID ESP32-Access-Point and password 123456789.
Ensure you're able to connect to this WiFi network from your phone or laptop.
After connecting your phone or laptop to the ESP32's WiFi network (ESP32-Access-Point with password 123456789), open a web browser and go to the IP address 192.168.4.1.
You should see a simple webpage with two links:

:> Turn LED ON
:> Turn LED OFF

licking on the links should control the LED on your ESP32 (turn it on/off).

Well, That's all!
Have a good day, May Allah Almighty bless you.
