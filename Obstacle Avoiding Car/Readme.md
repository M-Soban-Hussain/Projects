🚗 Obstacle Avoiding Car 🤖
An Arduino-based robot car that avoids obstacles using an ultrasonic sensor. Simple, fun, and beginner-friendly!

🔧 components used
🧠 arduino uno

⚙️ l298n motor driver

🌊 hc-sr04 ultrasonic sensor

🔩 2 gear motors

🧵 jumper wires

🔋 2 x 9v batteries

🖼️ circuit diagram
included in the repo to make wiring easy and clear 🧰

🛠️ step-by-step setup
🔋 power connection
connect 2 x 9v batteries in series

positive terminal → 12v pin of motor driver

negative terminal → gnd of motor driver

🔗 common ground
connect arduino gnd to motor driver gnd

⚙️ motor wiring
connect motors to motor driver

match +ve to +ve and -ve to -ve

🎮 control pins
in1 → pin 7

in2 → pin 6

in3 → pin 5

in4 → pin 4

📡 ultrasonic sensor
vcc → 5v on arduino

gnd → gnd on arduino

trig → pin 9

echo → pin 8

🧠 enable pins
short both ena pins together

short both enb pins together

⚙️ how it works
measures distance with sensor

if obstacle detected:

stop → reverse → turn → move forward

💾 code
upload the sketch to your arduino
it handles sensing, decisions, and motion

✅ tips
always connect a common ground

check connections before powering

enjoy your smart dodging car 😄
