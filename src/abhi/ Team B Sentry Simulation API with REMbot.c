#pragma config(Sensor, S1,     touch,          sensorTouch)
#pragma config(Sensor, S2,     gyro,           sensorI2CHiTechnicGyro)
#pragma config(Sensor, S3,     light,          sensorLightActive)
#pragma config(Sensor, S4,     sonar,          sensorSONAR)
#pragma config(Motor,  motorA,          gripperMotor,  tmotorNXT, PIDControl, encoder)
#pragma config(Motor,  motorB,          rightMotor,    tmotorNXT, PIDControl, encoder)
#pragma config(Motor,  motorC,          leftMotor,     tmotorNXT, PIDControl, encoder)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

// Encoder Class
float rightmotorDistance ()
{
	return nMotorEncoder[rightMotor];
}
float leftmotorDistance()
{
	return nMotorEncoder[leftMotor];
}

void resetleftMotorDistance()
{
	nMotorEncoder[leftMotor] = 0;
}

void resetrightMotorDistance ()
{
	nMotorEncoder[rightMotor] = 0;
}
//------------------------------------------------------

// Motors Class
void rightMotorOn50Power()
{
		motor[rightMotor] = 50;
}

void leftMotorOn50Power()
{
	motor[leftMotor] = 50;
}

void rightMotorOn0Power()
{
	motor[rightMotor] = 0;
}

void leftMotorOn0Power()
{
	motor[leftMotor] = 0;
}
//-------------------------------------------------------------
//Movement Commands

void moveForward (int distanceInInches)
{
	resetleftMotorDistance();
	resetrightMotorDistance();

	while (rightmotorDistance() < (distanceInInches / 0.01924))
	{

	   rightMotorOn50Power();
	   leftMotorOn50Power();
	}
		rightMotorOn0Power();
		leftMotorOn0Power();
		resetleftMotorDistance();
		resetrightMotorDistance();

}


void turnRight ()
{
	resetleftMotorDistance();
	resetrightMotorDistance();

	while (rightmotorDistance() < 120)
	{
		rightMotorOn0Power();
		leftMotorOn50Power();
	}
		rightMotorOn0Power();
		leftMotorOn0Power();
		resetleftMotorDistance();
		resetrightMotorDistance();


}


void turnLeft ()
{
	resetleftMotorDistance();
	resetrightMotorDistance();


		while (leftmotorDistance() <  120)
	{
		rightMotorOn50Power();
		leftMotorOn0Power();
	}

		rightMotorOn0Power();
		leftMotorOn0Power();
		resetleftMotorDistance();
		resetrightMotorDistance();

}