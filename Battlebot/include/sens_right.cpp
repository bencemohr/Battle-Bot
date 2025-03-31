long senseRight() {
    //Sonar control and distance calculations
    digitalWrite(SENSOR_TRIGGER_RIGHT, LOW);
    delayMicroseconds(2);
  
    digitalWrite(SENSOR_TRIGGER_RIGHT, HIGH);
    delayMicroseconds(10);
    digitalWrite(SENSOR_TRIGGER_RIGHT, LOW);
    
    long duration = pulseIn(SENSOR_ECHO_RIGHT, HIGH);
    long distanceRight = duration * 0.034 / 2;
  
    return distanceRight;
  }