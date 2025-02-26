//Object avoidance
void avoid(long distance) {
    //Go around object
    if (distance<18){
      moveBackward(200);
      moveRight(900);
      moveForward(1000);
      moveLeft(900);
      moveForward(1000);
      moveLeft(900);
      moveForward(1000);
      moveRight(900);
      distance = sense();
    }
    else{
      //Keep forwards
      sense();
      moveForward(500);
    }
}