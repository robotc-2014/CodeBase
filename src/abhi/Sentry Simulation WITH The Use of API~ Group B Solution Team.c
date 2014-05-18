void moveForward (int distanceInInches);
void turnRight();
void turnLeft();

task main ()
{

	nMotorEncoder[motorB]=0;
	moveForward (1800);
	turnRight ();
	nMotorEncoder[motorB]=0;
	moveForward (1800);
	turnRight ();
	nMotorEncoder[motorB]=0;
	moveForward (1800);
	turnRight ();
	nMotorEncoder[motorB]=0;
	moveForward (1800);
	turnRight ();
}



void moveForward (int distanceInInches)
{	nMotorEncoder[motorB] = distanceInInches;

			while (nMotorEncoder[motorB] != 1820) //I would've used distanceInInches here, but for some reason VW was bugging, so for the sake of it, I put nMotorEncoder
				{
					motor[motorB]=50;
					motor[motorC]=-50;
				}
					turnRight();
}

void turnRight()
{
				while (nMotorEncoder[motorB] != 1854)
				{
						motor[motorB]=0;
						motor[motorC]=-50;
					}

}

//Like Last time, please keep pushing the refresh button as VW bugs.
