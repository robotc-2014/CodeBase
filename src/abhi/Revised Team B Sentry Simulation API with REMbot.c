#pragma config(Sensor, S1,     touch,          sensorTouch)
#pragma config(Sensor, S2,     gyro,           sensorI2CHiTechnicGyro)
#pragma config(Sensor, S3,     light,          sensorLightActive)
#pragma config(Sensor, S4,     sonar,          sensorSONAR)
#pragma config(Motor,  motorA,          gripperMotor,  tmotorNXT, openLoop, encoder)
#pragma config(Motor,  motorB,          rightMotor,    tmotorNXT, openLoop, encoder)
#pragma config(Motor,  motorC,          leftMotor,     tmotorNXT, openLoop, encoder)




void moveForward (int distanceInInches)
{
	nMotorEncoder[leftMotor] = 0;
	nMotorEncoder[rightMotor] = 0;


	while ( nMotorEncoder[rightMotor] < (distanceInInches/0.01924))
	{
		motor[rightMotor] = 50;
		motor[leftMotor] = 50;
	}


	motor[leftMotor] = 0;
	motor[rightMotor] = 0;


	nMotorEncoder[leftMotor] = 0;
	nMotorEncoder[rightMotor] = 0;
}


void turnRight ()
{
	nMotorEncoder[leftMotor] = 0;
	nMotorEncoder[rightMotor] = 0;


	while (nMotorEncoder[rightMotor]  < 120)
	{
		motor[rightMotor] = 0;
		motor[leftMotor] = 50;
	}


	motor[leftMotor] = 0;
	motor[rightMotor] = 0;


	nMotorEncoder[leftMotor] = 0;
	nMotorEncoder[rightMotor] = 0;


}


void turnLeft ()
{
	nMotorEncoder[leftMotor] = 0;
	nMotorEncoder[rightMotor] = 0;


		while (nMotorEncoder[rightMotor] <  400)
	{
		motor[rightMotor] = 50;
		motor[leftMotor] = -50;
	}


	motor[leftMotor] = 0;
	motor[rightMotor] = 0;


	nMotorEncoder[leftMotor] = 0;
	nMotorEncoder[rightMotor] = 0;


}
