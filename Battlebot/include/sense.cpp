long measure(){
    digitalWrite(SENSOR_TRIGGER_RIGHT, LOW);
    digitalWrite(SENSOR_TRIGGER_LEFT, LOW);
    digitalWrite(SENSOR_TRIGGER_FRONT, LOW);
    delayMicroseconds(2);
  
    digitalWrite(SENSOR_TRIGGER_RIGHT, HIGH);
    digitalWrite(SENSOR_TRIGGER_LEFT, HIGH);
    digitalWrite(SENSOR_TRIGGER_FRONT, HIGH);
    delayMicroseconds(10);
    digitalWrite(SENSOR_TRIGGER_RIGHT, LOW);
    digitalWrite(SENSOR_TRIGGER_LEFT, LOW);
    digitalWrite(SENSOR_TRIGGER_FRONT, LOW);
    
    long durationLeft = pulseIn(SENSOR_ECHO_LEFT, HIGH);
    long durationFront = pulseIn(SENSOR_ECHO_FRONT, HIGH);
    long durationRight = pulseIn(SENSOR_ECHO_RIGHT, HIGH);
    long distanceRight = durationRight * 0.034 / 2;
    long distanceLeft = durationLeft * 0.034 / 2;
    long distanceFront = durationFront * 0.034 / 2;


  
    return distanceRight, distanceLeft, distanceFront;
}