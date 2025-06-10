#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <Adafruit_Fingerprint.h>
#include <SPI.h>
#include <MFRC522.h>
#include <vector>
#include <algorithm>

std::vector<int> enrolledIDs;
bool showFPIDList = false;
int fpidPage = 0;
unsigned long fpidShowTime = 0;

#define LCD_ADDRESS 0x27
LiquidCrystal_I2C lcd(LCD_ADDRESS, 20, 4);

// Fingerprint
HardwareSerial mySerial(2); // UART2
Adafruit_Fingerprint finger(&mySerial);

// RFID
#define SS_PIN 5
#define RST_PIN 4
MFRC522 rfid(SS_PIN, RST_PIN);

// Buzzer
#define BUZZER_PIN 14

// Button matrix GPIOs
const int rowPins[4] = {41, 42, 2, 1}; // R1 to R4
const int colPins[4] = {40, 39, 38, 37}; // C1 to C4

// Button states
bool buttonPressed[16] = {false};

// Globals for input and mode
String inputStr = "";
bool enrollMode = false;

// Inactivity timeout
unsigned long lastInputTime = 0;
const unsigned long inputTimeout = 10000; // 10 seconds
bool inputActive = false;

// FPID display constants
const int FPIDsPerPage = 30; // approximate number per 3 lines (comma separated)

void setup() {
  Serial.begin(115200);
  Wire.begin(15, 16); // SDA, SCL
  lcd.init();
  lcd.backlight();
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Initializing...");
  pinMode(BUZZER_PIN, OUTPUT);
  
    digitalWrite(BUZZER_PIN, HIGH);
    delay(100);
    digitalWrite(BUZZER_PIN, LOW);
    delay(150);
    digitalWrite(BUZZER_PIN, HIGH);
    delay(100);
    digitalWrite(BUZZER_PIN, LOW);
    delay(150);
    digitalWrite(BUZZER_PIN, HIGH);
    delay(350);
    digitalWrite(BUZZER_PIN, LOW);
    
  for (int i = 0; i < 4; i++) {
    pinMode(rowPins[i], OUTPUT);
    digitalWrite(rowPins[i], HIGH);
  }
  for (int i = 0; i < 4; i++) {
    pinMode(colPins[i], INPUT_PULLUP);
  }

  mySerial.begin(57600, SERIAL_8N1, 20, 21);
  finger.begin(57600);
  if (finger.verifyPassword()) {
    Serial.println("FP Ready");
    lcd.setCursor(0, 1);
    lcd.print("FP Ready");
  } else {
    Serial.println("FP FAIL");
    lcd.setCursor(0, 1);
    lcd.print("FP FAIL");
  }
  
  loadEnrolledFPIDs();
  
  SPI.begin(18, 12, 13, 5);
  rfid.PCD_Init();
  Serial.println("RFID Ready");
  lcd.setCursor(0, 2);
  lcd.print("RFID Ready");
  delay(1500);
  showIdleMenu();
}

void loop() {
  readButtons();

  if (showFPIDList) {
    if (millis() - fpidShowTime > 10000) {
      showFPIDList = false;
      showIdleMenu();
    }
  } else {
    if (!enrollMode) {
      checkFingerprint();
      checkRFID();
    }

    if (inputActive && (millis() - lastInputTime > inputTimeout)) {
      inputStr = "";
      inputActive = false;
      lcd.clear();
      showIdleMenu();
    }
  }
}
void loadEnrolledFPIDs() {
  enrolledIDs.clear();
  for (int id = 1; id <= 127; id++) {
    int p = finger.loadModel(id);
    if (p == FINGERPRINT_OK) {
      enrolledIDs.push_back(id);
    }
  }
}

void showIdleMenu() {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("+------------------+");
  lcd.setCursor(0, 1);
  lcd.print("|  SYSTEM STANDBY  |");
  lcd.setCursor(0, 2);
  lcd.print("|    READY...      |");
  lcd.setCursor(0, 3);
  lcd.print("+------------------+");
}

