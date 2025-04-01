#include <Adafruit_NeoPixel.h>
#include <Servo.h>

/*
NEW NOTES FROM JOEY - 03.25
Wiring battle bot
A1 = 11
A2 = 10
B1 = 6
B2 = 5
Front sens echo = A0
Front sens trig = 3
Left sens echo = A7
Left sens trig= A6
Right sens echo = A5
Right sens trig = A4
Ir(line) 3 = A3
Ir 4 = A2
Ir 5 = A1
Grip = 9
*/


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
    bool _Grip = false;

// Define neo pixel pins
const int LED_PIN = 4;
const int LED_COUNT = 4;
Adafruit_NeoPixel _leds = Adafruit_NeoPixel(LED_COUNT,LED_PIN,NEO_RGB + NEO_KHZ800);
// Define global calibration variables
int BOOST = 20;