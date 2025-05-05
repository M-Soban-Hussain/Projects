#define trigPin 10
#define echoPin 9
#define relay1 7
#define relay2 6
#define relay3 5
#define relay4 4

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(relay1, OUTPUT);
  pinMode(relay2, OUTPUT);
  pinMode(relay3, OUTPUT);
  pinMode(relay4, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  long duration = measure();
  float distance = (duration > 0) ? (duration * 0.034 / 2) : 0;

  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

 if (distance > 0 && distance < 30) {  
  digitalWrite(relay1, HIGH);
  digitalWrite(relay2, LOW);
  digitalWrite(relay3, HIGH);
  digitalWrite(relay4, LOW);
  delay(800);
  digitalWrite(relay1, LOW);
  digitalWrite(relay2, HIGH);
  digitalWrite(relay3, HIGH);
  digitalWrite(relay4, LOW);
  delay(1100);
} 
else {  
  digitalWrite(relay1, LOW);
  digitalWrite(relay2, HIGH);
  digitalWrite(relay3, LOW);
  digitalWrite(relay4, HIGH);
}
  delay(200); // Optional debounce delay
}

long measure() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
return pulseIn(echoPin, HIGH, 30000);
}
