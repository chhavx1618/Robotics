#include <SoftwareSerial.h>

SoftwareSerial BT_Serial(2, 3); // RX, TX for Bluetooth communication

#define enA 10  // Enable1 L298 Pin enA
#define in1 8   // Motor1 L298 Pin in1
#define in2 6   // Motor1 L298 Pin in2
#define in3 7   // Motor2 L298 Pin in3
#define in4 5   // Motor2 L298 Pin in4

int Speed = 200; // Motor speed (0 to 255)
char direction;

void setup() {
  pinMode(enA, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);

  BT_Serial.begin(9600); // Start Bluetooth serial communication
  Serial.begin(9600);    // Start serial communication with the computer
}

void loop() {
  if (BT_Serial.available()) { // If data is available from Bluetooth
    direction = BT_Serial.read(); // Read the incoming byte

    // Process the received command
    switch (direction) {
      case 'F': // Move forward
        forward();
        break;
      case 'B': // Move backward
        backward();
        break;
      case 'L': // Turn left
        left();
        break;
      case 'R': // Turn right
        right();
        break;
      case 'S': // Stop
        stop();
        break;
    }
  }
}

void forward() {
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  analogWrite(enA, Speed);
}

void backward() {
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
  analogWrite(enA, Speed);
}

void left() {
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  analogWrite(enA, Speed); // Set speed for motors on the left side
}

void right() {
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
  analogWrite(enA, Speed); // Set speed for motors on the right side
}

void stop() {
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
}
