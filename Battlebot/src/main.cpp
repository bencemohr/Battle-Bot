#include <Arduino.h>

// Define motor control pins
const int MOTOR_A1 = 3;
const int MOTOR_A2 = 9;
const int MOTOR_B1 = 11;
const int MOTOR_B2 = 10;
const int SENSOR_TRIGGER = 8;
const int SENSOR_ECHO = 7;

void setup() {
  // Set motor pins as outputs
  pinMode(MOTOR_A1, OUTPUT);
  pinMode(MOTOR_A2, OUTPUT);
  pinMode(MOTOR_B1, OUTPUT);
  pinMode(MOTOR_B2, OUTPUT);
  pinMode(SENSOR_TRIGGER, OUTPUT);
  pinMode(SENSOR_ECHO, INPUT);
  Serial.begin(9600);
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

void loop() {
  //Sensing
  long distance = sense();
  //Debug
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm.");
  avoid(distance);
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


