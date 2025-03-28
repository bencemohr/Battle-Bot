long senseLeft() {
    //Sonar control and distance calculations
    digitalWrite(SENSOR_TRIGGER_LEFT, LOW);
    delayMicroseconds(2);
  
    digitalWrite(SENSOR_TRIGGER_LEFT, HIGH);
    delayMicroseconds(10);
    digitalWrite(SENSOR_TRIGGER_LEFT, LOW);
    
    long duration = pulseIn(SENSOR_ECHO_LEFT, HIGH);
    long distanceLeft = duration * 0.034 / 2;

    btSerial.println(distanceLeft);
  
    return distanceLeft;
  }