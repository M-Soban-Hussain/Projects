#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <SPI.h>
#include <MFRC522.h>

// LCD setup
LiquidCrystal_I2C lcd(0x27, 20, 4);

// RC522 setup
#define SS_PIN   5
#define RST_PIN  4
#define SCK_PIN  18
#define MOSI_PIN 13
#define MISO_PIN 12

MFRC522 mfrc522(SS_PIN, RST_PIN);

// Predefined UID
String allowedUID = "D155A14B"; // Replace with actual UID in uppercase

void setup() {
  Wire.begin(15, 16); // SDA, SCL
  lcd.init();
  lcd.backlight();
  lcd.setCursor(3, 1);
  lcd.print("Welcome...");
  delay(1000);
  lcd.clear();
  lcd.setCursor(1, 1);
  lcd.print("Scan your RFID card");

  Serial.begin(9600);  // Match baud rate with LCD compatibility
  SPI.begin(SCK_PIN, MISO_PIN, MOSI_PIN, SS_PIN);
  mfrc522.PCD_Init();
}

void loop() {
  if (!mfrc522.PICC_IsNewCardPresent() || !mfrc522.PICC_ReadCardSerial()) return;

  String uidStr = "";
  for (byte i = 0; i < mfrc522.uid.size; i++) {
    if (mfrc522.uid.uidByte[i] < 0x10) uidStr += "0";
    uidStr += String(mfrc522.uid.uidByte[i], HEX);
  }
  uidStr.toUpperCase();

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("UID: ");
  lcd.print(uidStr);

  if (uidStr == allowedUID) {
    lcd.setCursor(0, 2);
    lcd.print("Access Granted");
  } else {
    lcd.setCursor(0, 2);
    lcd.print("Access Denied");
  }

  Serial.print("UID: ");
  Serial.println(uidStr);

  mfrc522.PICC_HaltA();
  mfrc522.PCD_StopCrypto1();
  delay(2000);
  lcd.clear();
  lcd.setCursor(1, 1);
  lcd.print("Scan your RFID card");
}
