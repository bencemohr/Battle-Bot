// Line sensor calibration

void calibrate(){
    bool quit = false;
    int state = 0;
    int interval = 5000;
    int flash = 1000;
    unsigned long nextInterval = 0;
    unsigned long nextFlash = 0;
    int led = 4;
    while (quit == false)
    {
        if (state == 0)
        {
            _leds.fill(_leds.Color(255,255,255),0,4);
            _leds.show();

            delay(450);
            _leds.clear();
            _leds.show();
            delay(450);
            btSerial.println("calibrate runs");
            if (digitalRead(BUTTON1) == 0){
                state++;
            }
        }
        else if (state == 1)
        {
            /* Collect white reflection data with loading animation. */
            if (millis() >= nextInterval){
                nextInterval = millis() + interval;
                while (millis() < nextInterval)
                {
                    btSerial.println("i love croissants");
                    if (millis() >= nextFlash){
                        nextFlash = millis() + flash;
                        _leds.setPixelColor(led , _leds.Color(255,255,0));
                        _leds.show();
                        led--;
                    }        
                }
            }
            _leds.clear();
            _leds.show();
            state++;
        }
        else if (state == 2)
        {
            /* Wait for new button press, flash white across each other */
            _leds.fill(_leds.Color(255,144,0),0,4);
            _leds.show();
        }
        
        if (readBT() == 'S')
        {
            quit = true;
        }
    }
}