
task main()
{
for (int i = 1; i <= 8; i++) //initiate a for loop
{
	int mPower = 100; //asign a variable to power for each motor

	nSyncedMotors = synchBC; //synch the two together
	motor[motorB] = mPower;
	motor[motorC] = mPower;
	wait1Msec (2500);

	switch (i) //a switch statement to indicate
	{
		case 1: //counter i increments everytime so I created a definition for each increment
			motor[motorB] = 0;
			motor[motorC] = (mPower - 50);
			wait1Msec (1875);
			break;
		case 2: //these cases represent turns made in the program
				motor[motorB] = 0;
				motor[motorC] = (mPower - 50);
				wait1Msec (1875);
				break;
		case 3:
				motor[motorB] = 0;
				motor[motorC] = (mPower - 50);
				wait1Msec (1505);
				break;
		case 4:
				motor[motorB] = 0;
				motor[motorC] = (mPower - 50);
				wait1Msec (2000);
				break;
		case 5:
				motor[motorB] = 0;
				motor[motorC] = (mPower - 50);
				wait1Msec (1600);
				break;
		case 6:
				motor[motorB] = 0;
				motor[motorC] = (mPower - 50);
				wait1Msec (1650);
				break;
		case 7:
				motor[motorB] = 0;
				motor[motorC] = (mPower - 50);
				wait1Msec (2000);
				break;
		case 8:
				motor[motorB] = 0;
				motor[motorC] = (mPower - 50);
				wait1Msec (2000);
				break;
	}
}

}
