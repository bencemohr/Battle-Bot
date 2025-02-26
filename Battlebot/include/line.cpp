void readLine(){
    btSerial.println(analogRead(LINE1));
    btSerial.println(analogRead(LINE2));
    btSerial.println(analogRead(LINE3));
    btSerial.println(analogRead(LINE4));
    btSerial.println(analogRead(LINE5));
    btSerial.println(analogRead(LINE6));
    btSerial.println(analogRead(LINE7));
    btSerial.println("----BREAK LINE---");
    delay(1000);
}