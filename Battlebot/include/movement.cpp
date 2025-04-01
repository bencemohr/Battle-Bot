//Moving functions

void moveBackward(long t) {
    _leds.fill(_leds.Color(255, 255, 255), 3, 4);
    _leds.show();
    analogWrite(MOTOR_A1, 255);
    analogWrite(MOTOR_A2, 0);
    analogWrite(MOTOR_B1, 0);
    analogWrite(MOTOR_B2, 255);
    delay(t);
  }
  
  void moveLeft(long t) {
    analogWrite(MOTOR_A1, 0);
    analogWrite(MOTOR_A2, 230);
    analogWrite(MOTOR_B1, 180);
    analogWrite(MOTOR_B2, 0);
    delay(t);
  }

  void moveLeftSharp(long t) {
    analogWrite(MOTOR_A1, 0);
    analogWrite(MOTOR_A2, 255);
    analogWrite(MOTOR_B1, 0);
    analogWrite(MOTOR_B2, 200);
    delay(t);
  }
  
  void moveRight(long t) {
    analogWrite(MOTOR_A1, 0);
    analogWrite(MOTOR_A2, 150);
    analogWrite(MOTOR_B1, 255);
    analogWrite(MOTOR_B2, 0);
    delay(t);
  }  
  
  void moveRightSharp(long t) {
    analogWrite(MOTOR_A1, 200);
    analogWrite(MOTOR_A2, 0);
    analogWrite(MOTOR_B1, 255);
    analogWrite(MOTOR_B2, 0);
    delay(t);
  }
  
  void moveForward(long t) {
    analogWrite(MOTOR_A1, 0);
    analogWrite(MOTOR_A2, 220);
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

  void spin()
  {
    analogWrite(MOTOR_A1, 255);
    analogWrite(MOTOR_A2,  0);
    analogWrite(MOTOR_B1, 255);
    analogWrite(MOTOR_B2, 0);
    delay(500);
  }