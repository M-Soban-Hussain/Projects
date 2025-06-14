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

  lcd.setCursor(1, 0);
  writeBlocks(2); lcd.print("   "); writeBlocks(2);
  lcd.print("    ");
   writeBlocks(2); lcd.print("   "); writeBlocks(2);
  
  lcd.setCursor(0, 1);
  writeBlocks(4); lcd.print(" "); writeBlocks(4);
  lcd.print("  ");
  writeBlocks(4); lcd.print(" "); writeBlocks(4);

  lcd.setCursor(1, 2);
  writeBlocks(7);
  lcd.print("    ");
  writeBlocks(7);

  lcd.setCursor(3, 3);
  writeBlocks(3); lcd.print("        "); writeBlocks(3);
}

void loop() {}
