void readLine(){
    if (analogRead(LINE4)>750 || analogRead(LINE3)>750 || analogRead(LINE5)>750)
    {
        moveForward(1);
    }

    else
    {
        moveBackward(3);
    }
}