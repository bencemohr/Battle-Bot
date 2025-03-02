void readLine(){
    btSerial.println(analogRead(LINE1));
    btSerial.println(analogRead(LINE2));
    btSerial.println(analogRead(LINE3));
    btSerial.println(analogRead(LINE4));
    btSerial.println(analogRead(LINE5));
    btSerial.println(analogRead(LINE6));
    btSerial.println(analogRead(LINE7));
    btSerial.println("----BREAK LINE---");

    if (analogRead(LINE4)>750 || analogRead(LINE3)>750 || analogRead(LINE5)>750)
    {
        moveForward(1);
    }

    else if (analogRead(LINE1)>750)
    {
        moveRightSharp(1);
    }

    else if (analogRead(LINE7)>750)
    {
        moveLeftSharp(1);
    }

    else if (analogRead(LINE2)>750)
    {
        moveRight(1);
    }     

    else if (analogRead(LINE6)>750)
    {
        moveLeft(1);
    }

    else
    {
        moveBackward(3);
    }
}