long sense() {
    //Sonar control and distance calculations
    digitalWrite(SENSOR_TRIGGER_FRONT, LOW);
    delayMicroseconds(2);
  
    digitalWrite(SENSOR_TRIGGER_FRONT, HIGH);
    delayMicroseconds(10);
    digitalWrite(SENSOR_TRIGGER_FRONT, LOW);
    
    long duration = pulseIn(SENSOR_ECHO_FRONT, HIGH);
    long distance = duration * 0.034 / 2;
  
    return distance;
  }