//Moving functions

void moveBackward(long t) {
    analogWrite(MOTOR_A1, 255);
    analogWrite(MOTOR_A2, 0);
    analogWrite(MOTOR_B1, 0);
    analogWrite(MOTOR_B2, 255);
    delayMicroseconds(t);
  }
  
  void moveLeft(long t) {
    analogWrite(MOTOR_A1, 0);
    analogWrite(MOTOR_A2, 230);
    analogWrite(MOTOR_B1, 180);
    analogWrite(MOTOR_B2, 0);
    delayMicroseconds(t);
  }

  void moveLeftSharp(long t) {
    analogWrite(MOTOR_A1, 0);
    analogWrite(MOTOR_A2, 255);
    analogWrite(MOTOR_B1, 0);
    analogWrite(MOTOR_B2, 0);
    delayMicroseconds(t);
  }
  
  void moveRight(long t) {
    analogWrite(MOTOR_A1, 0);
    analogWrite(MOTOR_A2, 150);
    analogWrite(MOTOR_B1, 255);
    analogWrite(MOTOR_B2, 0);
    delayMicroseconds(t);
  }  
  
  void moveRightSharp(long t) {
    analogWrite(MOTOR_A1, 0);
    analogWrite(MOTOR_A2, 0);
    analogWrite(MOTOR_B1, 255);
    analogWrite(MOTOR_B2, 0);
    delayMicroseconds(t);
  }
  
  void moveForward(long t) {
    analogWrite(MOTOR_A1, 0);
    analogWrite(MOTOR_A2, 220);
    analogWrite(MOTOR_B1, 255);
    analogWrite(MOTOR_B2, 0);
    delayMicroseconds(t);
  }
  
  void stop() {
    analogWrite(MOTOR_A1, 0);
    analogWrite(MOTOR_A2,  0);
    analogWrite(MOTOR_B1, 0);
    analogWrite(MOTOR_B2, 0);
  }