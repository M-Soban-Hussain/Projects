#include <AFMotor.h>

const int stepsPerRevolution = 4096;
AF_Stepper motor(stepsPerRevolution, 2);  // Port 2

void setup() {
  Serial.begin(9600);
  motor.setSpeed(10);  // Start with low speed
}

void loop() {
  motor.step(4096, FORWARD, INTERLEAVE); // 1 full revolution
  delay(1000);
  motor.step(4096, BACKWARD, INTERLEAVE);
  delay(1000);
}
