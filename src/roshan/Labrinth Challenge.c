
task main()
{
	motor[motorC] = 50;
	motor[motorB] = 50;
	wait1Msec (4000);

	motor[motorC] = 25;
	motor[motorB] = 50;
	wait1Msec (2500);

	motor[motorC] = 50;
	motor[motorB] = 50;
	wait1Msec (3500);

	motor[motorB] = 25;
	motor[motorC] = 50;
	wait1Msec (2500);

	motor[motorB] = -100;
	motor[motorC] = 100;
	wait1Msec (350);

	motor[motorB] = 100;
	motor[motorC] = 100;
	wait1Msec (1500);
}
