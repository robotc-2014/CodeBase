#pragma config(StandardModel, "RVW REMBOT")
#pragma config(RenamedStdModelMotor, motorB, B)
#pragma config(RenamedStdModelMotor, motorC, C)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//
int a=0 ;
int velocity =75;
void gototheleft()
 {
  motor[C]=velocity;
  motor[B]=0;
	wait10Msec(125);
	}

task main()
{
	nMotorEncoder[C]=0;
	nMotorEncoder[B]=0;
while(a<8)
{
while(nMotorEncoder[B] <=1512|| nMotorEncoder[C] <= 1512)
	{
	motor[B]=velocity;
	motor[C]=velocity;
	wait10Msec(1);
	}
	gototheleft();
	nMotorEncoder[C]=0;
	nMotorEncoder[B]=0;
	a++;
}
}

