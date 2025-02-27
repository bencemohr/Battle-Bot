#include <Adafruit_NeoPixel.h>
#include <SoftwareSerial.h>

// Bluetooth debugging
SoftwareSerial btSerial(2,3);

// Define time
unsigned long _timeZero = 0;

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
const int LINE1 = A1;
const int LINE2 = A2;
const int LINE3 = A3;
const int LINE4 = A4;
const int LINE5 = A5;
const int LINE6 = A6;
const int LINE7 = A7;
// Define gripper pins
const int GRIP = 9;
// Define rotation sensor pins

// Define neo pixel pins
const int LED_PIN = 4;
const int LED_COUNT = 4;
Adafruit_NeoPixel _leds = Adafruit_NeoPixel(LED_COUNT,LED_PIN,NEO_RGB + NEO_KHZ800);
// Define global calibration variables