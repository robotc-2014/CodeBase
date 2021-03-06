#pragma config(Motor,  motorB,          right,         tmotorNXT, PIDControl, encoder)
#pragma config(Motor,  motorC,          left,          tmotorNXT, PIDControl, encoder)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

int x = 0;
int motorSpeed = 75;

void leftTurn()
{
	motor[right] = 0;
	motor[left] = motorSpeed;
	wait10Msec(120);
}

task main()
{
	nMotorEncoder[left] = 0;
	nMotorEncoder[right] = 0;
	while (x<8)
	{
		while (nMotorEncoder[left]<1510 || nMotorEncoder[right]<1510)
			{
				motor[left] = motorSpeed;
				motor[right] = motorSpeed;
				wait10Msec(1);
			}
			leftTurn();
			nMotorEncoder[left] = 0;
			nMotorEncoder[right] = 0;
			x++;
		}
}
