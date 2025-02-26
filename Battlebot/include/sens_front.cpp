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