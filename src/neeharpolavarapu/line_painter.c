void drawLine(int distance);
void penDown();
void penUp();
void dottedLine(int dotted_distance);

task main()
{
  int testDistance = 300;
  drawLine(testDistance);
  dottedLine(testDistance);
  
  //fix task main to include the dotted lines and not have them all be solid lines
  
  // turnLeft();
  // drawLine(8);
  // turnRight();
  // drawLine(20);
  // turnRight();
  // drawLine(8);
  // turnLeft();
  // drawLine(5);
}

void dottedLine(int dotted_distance) {
  penDown();
  
  //put some code here that makes the pen do dotted lines
  
  //reset encoders
  nMotorEnocder[motorB] = 0;
  nMotorEnocder[motorC] = 0;
  motor[motorB] = 50;
  motor[motorC] = 50;
  while (nMotorEncoder[motorB] < distance) {
  }
  penUp();
  motor[motorB] = 0;
  motor[motorC] = 0;
}

void drawLine(int distance) {
  penDown();
  //reset encoders
  nMotorEnocder[motorB] = 0;
  nMotorEnocder[motorC] = 0;
  motor[motorB] = 50;
  motor[motorC] = 50;
  while (nMotorEncoder[motorB] < distance) {
  }
  penUp();
  motor[motorB] = 0;
  motor[motorC] = 0;
}

void penDown() {
  motor[motorA] = 50;
  wait1Msec(100);
  motor[motorA] = 0;
}

void penUp() {
  motor[motorA] = -50;
  wait1Msec(100);
  motor[motorA] = 0;
}
//End of Line Painter Challenge
