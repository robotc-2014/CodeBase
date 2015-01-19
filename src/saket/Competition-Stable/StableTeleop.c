#pragma config(Hubs,  S1, HTMotor,  HTMotor,  HTServo,  HTMotor)
#pragma config(Sensor, S1,     ,               sensorI2CMuxController)
#pragma config(Sensor, S2,     IRSeeker2,      sensorI2CCustom)
#pragma config(Sensor, S3,     gyroSensor,     sensorI2CHiTechnicGyro)
#pragma config(Motor,  motorA,           ,             tmotorNXT, openLoop, encoder)
#pragma config(Motor,  motorB,           ,             tmotorNXT, openLoop, encoder)
#pragma config(Motor,  mtr_S1_C1_1,     motorD,        tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C1_2,     motorE,        tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C2_1,     motorF,        tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C2_2,     right,         tmotorTetrix, openLoop, reversed)
#pragma config(Motor,  mtr_S1_C4_1,     motorH,        tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C4_2,     left,          tmotorTetrix, openLoop)
#pragma config(Servo,  srvo_S1_C3_1,    leftServo,               tServoNone)
#pragma config(Servo,  srvo_S1_C3_2,    servo2,               tServoNone)
#pragma config(Servo,  srvo_S1_C3_3,    servo3,               tServoNone)
#pragma config(Servo,  srvo_S1_C3_4,    servo4,               tServoNone)
#pragma config(Servo,  srvo_S1_C3_5,    servo5,               tServoNone)
#pragma config(Servo,  srvo_S1_C3_6,    rightServo,               tServoNone)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

#include "joystickdriver.c" // Joystick Driver

// Button Definitions (hex value)
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

//  Global Variables
#define duty_cycle 3
short jy1_p = 0, jy2_p = 0;
const bool kMaximumPowerLevel = 85;
const short maxjoystickvalue = 127;

short filter(short joyValue, short nMaxValue = kMaximumPowerLevel) { // Filters Joystick values with deadzoning, scales them and return as motor power output
	const short deadzone = 5;
	if(abs(joyValue) < deadzone) { // deadzoning
		return 0; }
	short direction = joyValue / abs(joyValue); // 1 or -1
	float ratio = ((joyValue * joyValue) / (maxjoystickvalue*maxjoystickvalue));
	short nScaled = (ratio * kMaximumPowerLevel) * direction;
	return nScaled;
}



void drive(short jy1, short jy2) {
	jy1 = filter(jy1);
	jy2 = filter(jy2);

	// pulse width modulation
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

	// get to target velocity without having overfeedback
	motor[left] = (0.3 * jy1) + (0.7 * motor[left]);
	motor[right] = (0.3 * jy2) + (0.7 * motor[right]);

	if (joystick.joy1_Buttons & button7){ // brakes
		motor[left] = 0;
		motor[right] = 0;
	}
	else if (joystick.joy1_Buttons & button8){ //brakes
		motor[left] = 0;
		motor[right] = 0;
	}

}

void clamp() {
	servoTarget[leftServo] = 255;     //will not work
	servoTarget[rightServo] = 0;
}

void unclamp() {
	servoTarget[leftServo] = 0;     //will not work
	servoTarget[rightServo] = 255;
}


void servos() {
	if (joystick.joy1_Buttons & button2){ // for servos to drag rolling goal
		clamp();
	}
	else if (joystick.joy1_Buttons & button3){
		unclamp();
	}

}


void initializeRobot() {
  unclamp();
	return;
}


task main () {
	motor[left] = 0; // motors are off at start
	motor[right] = 0;

	initializeRobot();
	waitForStart();

	while (true) {

		getJoystickSettings(joystick); // update controller data feed
		drive(joystick.joy1_y1, joystick.joy1_y2);
		servos();
		wait1Msec(10); // for code execution stablization
	}
}
