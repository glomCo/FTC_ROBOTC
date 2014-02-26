/********************************************
* arrow keys = movement											*
* Y = start flag thing											*
*	A = Stop flag thing												*
*	Original Wibbly Wobbly Code:							*
* motor[motorD] = joystick.joy1_y1;					*
* motor[motorE] = joystick.joy1_y2;					*
*																						*
*																						*
* Ben Kreger 2013														*
*********************************************/
#pragma config(Hubs,  S1, HTMotor,  HTServo,  none,     none)
#pragma config(Sensor, S1,     ,               sensorI2CMuxController)
#pragma config(Motor,  mtr_S1_C1_1,     motorD,        tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C1_2,     motorE,        tmotorTetrix, openLoop)
#pragma config(Servo,  srvo_S1_C2_1,    servo1,               tServoNone)
#pragma config(Servo,  srvo_S1_C2_2,    servo2,               tServoNone)
#pragma config(Servo,  srvo_S1_C2_3,    servo3,               tServoNone)
#pragma config(Servo,  srvo_S1_C2_4,    servo4,               tServoNone)
#pragma config(Servo,  srvo_S1_C2_5,    servo5,               tServoNone)
#pragma config(Servo,  srvo_S1_C2_6,    servo6,               tServoNone)


#include "JoystickDriver.c"



void forward(int m) {
	int cake = m - m - m;
    motor[motorD] = cake; // forward:
    motor[motorE] = m;
    wait1Msec(300);
}

void backward(int m) {
	int cake = m - m - m;
    motor[motorD] = m;
    motor[motorE] = cake;
    wait1Msec(50);


}
void left(int m) { //One way
    motor[motorD] = m;
    motor[motorE] = m;
    wait1Msec(50);


}
void right(int m) {	//Other way
	int cake = m - m - m;
    motor[motorD] = cake;
    motor[motorE] = cake;
    wait1Msec(50);


}
void stop() {	//Halt
    motor[motorD] = 0;
    motor[motorE] = 0;
    wait1Msec(50);
}

void initializeRobot()
{

  return;
}



/////////////////////////////////////////////////////////////////////////////////////////////////////

task main()
{
	//int set;
  initializeRobot();
	//forward();
  waitForStart();
	nxtDisplayTextLine(4, "   Ben Kreger  ");

	while (true)
	{
		getJoystickSettings(joystick);
		//Controller
	if(joystick.joy1_TopHat == 0)
		{

		forward(20);
		}
			if(joystick.joy1_TopHat == 4)
		{

		backward(30);
		}
	if(joystick.joy1_TopHat == 6)
		{
			side(30);
		}
	if(joystick.joy1_TopHat == 2)
		{
			spin(30);
		}
    if(joy1Btn(4) == 1)
    {
      motor[motorA] = 100;

		}
		if(joy1Btn(1) == 1)
    {
      motor[motorA] = 0;

		}
	else //If no other buttons are pressed durning the cycle set D and E to zero
		stop();
		{

		}
	}
}



















//}}
