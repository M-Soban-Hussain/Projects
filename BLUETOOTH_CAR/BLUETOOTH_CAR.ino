#include <Wire.h>
#include <hd44780.h>
#include <hd44780ioClass/hd44780_I2Cexp.h>

hd44780_I2Cexp lcd;

void setup() {
  Wire.begin(16, 17);   // SDA=16, SCL=17
  lcd.begin(16, 2);     // auto-detects address & chip
  lcd.backlight();
  lcd.setCursor(0,0);
  lcd.print("Hello World!");
  lcd.setCursor(0,1);
  lcd.print("ESP32 + LCD");
}

void loop() {}
