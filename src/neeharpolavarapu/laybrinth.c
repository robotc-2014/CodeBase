#pragma config(StandardModel, "RVW MANTIS")
#pragma config(RenamedStdModelMotor, motorB, leftMotor)
#pragma config(RenamedStdModelMotor, motorC, rightMotor)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

task main()			
{
	nSyncedMotors = synchBC;

	motor[leftMotor] = 100;			
	motor[rightMotor] = 100;			
	wait10Msec(350);			

	motor[leftMotor] = 50;			
	motor[rightMotor] = -50;			
	wait10Msec(95);			

	motor[leftMotor] = 100;			
	motor[rightMotor] = 100;			
	wait10Msec(210);			

	motor[leftMotor] = -50;			
	motor[rightMotor] = 50;			
	wait10Msec(95);			

	motor[leftMotor] = 100;			
	motor[rightMotor] = 100;			
	wait10Msec(100);			

	motor[leftMotor] = -50;			
	motor[rightMotor] = 50;			
	wait10Msec(95);			

	motor[leftMotor] = 100;			
	motor[rightMotor] = 100;			
	wait10Msec(100);			

	}			
