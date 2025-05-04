# Arduino 4-Wheel Robot Car
This repository contains code and instructions for building a 4-wheel robot car using Arduino. The car uses an ultrasonic sensor for obstacle detection and can be controlled using different methods.

## Things Needed

1. Arduino UNO board
2. HC-SR04 Ultrasonic Distance Sensor
3. 4-Channel Relay Module
4. 4 DC Motors with wheels
5. Battery Pack (3x 18650 batteries)
6. Jumper Wires
7. Chassis (or you can make your own)
8. Power Switch
9. Breadboard (optional, for easier connections)

## Connections

### Motor Connections
- **Left Front Motor:**
  - Red wire → Relay Channel 1 (NO)
  - Black wire → Battery Negative
  
- **Right Front Motor:**
  - Red wire → Relay Channel 2 (NO)
  - Black wire → Battery Negative
  
- **Left Rear Motor:**
  - Red wire → Relay Channel 3 (NO)
  - Black wire → Battery Negative
  
- **Right Rear Motor:**
  - Red wire → Relay Channel 4 (NO)
  - Black wire → Battery Negative

### Relay Module Connections
- **VCC** → Arduino 5V
- **GND** → Arduino GND
- **IN1** → Arduino Digital Pin 7
- **IN2** → Arduino Digital Pin 6
- **IN3** → Arduino Digital Pin 5
- **IN4** → Arduino Digital Pin 4
- **Relay COM Pins** → Battery Positive

### HC-SR04 Ultrasonic Sensor Connections
- **VCC** → Arduino 5V
- **GND** → Arduino GND
- **TRIG** → Arduino Digital Pin 9
- **ECHO** → Arduino Digital Pin 8

### Power Connections
- Battery Positive → Power Switch → Relay COM Pins
- Battery Negative → Arduino GND and Motor Negative wires
- Arduino Vin → Battery Positive (after the switch)

## Setup Instructions

1. Assemble the chassis and attach the motors to their respective positions
2. Mount the Arduino board securely on the chassis
3. Connect the relay module following the connection diagram
4. Connect the HC-SR04 ultrasonic sensor at the front of the robot
5. Connect all wires according to the connection details above
6. Double-check all connections before powering on
7. Upload the code from this repository to your Arduino board
8. Power on and test the robot car

## How It Works

This robot car can operate in two modes:
1. **Obstacle Avoidance Mode:** Using the ultrasonic sensor, the car detects obstacles and changes direction accordingly
2. **Manual Control Mode:** Can be controlled via various methods (details in the code)

The relay module controls the power to each motor independently, allowing different movement patterns:
- All motors forward → Move forward
- All motors backward → Move backward
- Left motors forward, Right motors backward → Turn right
- Right motors forward, Left motors backward → Turn left

## Code

The code for this project is available in this repository. It includes:
- Main code for relay-based motor control
- Functions for ultrasonic sensor readings
- Movement control algorithms

## Alternative Version

If you don't have the relay module, you can also use a motor driver version which is available in another folder in the same repository. The motor driver version uses an L298N or similar H-bridge motor driver instead of relays.

## Updates

Working perfectly! I'll be sharing a video demonstration soon. If you have any questions or need further clarification, feel free to ask me.

## License

This project is open-source and available under the MIT License.
