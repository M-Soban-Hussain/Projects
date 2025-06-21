#include <ESP32Servo.h>

int potLeftPin = 1;   // 2k potentiometer (upper)
int potRightPin = 2;  // 50k potentiometer (beneath)

Servo servoLeft;
Servo servoRight;

int lastLeftDeg = 0;
int lastRightDeg = 0;

void setup() {
  Serial.begin(115200);
  
  servoLeft.setPeriodHertz(50);
  servoRight.setPeriodHertz(50);
  
  servoLeft.attach(4, 500, 2500);
  servoRight.attach(5, 500, 2500);
}

void loop() {
  int leftRaw = analogRead(potLeftPin);
  int rightRaw = analogRead(potRightPin);

  int leftDeg = map(leftRaw, 0, 4095, 0, 180);
  int rightDeg = map(rightRaw, 0, 4095, 0, 180);

  // Small deadzone for smaller potentiometer (2k)
  if (abs(leftDeg - lastLeftDeg) > 2) {
    servoLeft.write(leftDeg);
    lastLeftDeg = leftDeg;
  }

  // Bigger deadzone for bigger potentiometer (50k)
  if (abs(rightDeg - lastRightDeg) > 5) {
    servoRight.write(rightDeg);
    lastRightDeg = rightDeg;
  }

  Serial.print("Left Pot: ");
  Serial.print(leftDeg);
  Serial.print("°   Right Pot: ");
  Serial.print(rightDeg);
  Serial.println("°");

  delay(100);
}
