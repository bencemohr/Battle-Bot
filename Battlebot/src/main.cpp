#include <Arduino.h>
#include <declared.cpp>

/*
AUTH BY:
JOEY HARMS
BENCE MOHR
2025. Jan - Apr
*/

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
  digitalWrite(GRIPPER, LOW);
  _leds.setPixelColor(0,_leds.Color(255,0,0));
  _leds.show();
  delay(500);
  Serial.begin(9600);
  delay(500);
  Serial.println("--### ARDUINO RESET ###--");

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
void loop() {  
  long frontDistance = sense();
  long leftDistance = senseLeft();
  long rightDistance = senseRight();
  if (_state == 0) {
    _leds.fill(_leds.Color(25,155,250),0,4);
    _leds.show();
    if (frontDistance <= 5)
    {
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
        moveForward(1000);
        stop();
        grip(985);
        delay(500);
        moveLeftSharp(720);
        moveForward(1150);
        delay(1250);
        stop();
        _state++;
    }
    
  } else if (_state == 1) {
    Serial.print("Front: "); Serial.print(frontDistance);
    Serial.print(" | Left: "); Serial.print(leftDistance);
    Serial.print(" | Right: "); Serial.println(rightDistance);
    delay(100);
  
     if (rightDistance < 15) {  // Reduced sensitivity to 15cm
         moveRightSharp(200);
  
         if (frontDistance > 15) {  
             moveForward(200);
         } else if (leftDistance > 15) {  
             moveLeftSharp(200);
         } else if (frontDistance <= 7) {
             // Move backward and turn
             moveBackward(200);
             delay(300);
             spin();
             delay(300);
          } else if (leftDistance <= 4) {
            moveRight(200);
          } else if (rightDistance <= 4) {
            moveLeft(200);
          } else {  
             // DEAD END - Move backward before turning
             spin();
             delay(300);
        moveRight(200);
        delay(100);
     }  
  } // Closing brace added here
  } // Missing closing brace for else if (_state == 1)
  else if (_state == 2) {
    /* code */
  } else if (_state == 3)
  {
    /* code */
  }
}