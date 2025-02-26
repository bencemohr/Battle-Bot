//Commands from BT
char readBT()
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
        break;
      case 'B':
        moveBackward(1000);
        break;
      case 'L':
        moveLeft(1000);
        break;
      case 'R':
        moveRight(1000);
        break;
      case 'S':
        setup();
        btSerial.println("Returning S");
        return 'S';
      default:
        btSerial.println("Invalid command");
        break;
    }
  }
  return NULL;
}