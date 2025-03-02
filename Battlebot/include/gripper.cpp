void grip() 
{
    gripper.attach(9);
    gripper.write(180);
    delay(1000);
    gripper.write(90);
    delay(1000);
    gripper.write(0);
    delay(1000);
    gripper.write(90);
    delay(200);
    gripper.detach();
}