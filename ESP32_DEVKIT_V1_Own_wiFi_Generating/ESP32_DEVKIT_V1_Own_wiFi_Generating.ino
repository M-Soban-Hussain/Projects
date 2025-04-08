#include <WiFi.h>

void setup() {
  Serial.begin(115200);
  WiFi.softAP("ESP32_AP", "12345678");  // SSID, Password
  Serial.println("Access Point Started");
  Serial.println(WiFi.softAPIP());
}

void loop() {
  // Nothing
}
