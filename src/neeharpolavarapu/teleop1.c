#pragma config(Hubs,  S1, HTMotor,  HTServo,  none,     none)
#pragma config(Sensor, S1,     ,               sensorI2CMuxController)
#pragma config(Motor,  mtr_S1_C1_1,     right,         tmotorTetrix, openLoop, reversed)
#pragma config(Motor,  mtr_S1_C1_2,     left,          tmotorTetrix, openLoop)
#pragma config(Servo,  srvo_S1_C2_1,    servo1,               tServoNone)
#pragma config(Servo,  srvo_S1_C2_2,    servo2,               tServoNone)
#pragma config(Servo,  srvo_S1_C2_3,    servo3,               tServoNone)
#pragma config(Servo,  srvo_S1_C2_4,    servo4,               tServoNone)
#pragma config(Servo,  srvo_S1_C2_5,    servo5,               tServoNone)
#pragma config(Servo,  srvo_S1_C2_6,    servo6,               tServoNone)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

#include "joystickdriver.c"

typedef enum
{
	kDriveTank     = 0,
	kDriveArcade   = 1
} TDriveType;


// Controls:
// Button 7 & 8 are brakes, press either one or both
// Button 6 is turbo mode
// Button 2 is to change driving style
// DPAD 0 -> logarithmic scaling, DPAD 2 -> modified logarithmic scaling, DPAD 4 -> cubic scaling, DPAD 6 -> linear scaling

// button defshortions
#define button1   0x01
#define button2   0x02
#define button3   0x04
#define button4   0x08
#define button5   0x10
#define button6   0x20
#define button7   0x40
#define button8   0x80
#define button9  0x100
#define button10 0x200

short jy1_p = 0, jy2_p = 0;

// Half Power
bool half_power = false;

//Logarithmic Scaling
bool bLogarithmicScale = true; // logarithmic like scale with adjusted range for larger deadband at 0
bool normal_logarithmic_scaling = false; // logarithmic scaling

// Cubic Scaling
bool cubic_scaling = false; // cubic scaling

// Constants
const bool kMaximumPowerLevel = 100;
const bool pwm = true; // enable pulse width modulation cycle adjustments

#define duty_cycle 3 //Limits d/dt Duty Cycle (in percent)

short filter(short joyValue, short nMaxValue = kMaximumPowerLevel) { // function filters joystick data with deadzone, scales it, and returns a motor power
	const short deadzone = 5;
	if(abs(joyValue) < deadzone) { // deadzoning
		return 0;
	}
	if (bLogarithmicScale) // logarithmic scaling with adjusted range for larger deadband at 0
	{
		static const short nLogScale[17] =
		{
			0,   5,   9,   10,
			12,  15,  18,  24,
			30,  36,  43,  50,
			60,  72,  85,  100,
			100
		};
		short nScaled;
		nScaled = joyValue;
		nScaled /= 7.9;
		if (nScaled >= 0) {
			nScaled = nLogScale[nScaled];
		}
		else {
			nScaled = - nLogScale[ - nScaled];
		}
		nScaled *= nMaxValue;
		nScaled /= 100;
		return nScaled;
	}
	else if (normal_logarithmic_scaling) { // regular logarithmic scaling for precise and more fine grain control at lower speeds
		const float MAX_JOY_VAL = 127.0;
		short direction = joyValue / abs(joyValue); // 1 or -1
		float ratio = ((joyValue * joyValue) / (MAX_JOY_VAL * MAX_JOY_VAL));
		short nScaled = (ratio * nMaxValue) * direction;
		return nScaled;
	}
	else if (cubic_scaling) { // cubic scaling
		short nScaled = (float) (((float) joyValue) / 127);
		pow(nScaled, 3);
		nScaled *= 100;
		return nScaled;
	}
	else // if logarithmic scaling and exponential scaling is not desired --> linear scaling is default
	{
		short nScaled = 100 * ((float) (((float) joyValue) / 127));
		return nScaled;
	}
}

