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

  lcd.setCursor(0, 0);
  writeBlocks(3); lcd.print("              "); writeBlocks(3);

  lcd.setCursor(3, 1);
  writeBlocks(3); lcd.print("        "); writeBlocks(3);

  lcd.setCursor(5, 2);
  writeBlocks(3); lcd.print("    "); writeBlocks(3);

  lcd.setCursor(5, 3);
  writeBlocks(3); lcd.print("    "); writeBlocks(3);
}

void loop() {}
