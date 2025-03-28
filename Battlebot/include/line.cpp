void readLine(){
    btSerial.println(analogRead(LINE3));
    btSerial.println(analogRead(LINE4));
    btSerial.println(analogRead(LINE5));
    btSerial.println("----BREAK LINE---");

    if (analogRead(LINE4)>750 || analogRead(LINE3)>750 || analogRead(LINE5)>750)
    {
        moveForward(1);
    }

    else
    {
        moveBackward(3);
    }
}