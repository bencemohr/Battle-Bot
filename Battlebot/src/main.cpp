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
void loop() {
  long frontDistance = sense();
  long leftDistance = senseLeft();
  long rightDistance = senseRight();

  Serial.print("Front: "); Serial.print(frontDistance);
  Serial.print(" | Left: "); Serial.print(leftDistance);
  Serial.print(" | Right: "); Serial.println(rightDistance);
  delay(100);

   if (leftDistance < 15) {  // Reduced sensitivity to 15cm
       stop();
       delay(200);

       if (frontDistance > 15) {  
           moveForward(100);
       } else if (rightDistance > 15) {  
           moveRightSharp(100);
       } else {  
           // DEAD END - Move backward before turning
           spin();
           delay(1000);
       }
   } else {
      moveLeft(100);
   }
}
