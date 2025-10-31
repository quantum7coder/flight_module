#include <Servo.h>

// Create Servo objects for each ESC
Servo esc1;  // M1 - Right Front (CW)
Servo esc2;  // M2 - Right Rear (CCW)
Servo esc3;  // M3 - Left Rear (CW)
Servo esc4;  // M4 - Left Front (CCW)

// Define ESC signal pins
const int ESC1_PIN = 2;
const int ESC2_PIN = 3;
const int ESC3_PIN = 4;
const int ESC4_PIN = 5;

// ESC pulse limits (in microseconds)
const int MIN_THROTTLE = 1000;  // minimum (stop)
const int MAX_THROTTLE = 2000;  // maximum (full speed)

void setup() {
  // Attach ESCs to their signal pins
  esc1.attach(ESC1_PIN);
  esc2.attach(ESC2_PIN);
  esc3.attach(ESC3_PIN);
  esc4.attach(ESC4_PIN);

  Serial.begin(9600);
  Serial.println("Initializing ESCs...");

  // Step 1: Send minimum signal to arm ESCs
  esc1.writeMicroseconds(MIN_THROTTLE);
  esc2.writeMicroseconds(MIN_THROTTLE);
  esc3.writeMicroseconds(MIN_THROTTLE);
  esc4.writeMicroseconds(MIN_THROTTLE);

  Serial.println("Arming ESCs... wait 5 seconds");
  delay(5000); // Give ESCs time to initialize
}

void loop() {
  Serial.println("Increasing throttle...");
  
  // Gradually increase throttle
  for (int speed = MIN_THROTTLE; speed <= 1600; speed += 10) {
    esc1.writeMicroseconds(speed);
    esc2.writeMicroseconds(speed);
    esc3.writeMicroseconds(speed);
    esc4.writeMicroseconds(speed);
    delay(50);
  }

  Serial.println("Holding speed...");
  delay(2000);

  Serial.println("Stopping motors...");
  // Stop motors
  esc1.writeMicroseconds(MIN_THROTTLE);
  esc2.writeMicroseconds(MIN_THROTTLE);
  esc3.writeMicroseconds(MIN_THROTTLE);
  esc4.writeMicroseconds(MIN_THROTTLE);
  
  delay(5000);
}