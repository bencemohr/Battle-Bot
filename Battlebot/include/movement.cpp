//Moving functions

void moveBackward(long t) {
    _leds.clear(); 
    _leds.fill(_leds.Color(255, 255, 255), 1, 3);
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
    _leds.clear();
    _leds.clear();
    _leds.setPixelColor(3,_leds.Color(255, 165, 0));
    _leds.setPixelColor(0,_leds.Color(255, 165, 0));
    _leds.show();
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
    _leds.clear();
    _leds.show();
    _leds.fill(_leds.Color(255, 165, 0), 1, 2);
    _leds.show();
    analogWrite(MOTOR_A1, 200);
    analogWrite(MOTOR_A2, 0);
    analogWrite(MOTOR_B1, 255);
    analogWrite(MOTOR_B2, 0);
    delay(t);
  }
  
  void moveForward(long t) {
    _leds.clear();
    _leds.show();
    _leds.setPixelColor(0,_leds.Color(255, 0, 0));
    _leds.setPixelColor(1,_leds.Color(255, 0, 0));
    _leds.fill(_leds.Color(255, 255, 255), 2, 3);
    _leds.show();
    analogWrite(MOTOR_A1, 0);
    analogWrite(MOTOR_A2, 230);
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
    _leds.clear();
    _leds.fill(_leds.Color(255, 0, 0), 0, 4);
    _leds.show();
    analogWrite(MOTOR_A1, 255);
    analogWrite(MOTOR_A2,  0);
    analogWrite(MOTOR_B1, 255);
    analogWrite(MOTOR_B2, 0);
    delay(100);
  }