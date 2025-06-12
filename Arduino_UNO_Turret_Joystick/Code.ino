#include <Servo.h>

Servo servoX;
Servo servoY;

int lastX = 90;
int lastY = 90;

void setup() {
  servoX.attach(9);
  servoY.attach(10);
}

void loop() {
  int xValue = analogRead(A0);
  int yValue = analogRead(A1);

  int xPos = map(xValue, 0, 1023, 180, 0);  // full inverted X
  int yPos = map(yValue, 0, 1023, 0, 180);  // full Y

  if (abs(xPos - lastX) > 3) {
    servoX.write(xPos);
    lastX = xPos;
  }

  if (abs(yPos - lastY) > 3) {
    servoY.write(yPos);
    lastY = yPos;
  }

  delay(20);
}
