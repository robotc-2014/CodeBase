#pragma config(Motor,  motorB,          rm,            tmotorNXT, PIDControl, encoder)
#pragma config(Motor,  motorC,          lm,            tmotorNXT, PIDControl, encoder)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

task main()
{

	motor[rm] = 100;
	motor[lm] = 100;
	wait1Msec(3000);

	motor[lm] = -100;
	wait1Msec(412);

  motor[lm] = 100;
  wait1Msec(2100);

  motor[rm] = -100;
  wait1Msec(380);

  motor[rm] = 100;
  wait1Msec(1200);

  motor[rm] = -100;
  wait1Msec(390);

  motor[rm] = 100;
  wait1Msec(10000);

}