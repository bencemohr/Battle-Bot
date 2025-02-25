#include <Arduino.h>
#include <SoftwareSerial.h>
#include <Adafruit_NeoPixel.h>

// Bluetooth debugging
SoftwareSerial btSerial(2,3);

// Define time
unsigned long timeZero = 0;

// Define motor control pins
const int MOTOR_A1 = 11;
const int MOTOR_A2 = 10;
const int MOTOR_B1 = 9;
const int MOTOR_B2 = 6;
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

// Define rotation sensor pins

// Define neo pixel pins
const int LED_PIN = 5;
const int LED_COUNT = 4;
Adafruit_NeoPixel leds = Adafruit_NeoPixel(LED_COUNT,LED_PIN,NEO_RGB + NEO_KHZ800);

void setup() {
  leds.begin();
  leds.setBrightness(100);
  leds.setPixelColor(0,leds.Color(255,0,0));
  leds.show();
  delay(500);
  // Set motor pins as outputs
  pinMode(MOTOR_A1, OUTPUT);
  pinMode(MOTOR_A2, OUTPUT);
  pinMode(MOTOR_B1, OUTPUT);
  pinMode(MOTOR_B2, OUTPUT);
  leds.setPixelColor(3,leds.Color(255,0,0));
  leds.show();
  delay(500);
  pinMode(SENSOR_TRIGGER, OUTPUT);
  pinMode(SENSOR_ECHO, INPUT);
  leds.setPixelColor(2,leds.Color(255,0,0));
  leds.show();
  delay(500);
  pinMode(LINE1, INPUT);
  pinMode(LINE2, INPUT);
  pinMode(LINE3, INPUT);
  pinMode(LINE4, INPUT);
  pinMode(LINE5, INPUT);
  pinMode(LINE6, INPUT);
  pinMode(LINE7, INPUT);
  leds.setPixelColor(1,leds.Color(255,0,0));
  leds.show();
  delay(500);
  Serial.begin(9600);
  delay(500);
  btSerial.begin(9600);
  Serial.println("--### ARDUINO RESET ###--");
  btSerial.println("BT Ready");
  btSerial.println("--### ARDUINO RESET ###--");

  leds.fill(leds.Color(0,255,0),0,4);
  leds.show();
  delay(500);
  leds.clear();
  leds.show();
  delay(500);
  leds.fill(leds.Color(0,255,0),0,4);
  leds.show();
  delay(500);
  leds.clear();
  leds.show();
  delay(500);
  leds.fill(leds.Color(0,255,0),0,4);
  leds.show();
  delay(500);
  leds.clear();
  leds.show();
}

//Moving functions

void moveBackward(int t) {
  analogWrite(MOTOR_A1, 230);
  analogWrite(MOTOR_A2, 0);
  analogWrite(MOTOR_B1, 0);
  analogWrite(MOTOR_B2, 255);
  delay(t);
}

void moveLeft(int t) {
  analogWrite(MOTOR_A1, 0);
  analogWrite(MOTOR_A2, 220);
  analogWrite(MOTOR_B1, 0);
  analogWrite(MOTOR_B2, 0);
  delay(t);
}

void moveRight(int t) {
  analogWrite(MOTOR_A1, 0);
  analogWrite(MOTOR_A2, 0);
  analogWrite(MOTOR_B1, 255);
  analogWrite(MOTOR_B2, 0);
  delay(t);
}

void moveForward(int t) {
  analogWrite(MOTOR_A1, 0);
  analogWrite(MOTOR_A2,  230);
  analogWrite(MOTOR_B1, 255);
  analogWrite(MOTOR_B2, 0);
  delay(t);
}

void stop() {
  analogWrite(MOTOR_A1, 0);
  analogWrite(MOTOR_A2,  0);
  analogWrite(MOTOR_B1, 0);
  analogWrite(MOTOR_B2, 0);
}
/*
long sense() {
  //Sonar control and distance calculations
  digitalWrite(SENSOR_TRIGGER, LOW);
  delayMicroseconds(2);

  digitalWrite(SENSOR_TRIGGER, HIGH);
  delayMicroseconds(10);
  digitalWrite(SENSOR_TRIGGER, LOW);
  
  long duration = pulseIn(SENSOR_ECHO, HIGH);
  long distance = duration * 0.034 / 2;

  return distance;
}
//Object avoidance
void avoid(long distance) {
  //Go around object
  if (distance<18){
    moveBackward(200);
    moveRight(900);
    moveForward(1000);
    moveLeft(900);
    moveForward(1000);
    moveLeft(900);
    moveForward(1000);
    moveRight(900);
    distance = sense();
  }
  else{
    //Keep forwards
    long distance = sense();
    moveForward(500);
  }

}
*/

//Commands from BT
void readBT()
{
  if (btSerial.available())
  {
    char input = btSerial.read();

    btSerial.print("Recieved command: ");
    btSerial.println(input);

    switch (input)
    {
      case 'F': 
        moveForward(1000);
        break;
      case 'B':
        moveBackward(1000);
        break;
      case 'L':
        moveLeft(1000);
        break;
      case 'R':
        moveRight(1000);
        break;
      case 'S':
        setup();
        break;
      default:
        btSerial.println("Invalid command");
        break;
    }
  }
}

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
  /*
  Serial.println(analogRead(LINE1));
  Serial.println(analogRead(LINE2));
  Serial.println(analogRead(LINE3));
  Serial.println(analogRead(LINE4));
  Serial.println(analogRead(LINE5));
  Serial.println(analogRead(LINE6));
  Serial.println(analogRead(LINE7));
  Serial.println("----BREAK LINE---");

  delay(1000);
  */
   readBT();
}

/*
Basic moves function
void basicMoves(){
  moveForward(5000);
  moveBackward(4000);
  moveRight(1000);
  moveLeft(1000);
}
*/


