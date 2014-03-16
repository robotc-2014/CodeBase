task main()
{
	int basespeed;
	basespeed=70;
	float modifier;

	motor[motorB] = -50;
	motor[motorC] = 50;
	wait1Msec(270);

	for(int i=135;i<1800;i++)
	{
		modifier=18*sinDegrees(i);
		motor[motorB] = 1.4*(50-modifier);
		motor[motorC] = 1.4*(50+modifier);
		wait1Msec(25);
	}

}
