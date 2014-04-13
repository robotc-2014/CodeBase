void leftturn();
void rightturn();
void penup();
void pendown();
void inchmove();
void linemove(int distanceininch, bool draw);


task main()
{
	linemove(5,true);

}

void leftturn()
{
	motor[motorB]=50;
	motor[motorC]=-50;
	wait1Msec(900);
}

void rightturn()
{
	motor[motorB]=-50;
	motor[motorC]=50;
	wait1Msec(900);
}

void linemove(int distanceininch, bool draw)
{
	int distance;
	distance=0;
	while (distance < distanceininch)
	{
		if (draw==true)
		{
			penup();
		}

		inchmove();

		if (draw==true)
		{
			pendown();
		}

		distance=distance+1;

		if (distance != distanceininch)
		{
			inchmove();
			distance=distance+1;
		}
	}
}

void inchmove()
{
	nMotorEncoder[motorB]=0;
	while (nMotorEncoder[motorC]<52)
	{
		motor[motorB]=50;
		motor[motorC]=50;
	}
	motor[motorB]=0;
	motor[motorC]=0;
}

void penup()
{
  motor[motorA] = -50;
  wait1Msec(100);
  motor[motorA] = 0;
}

void pendown()
{
  motor[motorA] = 50;
  wait1Msec(100);
  motor[motorA] = 0;
}
