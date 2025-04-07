// Function to control the gripper using pulse width modulation (PWM)
void grip(int pulse)
{
    // Static variables to store the timer and the last pulse value
    static long unsigned int timer = 0; // Timer to control the gripper's update interval
    static int lastPulse = 0;           // Stores the last pulse value for continuity

    // Check if the current time exceeds the timer
    if (millis() > timer)
    {
        // If a valid pulse value is provided, update the lastPulse
        if (pulse > 0)
        {
            lastPulse = pulse; // Store the current pulse value
        }
        else
        {
            // If no valid pulse is provided, use the lastPulse value
            pulse = lastPulse;
        }

        // Send a HIGH signal to the gripper pin for the duration of the pulse
        digitalWrite(GRIPPER, HIGH);
        delayMicroseconds(pulse); // Keep the pin HIGH for the specified pulse duration

        // Send a LOW signal to the gripper pin to complete the PWM cycle
        digitalWrite(GRIPPER, LOW);

        // Update the timer to ensure the gripper is updated every 20 milliseconds
        timer = millis() + 20;
    }
}