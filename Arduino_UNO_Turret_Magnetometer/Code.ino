#include <Wire.h>
#include <QMC5883LCompass.h>
#include <Servo.h>

QMC5883LCompass compass;
Servo servoX;
Servo servoY;

int centerX = 0, centerY = 0;
float sensitivity = 0.7;  // You can adjust this
const int filterStrength = 12;  // Higher = smoother, slower response

float filteredX = 0;
float filteredY = 0;

void setup() {
  Serial.begin(9600);
  Wire.begin();
  compass.init();

  servoX.attach(9);
  servoY.attach(10);
  servoX.write(90);
  servoY.write(90);
  
  Serial.println("Calibrating...");
  long startTime = millis();

  long sumX = 0, sumY = 0;
  int samples = 0;

  while (millis() - startTime < 3000) {
    compass.read();
    sumX += compass.getX();
    sumY += compass.getY();
    samples++;
    delay(10);
  }

  centerX = sumX / samples;
  centerY = sumY / samples;

  Serial.println("Calibration done.");
}

void loop() {
  compass.read();
  int rawX = compass.getX() - centerX;
  int rawY = compass.getY() - centerY;

  // Apply sensitivity
  rawX = rawX * sensitivity;
  rawY = rawY * sensitivity;

  // Invert X
  rawX = -rawX;

  // Apply smoothing filter
  filteredX = (filteredX * (filterStrength - 1) + rawX) / filterStrength;
  filteredY = (filteredY * (filterStrength - 1) + rawY) / filterStrength;

  // Map and constrain
  int servoPosX = constrain(map(filteredX, -500, 500, 0, 180), 0, 180);
  int servoPosY = constrain(map(filteredY, -500, 500, 0, 180), 0, 180);

  servoX.write(servoPosX);
  servoY.write(servoPosY);

  Serial.print("X: "); Serial.print(servoPosX);
  Serial.print(" Y: "); Serial.println(servoPosY);

  delay(20);
}
