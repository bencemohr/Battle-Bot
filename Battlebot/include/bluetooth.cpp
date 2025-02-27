//Commands from BT
void readBT()
{
  if (btSerial.available())
  {
    char input = btSerial.read();

    btSerial.print("Recieved command: ");
    btSerial.println(input);

    switch (input)
    {
      case 'F': 
        moveForward(1000);
        input='x';
        break;
      case 'B':
        moveBackward(1000);
        input='x';
        break;
      case 'L':
        moveLeft(1000);
        input='x';
        break;
      case 'R':
        moveRight(1000);
        input='x';
        break;
      case 'S':
        stop();
        input='x';
        btSerial.println("Returning S");
      case 'G':
        grip(2);
        input='G';
        break;
      default:
        btSerial.println("Invalid command");
        input='x';
        break;
    }
  }
}