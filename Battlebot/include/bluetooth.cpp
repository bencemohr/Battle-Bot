//Commands from BT
void readBT()
{
  if (btSerial.available())
  {
    char input = btSerial.read();

    btSerial.print("Received command: ");
    btSerial.println(input);

    switch (input)
    {
      case 'F': 
        moveForward(1000);
        input='x';
        btSerial.println("Going forward");
        break;
      case 'B':
        moveBackward(1000);
        input='x';
        btSerial.println("Going backwards");
        break;
      case 'L':
        moveLeft(1000);
        input='x';
        btSerial.println("Turning Left");
        break;
      case 'R':
        moveRight(1000);
        input='x';
        btSerial.println("Turning Right");
        break;
      case 'S':
        stop();
        input='x';
        btSerial.println("Stopping");
      // case 'G':
        // grip();
        // input='x';
        // btSerial.println("Gripping");
        // break;
      default:
        btSerial.println("Invalid command");
        input='x';
        break;
    }
  }
}