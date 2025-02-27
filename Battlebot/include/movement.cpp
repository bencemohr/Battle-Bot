//Moving functions

void moveBackward(int t) {
    analogWrite(MOTOR_A1, 180);
    analogWrite(MOTOR_A2, 0);
    analogWrite(MOTOR_B1, 0);
    analogWrite(MOTOR_B2, 185);
    delay(t);
  }
  
  void moveLeft(int t) {
    analogWrite(MOTOR_A1, 0);
    analogWrite(MOTOR_A2, 170);
    analogWrite(MOTOR_B1, 0);
    analogWrite(MOTOR_B2, 0);
    delay(t);
  }
  
  void moveRight(int t) {
    analogWrite(MOTOR_A1, 0);
    analogWrite(MOTOR_A2, 0);
    analogWrite(MOTOR_B1, 205);
    analogWrite(MOTOR_B2, 0);
    delay(t);
  }
  
  void moveForward(int t) {
    analogWrite(MOTOR_A1, 0);
    analogWrite(MOTOR_A2,  180);
    analogWrite(MOTOR_B1, 205);
    analogWrite(MOTOR_B2, 0);
    delay(t);
  }
  
  void stop() {
    analogWrite(MOTOR_A1, 0);
    analogWrite(MOTOR_A2,  0);
    analogWrite(MOTOR_B1, 0);
    analogWrite(MOTOR_B2, 0);
  }