//Gets joystick values, filters them, applies pwm cycle adjustments, and sends to motors.
void drive(short jy1, short jy2) {
	jy1 = filter(jy1);
	jy2 = filter(jy2);
	if (half_power) {
		jy1 /= 2;
		jy2 /= 2;
	}
	if(pwm) {
		short delta = jy1 - jy1_p;

		if((delta) * (jy1) > 0 && abs(delta) > duty_cycle ) {
			jy1 = (abs(delta)/delta)*duty_cycle + jy1_p;
		}

		delta = jy2 - jy2_p;

		if((delta) * (jy2) > 0 && abs(delta) > duty_cycle ) {
			jy2 = (abs(delta)/delta)*duty_cycle + jy2_p;
		}

		jy1_p = jy1;
		jy2_p = jy2;
	}

	motor[left] = (0.3 * jy1) + (0.7 * motor[left]);
	motor[right] = (0.3 * jy2) + (0.7 * motor[right]);

}

void arcade(short x, short y) // arcade mode: uses just right joystick to steer robot
{
	short powY;

	powY = filter(y); // convert joystick -128 to 127 range to -100 to 100 for powering motors
	if (half_power) {
		powY /= 2;
	}

	if (x < 0) //  if x negative, turning left; otherwise, turning right
	{
		motor[left]  = (powY * (127 + (2 * x))/127); // left motor reduced for right turn
		motor[right] = powY;												 // right motor not changed
	}
	else
	{
		motor[right] = (powY * (127 - (2 * x))/127); // right motor reduced for left turn
		motor[left] = powY;													 // left motor not changed
	}
}


void hatAction() { //Checks hat and changes scaling if pressed. Returns zero if pad is not pressed, non-zero if some direction is pressed.

	switch(joystick.joy1_TopHat) {
	case -1: //not pressed
		break;

	case 0:
		bLogarithmicScale = false;
		normal_logarithmic_scaling = true;
		cubic_scaling = false;
		break;

	case 2:
		bLogarithmicScale = true;
		normal_logarithmic_scaling = false;
		cubic_scaling = false;
		break;

	case 4:
		bLogarithmicScale = false;
		normal_logarithmic_scaling = false;
		cubic_scaling = true;
		break;

	case 6:
		bLogarithmicScale = false;
		normal_logarithmic_scaling = false;
		cubic_scaling = false;
		break;

	}
}

void initializeRobot() {
	return;
}

task main()
{
	motor[motorD] = 0; // motor is powered off
	motor[motorE] = 0; // motor is powered off

	TDriveType DriveStyle = kDriveTank; // default drive mode

	initializeRobot(); // initialization routine
	waitForStart(); // wait for start

	while (true)
	{
		getJoystickSettings(joystick); // get joystick values
		hatAction();
		switch (DriveStyle) // run driving function based on current mode
		{
		case kDriveTank:
			drive(joystick.joy1_y1, joystick.joy1_y2);
			break;

		case kDriveArcade:
			arcade(joystick.joy1_x2, joystick.joy1_y2);
			break;
		}
		if (joystick.joy1_Buttons & button7){ // brakes
			motor[left] = 0;
			motor[right] = 0;
		}
		else if (joystick.joy1_Buttons & button8){ //brakes
			motor[left] = 0;
			motor[right] = 0;
		}
		if (joystick.joy1_Buttons & button6){ //turbo mode, press once to turn on or off
			if (half_power == true) {
				half_power = false;
			}
			else {
				half_power = true;
			}
		}
		if (joystick.joy1_Buttons & button2) // choose drive style, press once to change drive style
		{
			if (DriveStyle != kDriveTank)
			{
				DriveStyle = kDriveTank;
				playSound(soundBeepBeep);
			}
			else
			{
				DriveStyle = kDriveArcade;
				playSound(soundBeepBeep);
			}
		}

		wait1Msec(10); // for stable code execution
	}
}

//Todo:
// Test it
// make unit tests