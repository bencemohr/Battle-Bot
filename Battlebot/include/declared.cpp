#include <Adafruit_NeoPixel.h>
#include <SoftwareSerial.h>
#include <Servo.h>


// Bluetooth debugging
SoftwareSerial btSerial(2,3);

// Define time
unsigned long _timeZero = 500;

// Define callibrate button
const int BUTTON1 = 8;
bool _calibrationRunning = false;

// Define motor control pins
const int MOTOR_A1 = 11;
const int MOTOR_A2 = 10;
const int MOTOR_B1 = 6;
const int MOTOR_B2 = 5;
// Define sensor pins
const int SENSOR_TRIGGER = 8;
const int SENSOR_ECHO = 7;
// Define line sensor pins
const int LINE1 = A0;
const int LINE2 = A1;
const int LINE3 = A2;
const int LINE4 = A3;
const int LINE5 = A4;
const int LINE6 = A5;
const int LINE7 = A6;
const int LINE8 = A7;
// Define gripper pins
//Servo gripper;
const int GRIPPER = 9;
bool _Grip = false;
// Define rotation sensor pins

// Define neo pixel pins
const int LED_PIN = 4;
const int LED_COUNT = 4;
Adafruit_NeoPixel _leds = Adafruit_NeoPixel(LED_COUNT,LED_PIN,NEO_RGB + NEO_KHZ800);
// Define global calibration variables
int BOOST = 20;