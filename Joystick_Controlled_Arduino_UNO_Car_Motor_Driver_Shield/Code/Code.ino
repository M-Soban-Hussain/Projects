#include <AFMotor.h>

// Joystick pins
#define VRX A0
#define VRY A1

// Motor mappings
AF_DCMotor motor1(1);  // Front-Right
AF_DCMotor motor2(2);  // Back-Right (inverted)
AF_DCMotor motor3(3);  // Back-Left  (inverted)
AF_DCMotor motor4(4);  // Front-Left

void setup() {
  Serial.begin(9600);
  motor1.setSpeed(200);
  motor2.setSpeed(200);
  motor3.setSpeed(200);
  motor4.setSpeed(200);
}

void loop() {
  int x = 512 - analogRead(VRY);
  int y = analogRead(VRX) - 512;

  Serial.print("X: "); Serial.print(x);
  Serial.print("  Y: "); Serial.println(y);

  int threshold = 100;

  if (y > threshold) forward();
  else if (y < -threshold) backward();
  else if (x > threshold) right();
  else if (x < -threshold) left();
  else stopCar();
}

void forward() {
  motor1.run(FORWARD);  
  motor2.run(BACKWARD);  // inverted
  motor3.run(BACKWARD);  // inverted
  motor4.run(FORWARD);
}

void backward() {
  motor1.run(BACKWARD);  
  motor2.run(FORWARD);  // inverted
  motor3.run(FORWARD);  // inverted
  motor4.run(BACKWARD);
}

void right() {
  motor1.run(BACKWARD);
  motor2.run(FORWARD);
  motor3.run(BACKWARD);
  motor4.run(FORWARD);
}

void left() {
  motor1.run(FORWARD);
  motor2.run(BACKWARD);
  motor3.run(FORWARD);
  motor4.run(BACKWARD);
}

void stopCar() {
  motor1.run(RELEASE);
  motor2.run(RELEASE);
  motor3.run(RELEASE);
  motor4.run(RELEASE);
}
