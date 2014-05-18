
task main()
{
	motor[motorB]=60;
	motor[motorC]=60;
	wait1Msec(4200);

		motor[motorB]=50;
	motor[motorC]=-50;
	wait1Msec(900);

	motor[motorB]=50;
	motor[motorC]=50;
	wait1Msec(4600);

	motor[motorB]=-50;
	motor[motorC]=50;
	wait1Msec(930);

	motor[motorB]=50;
	motor[motorC]=50;
	wait1Msec(3700);

	motor[motorB]=-50;
	motor[motorC]=50;
	wait1Msec(973);

	motor[motorB]=50;
	motor[motorC]=50;
	wait1Msec(1700);





}