void readButtons() {
  for (int r = 0; r < 4; r++) {
    digitalWrite(rowPins[r], LOW);
    for (int c = 0; c < 4; c++) {
      int buttonIndex = r * 4 + c;
      bool pressed = digitalRead(colPins[c]) == LOW;
      if (pressed && !buttonPressed[buttonIndex]) {
        buttonPressed[buttonIndex] = true;
        handleButton(buttonIndex + 1); // Buttons numbered 1 to 16
      }
      if (!pressed) buttonPressed[buttonIndex] = false;
    }
    digitalWrite(rowPins[r], HIGH);
  }
}

void handleButton(int btn) {
  if (enrollMode) return;

  if (showFPIDList) {
    // Pagination controls
    if (btn == 12) { // S12 = Next page
      int maxPage = (enrolledIDs.size() + FPIDsPerPage - 1) / FPIDsPerPage - 1;
      if (fpidPage < maxPage) fpidPage++;
      displayFPIDPage();
      fpidShowTime = millis();
      return;
    } else if (btn == 11) { // S11 = Previous page
      if (fpidPage > 0) fpidPage--;
      displayFPIDPage();
      fpidShowTime = millis();
      return;
    }
  }

  if (btn >= 1 && btn <= 9) {
    inputStr += String(btn);
    updateLCDInput();
    lastInputTime = millis();
    inputActive = true;
  } else if (btn == 10) {
    inputStr += "0";
    updateLCDInput();
    lastInputTime = millis();
    inputActive = true;
  } else if (btn == 13) {
    if (inputStr.length() > 0) {
      inputStr.remove(inputStr.length() - 1);
      updateLCDInput();
      lastInputTime = millis();
    }
  } else if (btn == 14) {
    if (inputStr.length() == 0) {
      lcd.clear();
      lcd.print("Enter ID first");
      delay(1500);
      updateLCDInput();
    } else {
      enrollMode = true;
      enrollFingerprint(inputStr.toInt());
      inputStr = "";
      enrollMode = false;
      lcd.clear();
      showIdleMenu();
      inputActive = false;
    }
  } else if (btn == 15) { // Show FPID list
    if (enrolledIDs.size() == 0) {
      lcd.clear();
      lcd.print("No FPIDs found");
      delay(1500);
      showIdleMenu();
      return;
    }
    showFPIDList = true;
    fpidPage = 0;
    displayFPIDPage();
    fpidShowTime = millis();
  } else if (btn == 16) {
  for (int i = 1; i <= 127; i++) {
    finger.deleteModel(i);
  }
  enrolledIDs.clear();
  lcd.clear();
  lcd.print("All FPIDs Deleted");
  buzz();
  delay(2000);
  showIdleMenu();
  }
}

void updateLCDInput() {
  lcd.clear();
  lcd.print("Input: ");
  lcd.print(inputStr);
}

void enrollFingerprint(int id) {
  int p;
  lcd.clear();
  lcd.print("Enroll ID:");
  lcd.print(id);
  delay(1000);

  // Step 1
  lcd.clear();
  lcd.print("Step 1:");
  lcd.setCursor(0, 1);
  lcd.print("Place finger");
  buzz();

  while (true) {
    p = finger.getImage();
    if (p == FINGERPRINT_OK) break;
    else if (p == FINGERPRINT_NOFINGER) continue;
    else {
      modelError();
      return;
    }
  }

  p = finger.image2Tz(1);
  if (p != FINGERPRINT_OK) {
    modelError();
    return;
  }

  lcd.clear();
  lcd.print("Remove finger");
  delay(2000);

  // Step 2
  lcd.clear();
  lcd.print("Step 2:");
  lcd.setCursor(0, 1);
  lcd.print("Place finger again");
  buzz();

  while (true) {
    p = finger.getImage();
    if (p == FINGERPRINT_OK) break;
    else if (p == FINGERPRINT_NOFINGER) continue;
    else {
      modelError();
      return;
    }
  }

  p = finger.image2Tz(2);
  if (p != FINGERPRINT_OK) {
    modelError();
    return;
  }

  int st = finger.createModel();
  if (st != FINGERPRINT_OK) {
    lcd.clear();
    lcd.print("Model Error");
    delay(2000);
    return;
  }

  st = finger.storeModel(id);
  if (st == FINGERPRINT_OK) {
    lcd.clear();
    lcd.print("Stored ID: ");
    lcd.print(id);
    buzz();
    delay(2000);

    // Add to enrolledIDs vector if not already present
    if (std::find(enrolledIDs.begin(), enrolledIDs.end(), id) == enrolledIDs.end()) {
      enrolledIDs.push_back(id);
    }
  } else {
    lcd.clear();
    lcd.print("Store Failed");
    delay(2000);
  }
}

