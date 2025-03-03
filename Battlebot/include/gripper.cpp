void grip(int pulse)
{
    while (_Grip == true)    
    {
        static long unsigned int timer = 0;
        static int lastPulse = 0;
        if (millis()>timer)
        {
            if (pulse > 0)
            {
                lastPulse = pulse;
            }
            else
            {
                pulse = lastPulse;
            }
            
            digitalWrite(GRIPPER, HIGH);
            delayMicroseconds(pulse);
            digitalWrite(GRIPPER, LOW);
            timer=millis()+20;
        }
    }


}