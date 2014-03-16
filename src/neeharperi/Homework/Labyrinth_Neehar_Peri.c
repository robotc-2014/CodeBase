task main()
{

nSyncedMotors = synchBC;
nSyncedTurnRatio = 100;

int motorCPower = 50;

	motor[motorC] = motorCPower; //go forward
	motor[motorB] = 50;
	wait1Msec(5000);

	motor[motorC] = -50; //turn left
	motor[motorB] = 50;
	wait1Msec(950);

	motor[motorC] = 50; //go forward
	motor[motorB] = 50;
	wait1Msec(5000);

	motor[motorC] = -50; //turn left
	motor[motorB] = 50;
	wait1Msec(950);

	motor[motorC] = 50; //go forward
	motor[motorB] = 50;
	wait1Msec(4500);

	motor[motorC] = -50; //turn left
	motor[motorB] = 50;
	wait1Msec(950);

	motor[motorC] = 50; //go forward
	motor[motorB] = 50;
	wait1Msec(2500);

	motor[motorC] = -50; //turn left
	motor[motorB] = 50;
	wait1Msec(950);

	motor[motorC] = 50; //go forward
	motor[motorB] = 50;
	wait1Msec(2000);

	motor[motorC] = -50; //go backwards
	motor[motorB] = -50;
	wait1Msec(2000);

	motor[motorC] = -50; //turn left
	motor[motorB] = 50;
	wait1Msec(950);

	motor[motorC] = 50; //go forwards
	motor[motorB] = 50;
	wait1Msec(2000);

	motor[motorC] = 50; //turn right
	motor[motorB] = -50;
	wait1Msec(950);

	motor[motorC] = 50; //go forwards
	motor[motorB] = 50;
	wait1Msec(10000);

	motor[motorC] = 50; //turn right
	motor[motorB] = -50;
	wait1Msec(950);

	motor[motorC] = 50; //go forwards to finish
	motor[motorB] = 50;
	wait1Msec(3000);



}
