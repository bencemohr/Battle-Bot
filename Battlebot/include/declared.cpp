#include <Adafruit_NeoPixel.h>
#include <Servo.h>

// Define states
int _state  = 0; //0 = primed, 1 = solving, 2 = ending, 3 = finished/stopped

// Define time
unsigned long _timeZero = 500;

// Define motor control pins
const int MOTOR_A1 = 11;
const int MOTOR_A2 = 10;
const int MOTOR_B1 = 6;
const int MOTOR_B2 = 5;

// Define sensor pins
    //Sensor front
const int SENSOR_TRIGGER_FRONT = 3;
const int SENSOR_ECHO_FRONT = A0;
    //Sensor right
const int SENSOR_TRIGGER_RIGHT = 12;
const int SENSOR_ECHO_RIGHT = 13;
    //Sensor left
const int SENSOR_TRIGGER_LEFT = A4;
const int SENSOR_ECHO_LEFT = A5;
// Define line sensor pins
const int LINE3 = A3;
const int LINE4 = A2;
const int LINE5 = A1;
// Define gripper pins
    //Servo gripper;
    const int GRIPPER = 9;

// Define neo pixel pins
const int LED_PIN = 4;
const int LED_COUNT = 4;
Adafruit_NeoPixel _leds = Adafruit_NeoPixel(LED_COUNT,LED_PIN,NEO_RGB + NEO_KHZ800);
// Define global calibration variables
int LOWER_LIMIT = 0;
int UPPER_LIMIT = 0;