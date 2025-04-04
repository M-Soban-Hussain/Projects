// Define pin connections
#define trigPin 9
#define echoPin 8
#define motor1Pin1 7
#define motor1Pin2 6
#define motor2Pin1 5
#define motor2Pin2 4

void setup() {
  // Initialize the pins
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(motor1Pin1, OUTPUT);
  pinMode(motor1Pin2, OUTPUT);
  pinMode(motor2Pin1, OUTPUT);
  pinMode(motor2Pin2, OUTPUT);

  Serial.begin(9600);
}

void loop() {
  long duration, distance;

  // Trigger the ultrasonic sensor
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Read the echo pin
  duration = pulseIn(echoPin, HIGH);

  // Calculate distance
  distance = (duration / 2) / 29.1;

  // Print distance
  Serial.print("Distance: ");
  Serial.println(distance);

  // Check if the car is too close to an obstacle
  if (distance < 15) {
    // Stop the car if obstacle is detected
    stopCar();
    delay(500); // Wait for a short moment
    reverseCar();
    delay(1000); // Reverse for 1 second
    turnCarRight(); // Turn right after reversing
    delay(500); // Turn for 0.5 second
  } else {
    // Move forward if no obstacle
    moveForward();
  }
}

// Move the car forward
void moveForward() {
  digitalWrite(motor1Pin1, HIGH);
  digitalWrite(motor1Pin2, LOW);
  digitalWrite(motor2Pin1, HIGH);
  digitalWrite(motor2Pin2, LOW);
}

// Stop the car
void stopCar() {
  digitalWrite(motor1Pin1, LOW);
  digitalWrite(motor1Pin2, LOW);
  digitalWrite(motor2Pin1, LOW);
  digitalWrite(motor2Pin2, LOW);
}

// Reverse the car
void reverseCar() {
  digitalWrite(motor1Pin1, LOW);
  digitalWrite(motor1Pin2, HIGH);
  digitalWrite(motor2Pin1, LOW);
  digitalWrite(motor2Pin2, HIGH);
}

// Turn the car to the right
void turnCarRight() {
  digitalWrite(motor1Pin1, HIGH);
  digitalWrite(motor1Pin2, LOW);
  digitalWrite(motor2Pin1, LOW);
  digitalWrite(motor2Pin2, LOW);
}
