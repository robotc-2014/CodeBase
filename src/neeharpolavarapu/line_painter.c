void drawLine(int distance);
void penDown();
void penUp();

task main()
{
  int testDistance = 300;
  drawLine(testDistance);
  // turnLeft();
  // drawLine(8);
  // turnRight();
  // drawLine(20);
  // turnRight();
  // drawLine(8);
  // turnLeft();
  // drawLine(5);
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