void checkFingerprint() {
  int p = finger.getImage();
  if (p != FINGERPRINT_OK) return;
  p = finger.image2Tz();
  if (p != FINGERPRINT_OK) return;
  p = finger.fingerSearch();
  if (p != FINGERPRINT_OK) {
    lcd.clear();
    lcd.print("Fingerprint");
    lcd.setCursor(0, 1);
    lcd.print("Access Denied");
    delay(2000);
    return;
  }

  int id = finger.fingerID;
  int conf = finger.confidence;

  lcd.clear();
  lcd.print("FP ID: ");
  lcd.print(id);
  lcd.setCursor(0, 1);
  lcd.print("Match: ");
  lcd.print(conf);
  lcd.print("%");
  lcd.setCursor(0, 2);
  lcd.print("Access Approved");

  buzz();
  delay(3000);
  showIdleMenu();
}

void checkRFID() {
  if (!rfid.PICC_IsNewCardPresent() || !rfid.PICC_ReadCardSerial()) return;

  String uid = "";
  for (byte i = 0; i < rfid.uid.size; i++) {
    uid += String(rfid.uid.uidByte[i] < 0x10 ? "0" : "");
    uid += String(rfid.uid.uidByte[i], HEX);
  }
  uid.toUpperCase();

  lcd.clear();
  lcd.print("Card UID:");
  lcd.setCursor(0, 1);
  lcd.print(uid);

  if (uid == "52917E53" || uid == "10288E11" || uid == "D1AE9B0D" || uid == "E03EDB10") {
    lcd.setCursor(0, 2);
    lcd.print("Access Approved");
    buzz();
  } else {
    lcd.setCursor(0, 2);
    lcd.print("Access Denied");
  }

  delay(3000);
  showIdleMenu();
  rfid.PICC_HaltA();
}

void buzz() {
  digitalWrite(BUZZER_PIN, HIGH);
  delay(200);
  digitalWrite(BUZZER_PIN, LOW);
}

void modelError() {
  lcd.clear();
  lcd.print("Model error");
  delay(2000);
  lcd.clear();
}

void displayFPIDPage() {
  lcd.clear();
  lcd.print("FPIDs Page ");
  lcd.print(fpidPage + 1);

  int startIdx = fpidPage * FPIDsPerPage;
  int endIdx = std::min(startIdx + FPIDsPerPage, (int)enrolledIDs.size());
  String line = "";
  int lineNum = 1;

  for (int i = startIdx; i < endIdx; i++) {
    line += String(enrolledIDs[i]);
    if (i != endIdx - 1) line += ",";
    if (line.length() > 19 || i == endIdx - 1) {
      lcd.setCursor(0, lineNum);
      lcd.print(line);
      line = "";
      lineNum++;
      if (lineNum > 3) break;
    }
  }
}

void deleteAllFPIDs() {
  // Delete all stored models from fingerprint sensor
  lcd.clear();
  lcd.print("Deleting...");
  for (int i = 0; i < 127; i++) {
    finger.deleteModel(i);
  }
  enrolledIDs.clear();

  lcd.clear();
  lcd.print("All FPIDs Deleted");
  buzz();
  delay(2000);
  showIdleMenu();
}
