
task main()
{
	while (nMotorEncoder[motorB] != 14888)
	{	nMotorEncoder[motorB]=0; //This allows the encoders to keep refreshing with each turn
		while (nMotorEncoder[motorB] != 1827)
		{
		  motor[motorB]=50;
    	motor[motorC]=-50; //Until the encoder hits 1827, the robot will move straight and turn
    }
  		while (nMotorEncoder[motorB] != 1861)
  		{
  			motor[motorB]=0;
  			motor[motorC]=-50; //Until the encoder hits 1861 from 1827, the robot will turn. Then, the encoder will go to zero and the loop continues.
  		}
	}
}

//Final Note: This program bugs frequently on Virtual Worlds (at least mine), so keep hitting the refresh button- this program does work.
