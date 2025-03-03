#include <Arduino.h>
#include <declared.cpp>

/*
AUTH BY:
JOEY HARMS
BENCE MOHR
2025.
*/

void setup() {
  Serial.end();
  _leds.begin();
  _leds.setBrightness(100);
  _leds.setPixelColor(3,_leds.Color(255,0,0));
  _leds.show();
  //gripper.attach(9);
  delay(500);
  // Set motor pins as outputs
  pinMode(MOTOR_A1, OUTPUT);
  pinMode(MOTOR_A2, OUTPUT);
  pinMode(MOTOR_B1, OUTPUT);
  pinMode(MOTOR_B2, OUTPUT);
  _leds.setPixelColor(2,_leds.Color(255,0,0));
  _leds.show();
  delay(500);
  pinMode(SENSOR_TRIGGER, OUTPUT);
  pinMode(SENSOR_ECHO, INPUT);
  _leds.setPixelColor(1,_leds.Color(255,0,0));
  _leds.show();
  delay(500);
  pinMode(LINE1, INPUT);
  pinMode(LINE2, INPUT);
  pinMode(LINE3, INPUT);
  pinMode(LINE4, INPUT);
  pinMode(LINE5, INPUT);
  pinMode(LINE6, INPUT);
  pinMode(LINE7, INPUT);
  pinMode(GRIPPER, OUTPUT);
  digitalWrite(GRIPPER, LOW);
  _leds.setPixelColor(0,_leds.Color(255,0,0));
  _leds.show();
  delay(500);
  Serial.begin(9600);
  delay(500);
  btSerial.begin(9600);
  _calibrationRunning = false;
  pinMode(BUTTON1, INPUT);
  Serial.println("--### ARDUINO RESET ###--");
  btSerial.println("BT Ready");
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
#include <bluetooth.cpp>
#include <sens_front.cpp>
#include <avoid.cpp>
#include <line.cpp>
#include <calibrate.cpp>
void loop() {
  /*
  //Sensing
  long distance = sense();
  //Debug
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm.");
  avoid(distance);
  */
  

  readLine();
  readBT();
  /*
  if (digitalRead(BUTTON1) == 0 && _calibrationRunning == false){
    _calibrationRunning = true;
    btSerial.println("Calibration job sent.");
    calibrate();
  }
  */
  if (digitalRead(BUTTON1) == 0)
  {
    grip(985);
    _Grip = true;
  }

}