#include <AFMotor.h>
#include <SoftwareSerial.h>

SoftwareSerial BT(9, 10); // RX, TX for HC-05

AF_DCMotor motor1(1); // M1
AF_DCMotor motor2(2); // M2
AF_DCMotor motor3(3); // M3
AF_DCMotor motor4(4); // M4

char cmd = 'S';
unsigned long lastCmdTime = 0;

void setup() {
  Serial.begin(9600);
  BT.begin(9600);
  Serial.println("Adafruit Bluetooth Car Ready");
  stopCar();
}

void loop() {
  if (BT.available()) {
    cmd = BT.read();
    lastCmdTime = millis();
    Serial.print("Received: ");
    Serial.println(cmd);
    controlCar(cmd);
  }

  if (millis() - lastCmdTime > 500)
    stopCar();
}

void controlCar(char c) {
  switch (c) {
    case 'F': forward();  Serial.println("Moving Forward");  break;
    case 'B': backward(); Serial.println("Moving Backward"); break;
    case 'L': left();     Serial.println("Turning Left");    break;
    case 'R': right();    Serial.println("Turning Right");   break;
    case '0': stopCar();  Serial.println("Stopped");         break;
    default: break;
  }
}

void forward() {
  motor1.setSpeed(255); motor2.setSpeed(255);
  motor3.setSpeed(255); motor4.setSpeed(255);
  motor1.run(BACKWARD);  motor2.run(BACKWARD);
  motor3.run(BACKWARD);  motor4.run(BACKWARD);
}

void backward() {
  motor1.setSpeed(255); motor2.setSpeed(255);
  motor3.setSpeed(255); motor4.setSpeed(255);
  motor1.run(FORWARD);  motor2.run(FORWARD);
  motor3.run(FORWARD);  motor4.run(FORWARD);
}


void left() {
  motor1.setSpeed(255); motor2.setSpeed(255);
  motor3.setSpeed(255); motor4.setSpeed(255);
  // Left side forward, right side backward
  motor1.run(FORWARD);  motor2.run(FORWARD);
  motor3.run(BACKWARD); motor4.run(BACKWARD);
}

void right() {

  motor1.setSpeed(255); motor2.setSpeed(255);
  motor3.setSpeed(255); motor4.setSpeed(255);
  // Left side backward, right side forward
  motor1.run(BACKWARD); motor2.run(BACKWARD);
  motor3.run(FORWARD);  motor4.run(FORWARD);
}


void stopCar() {
  motor1.run(RELEASE);
  motor2.run(RELEASE);
  motor3.run(RELEASE);
  motor4.run(RELEASE);
}
