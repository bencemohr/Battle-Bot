#include <Arduino.h>
#include <declared.cpp>
#include <SoftwareSerial.h>

/*
AUTH BY:
JOEY HARMS
BENCE MOHR
2025. Jan - Apr
*/

SoftwareSerial btSerial(7, 2); // RX, TX

void setup() {
  Serial.end();
  _leds.begin();
  _leds.setBrightness(100);
  _leds.setPixelColor(3,_leds.Color(255,0,0));
  _leds.show();
  delay(500);
  // Set motor pins as outputs
  pinMode(MOTOR_A1, OUTPUT);
  pinMode(MOTOR_A2, OUTPUT);
  pinMode(MOTOR_B1, OUTPUT);
  pinMode(MOTOR_B2, OUTPUT);
  _leds.setPixelColor(2,_leds.Color(255,0,0));
  _leds.show();
  delay(500);
  pinMode(SENSOR_TRIGGER_FRONT, OUTPUT);
  pinMode(SENSOR_ECHO_FRONT, INPUT);  
  pinMode(SENSOR_TRIGGER_LEFT, OUTPUT);
  pinMode(SENSOR_ECHO_LEFT, INPUT);
  pinMode(SENSOR_TRIGGER_RIGHT, OUTPUT);
  pinMode(SENSOR_ECHO_RIGHT, INPUT);
  _leds.setPixelColor(1,_leds.Color(255,0,0));
  _leds.show();
  delay(500);
  pinMode(LINE3, INPUT);
  pinMode(LINE4, INPUT);
  pinMode(LINE5, INPUT);
  pinMode(GRIPPER, OUTPUT);
  _leds.setPixelColor(0,_leds.Color(255,0,0));
  _leds.show();
  delay(500);
  Serial.begin(9600);
  btSerial.begin(9600);
  delay(500);
  Serial.println("--### ARDUINO RESET ###--");
  btSerial.println("--### ARDUINO RESET ###--");

  _leds.fill(_leds.Color(0,255,0),0,4);
  _leds.show();
  delay(500);
  _leds.clear();
  _leds.show();
  delay(500);
  _leds.fill(_leds.Color(0,255,0),0,4);
  _leds.show();
  delay(500);
  _leds.clear();
  _leds.show();
  delay(500);
  _leds.fill(_leds.Color(0,255,0),0,4);
  _leds.show();
  delay(500);
  _leds.clear();
  _leds.show();
}

//INCLUDES

#include <gripper.cpp>
#include <movement.cpp>
#include <sens_front.cpp>
#include <avoid.cpp>
#include <line.cpp>
#include <assignment.cpp>
#include <sens_right.cpp>
#include <sens_left.cpp>
#include <primed.cpp>

long getFilteredDistance(long (*senseFunc)()) {
    long total = 0;
    for (int i = 0; i < 5; i++) {
        total += senseFunc();
        delay(10);  // Small delay between readings
    }
    return total / 5;  // Return the average
}

void checkIfStuck(long frontDistance, long leftDistance, long rightDistance) {
    const long stuckThresholdFront = 7; // Threshold distance in cm to consider "stuck"
    const long stuckThresholdSides = 2; // Threshold distance in cm to consider "stuck"

    if (frontDistance < stuckThresholdFront) {
        // Too close to a wall in front, reverse
        btSerial.println("Stuck: Too close to the front. Reversing...");
        moveBackward(100);
    } else if (leftDistance < stuckThresholdSides) {
        // Too close to a wall on the left, turn right
        btSerial.println("Stuck: Too close to the left. Turning right...");
        moveRight(300);
    } else if (rightDistance < stuckThresholdSides) {
        // Too close to a wall on the right, turn left
        btSerial.println("Stuck: Too close to the right. Turning left...");
        moveLeft(300);
    }
}

void loop() {  
  long frontDistance = sense();
  long leftDistance = senseLeft();
  long rightDistance = senseRight();
  if (_state == 0) {
    _leds.fill(_leds.Color(25,155,250),0,4);
    _leds.show();
    if (frontDistance <= 25)
    {
        grip(1500);
        grip(1500);
        delay(1000);
        _leds.fill(_leds.Color(255,0,0),0,4);
        _leds.show();
        delay(2500);
        _leds.fill(_leds.Color(255, 165, 0),0,4);
        _leds.show();
        delay(2500);
        _leds.fill(_leds.Color(0,255,0),0,4);
        _leds.show();
        moveForward(1500);
        stop();
        grip(985);
        grip(985);
        delay(500);
        moveLeftSharp(800);
        moveForward(500);
        stop();
        _state++;
    }
  } else if (_state == 1) {
    // Print sensor readings for debugging
    btSerial.print("Front: "); btSerial.print(frontDistance);
    btSerial.print(" | Left: "); btSerial.print(leftDistance);
    btSerial.print(" | Right: "); btSerial.println(rightDistance);
    delay(100);

    // Check if the robot is stuck
    checkIfStuck(frontDistance, leftDistance, rightDistance);

    // Right-hand rule logic
    if (rightDistance > 18) {  // If the right is clear, turn right
        btSerial.println("Turning right");
        moveRightSharp(200);
        delay(500);  // Allow time for the turn
    } else if (frontDistance > 18) {  // If forward is clear, move forward
        btSerial.println("Moving forward");
        moveForward(200);
        delay(500);  // Allow time for movement
    } else if (leftDistance > 18) {  // If left is clear, turn left
        btSerial.println("Turning left");
        moveLeftSharp(200);
        delay(500);  // Allow time for the turn
    } else {  // If all directions are blocked, reverse and turn around
        btSerial.println("All directions blocked, reversing and turning around");
        moveBackward(270);
        delay(500);
        spin();  // Turn around
        delay(500);
    }
  } else if (_state == 2) {
    /* code */
  } else if (_state == 3)
  {
    /* code */
  }
}