
task main()
{
while(1)
{
motor[motorB] = 50;
motor[motorC] = -50;
wait1Msec(500);
motor[motorB] = 0;
motor[motorC] = 0;
wait1Msec(100);
motor[motorB] = -50;
motor[motorC] = 50;
wait1Msec(500);
motor[motorB] = 0;
motor[motorC] = 0;
wait1Msec(100);
}
}
