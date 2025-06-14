#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 20, 4);

byte fullBlock[8] = {0b11111,0b11111,0b11111,0b11111,0b11111,0b11111,0b11111,0b11111};

void writeBlocks(int count) {
  for (int i = 0; i < count; i++) lcd.write(0);
}

void setup() {
  Wire.begin(16, 17);  
  lcd.init();
  lcd.backlight();
  lcd.createChar(0, fullBlock);

  lcd.setCursor(0, 1);
  writeBlocks(9); lcd.print("  "); writeBlocks(9);

  lcd.setCursor(0, 2);
  writeBlocks(9); lcd.print("  "); writeBlocks(9);
}

void loop() {}
