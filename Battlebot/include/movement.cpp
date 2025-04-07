// Moving functions

// Function to move the robot backward for a specified duration
void moveBackward(long t) {
    _leds.clear(); 
    _leds.fill(_leds.Color(255, 255, 255), 0, 4); // Set all LEDs to white
    _leds.show();
    analogWrite(MOTOR_A1, 255); // Set motor A1 to full speed backward
    analogWrite(MOTOR_A2, 0);   // Stop motor A2
    analogWrite(MOTOR_B1, 0);   // Stop motor B1
    analogWrite(MOTOR_B2, 240); // Set motor B2 to full speed backward
    delay(t);                   // Move for the specified duration
}

// Function to move the robot left for a specified duration
void moveLeft(long t) {
    analogWrite(MOTOR_A1, 0);   // Stop motor A1
    analogWrite(MOTOR_A2, 230); // Set motor A2 to turn left
    analogWrite(MOTOR_B1, 180); // Set motor B1 to turn left
    analogWrite(MOTOR_B2, 0);   // Stop motor B2
    delay(t);                   // Move for the specified duration
}

// Function to make a sharp left turn for a specified duration
void moveLeftSharp(long t) {
    _leds.clear();
    _leds.setPixelColor(3, _leds.Color(255, 165, 0)); // Set LED 3 to orange
    _leds.setPixelColor(0, _leds.Color(255, 165, 0)); // Set LED 0 to orange
    _leds.show();
    analogWrite(MOTOR_A1, 0);   // Stop motor A1
    analogWrite(MOTOR_A2, 255); // Set motor A2 to full speed left
    analogWrite(MOTOR_B1, 0);   // Stop motor B1
    analogWrite(MOTOR_B2, 200); // Set motor B2 to full speed left
    delay(t);                   // Move for the specified duration
}

// Function to move the robot right for a specified duration
void moveRight(long t) {
    analogWrite(MOTOR_A1, 0);   // Stop motor A1
    analogWrite(MOTOR_A2, 150); // Set motor A2 to turn right
    analogWrite(MOTOR_B1, 255); // Set motor B1 to turn right
    analogWrite(MOTOR_B2, 0);   // Stop motor B2
    delay(t);                   // Move for the specified duration
}

// Function to make a sharp right turn for a specified duration
void moveRightSharp(long t) {
    _leds.clear();
    _leds.show();
    _leds.fill(_leds.Color(255, 165, 0), 1, 2); // Set LEDs 1 and 2 to orange
    _leds.show();
    analogWrite(MOTOR_A1, 200); // Set motor A1 to full speed right
    analogWrite(MOTOR_A2, 0);   // Stop motor A2
    analogWrite(MOTOR_B1, 255); // Set motor B1 to full speed right
    analogWrite(MOTOR_B2, 0);   // Stop motor B2
    delay(t);                   // Move for the specified duration
}

// Function to move the robot forward for a specified duration
void moveForward(long t) {
    _leds.clear();
    _leds.show();
    _leds.setPixelColor(0, _leds.Color(255, 0, 0));   // Set LED 0 to red
    _leds.setPixelColor(1, _leds.Color(255, 0, 0));   // Set LED 1 to red
    _leds.fill(_leds.Color(255, 255, 255), 2, 3);     // Set LEDs 2 and 3 to white
    _leds.show();
    analogWrite(MOTOR_A1, 0);   // Stop motor A1
    analogWrite(MOTOR_A2, 240); // Set motor A2 to full speed forward
    analogWrite(MOTOR_B1, 255); // Set motor B1 to full speed forward
    analogWrite(MOTOR_B2, 0);   // Stop motor B2
    delay(t);                   // Move for the specified duration
}

// Function to stop all motors
void stop() {
    analogWrite(MOTOR_A1, 0);   // Stop motor A1
    analogWrite(MOTOR_A2, 0);   // Stop motor A2
    analogWrite(MOTOR_B1, 0);   // Stop motor B1
    analogWrite(MOTOR_B2, 0);   // Stop motor B2
}

// Function to spin the robot in place
void spin() {
    _leds.clear();
    _leds.fill(_leds.Color(255, 0, 0), 0, 4); // Set all LEDs to red
    _leds.show();
    analogWrite(MOTOR_A1, 0);   // Stop motor A1
    analogWrite(MOTOR_A2, 255); // Set motor A2 to full speed backward
    analogWrite(MOTOR_B1, 0);   // Stop motor B1
    analogWrite(MOTOR_B2, 255); // Set motor B2 to full speed backward
    delay(70);                  // Spin for a short duration
}