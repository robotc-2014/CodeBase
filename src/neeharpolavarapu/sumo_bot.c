#pragma config(StandardModel, "RVW REMBOT")
#pragma config(RenamedStdModelMotor, motorB, B)
#pragma config(RenamedStdModelMotor, motorC, C)
int velocity =50;
int neg_vel =-50
int high_velocity =100
task main()
{
	nSyncedMotors = synchBC;

	motor [B] = velocity;
	motor [C] = neg_vel;
	wait1Msec (945);

	motor [B] = neg_vel;
	motor [C] = neg_vel;
	wait1Msec (999);

	motor [B] = neg_vel;
	motor [C] = velocity;
	wait1Msec (945);

	motor [B] = high_velocity;
	motor [C] = high_velocity;
	wait1Msec (3465);


}
