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