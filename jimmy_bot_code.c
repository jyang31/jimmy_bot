#pragma config(Sensor, dgtl1,  Left_DT_Encoder, sensorQuadEncoder)
#pragma config(Sensor, dgtl3,  Right_DT_Encoder, sensorQuadEncoder)
#pragma config(Sensor, dgtl5,  RedorBlueJumper, sensorDigitalIn)
#pragma config(Sensor, dgtl6,  waitJumper,     sensorDigitalIn)
#pragma config(Motor,  port1,           rightShooterMotor, tmotorVex393_HBridge, openLoop, reversed)
#pragma config(Motor,  port2,           leftMotor,     tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port3,           rightMotor,    tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port4,           firstIntakeMotor, tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port5,           secondIntakeMotor, tmotorServoContinuousRotation, openLoop)
#pragma config(Motor,  port6,           firstIntakeMotorTwo, tmotorNone, openLoop)
#pragma config(Motor,  port10,          leftShooterMotor, tmotorVex393_HBridge, openLoop, reversed)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*        Description: Competition template for VEX EDR                      */
/*                                                                           */
/*---------------------------------------------------------------------------*/

// This code is for the VEX cortex platform
#pragma platform(VEX2)

// Select Download method as "competition"
#pragma competitionControl(Competition)

//Main competition background code...do not modify!
#include "Vex_Competition_Includes.c"

/*---------------------------------------------------------------------------*/
/*                          Pre-Autonomous Functions                         */
/*                                                                           */
/*  You may want to perform some actions before the competition starts.      */
/*  Do them in the following function.  You must return from this function   */
/*  or the autonomous and usercontrol tasks will not be started.  This       */
/*  function is only called once after the cortex has been powered on and    */
/*  not every time that the robot is disabled.                               */
/*---------------------------------------------------------------------------*/

void pre_auton()
{

	// Set bStopTasksBetweenModes to false if you want to keep user created tasks
	// running between Autonomous and Driver controlled modes. You will need to
	// manage all user created tasks if set to false.
	bStopTasksBetweenModes = true;

	// Set bDisplayCompetitionStatusOnLcd to false if you don't want the LCD
	// used by the competition include file, for example, you might want
	// to display your team name on the LCD in this function.
	// bDisplayCompetitionStatusOnLcd = false;

	// All activities that occur before the competition starts
	// Example: clearing encoders, setting servo positions, ...
}

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              Autonomous Task                              */
/*                                                                           */
/*  This task is used to control your robot during the autonomous phase of   */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/

task autonomous()
{
	SensorValue(Left_DT_Encoder) = 0;
	SensorValue(Right_DT_Encoder) = 0;

	if (SensorValue[waitJumper] == 0)
	{
		wait(5);
	}//wait jumper
	// ..........................................................................
	// Insert user code here.
	// ..........................................................................

	// Remove this function call once you have "real" code.
	while (1==1)
	{



		//Actual Movement
	//HIGH GOAL INNER
	//start of red

		if (SensorValue [RedorBlueJumper] == 1)
		{
			if (SensorValue [Left_DT_Encoder] >= 0 && SensorValue [Left_DT_Encoder] < 60)
			{
				motor[leftMotor] = -63;
				motor[rightMotor] = -63;
			}//1st move forward
			if (SensorValue[Left_DT_Encoder] >= 60 && SensorValue[Left_DT_Encoder] < 700)

			{
				motor[leftMotor] = -63;
				motor[rightMotor] = 0;
			}//turn
			else if (SensorValue[Left_DT_Encoder] >= 700 && SensorValue[Left_DT_Encoder] < 1360)
			{
				motor[leftMotor] = -63;
				motor[rightMotor] = -63;
			}//move forward again
			else if (SensorValue[Left_DT_Encoder] >= 1360)
			{
				motor[leftMotor] = 0;
				motor[rightMotor] = 0;
				motor[leftShooterMotor] = 127;
				motor[rightShooterMotor] = 127;
				wait(8);
				motor[secondIntakeMotor] = 127;

			}//stop moving/fire
		}//jumper out: red

	//	start of blue
		else if (SensorValue [RedorBlueJumper] == 0)
		{
			if (SensorValue [Right_DT_Encoder] <= 0 && SensorValue [Right_DT_Encoder] > -80)
			{
				motor[leftMotor] = -63;
				motor[rightMotor] = -63;
			}//first move forward
			if (SensorValue [Right_DT_Encoder] <= -80 && SensorValue [Right_DT_Encoder] > -600)
			{
				motor[rightMotor] = -63;
				motor[leftMotor] = 0;
			}//turn
			else if (SensorValue [Right_DT_Encoder] <= -600 && SensorValue [Right_DT_Encoder] > -1340)
			{
				motor[leftMotor] = -63;
				motor[rightMotor] = -63;
			}//move forward again
			else if (SensorValue [Right_DT_Encoder] <= -1340)
			{
				motor[leftMotor] = 0;
				motor[rightMotor] = 0;
				motor[leftShooterMotor] = 127;
				motor[rightShooterMotor] = 127;
				wait(8);
				motor[secondIntakeMotor] = 127;
			}
		//	//stop moving/fire

		//}//jumper in: blue

		//low goal/ outer auton
		//if (SensorValue [RedorBlueJumper] == 1)
		//{
		//	if (SensorValue [Left_DT_Encoder] >= 0 && SensorValue [Left_DT_Encoder] < 660)
		//	{
		//		motor[leftMotor] = -63;
		//		motor[rightMotor] = -63;
		//	}//1st move forward
		//	if (SensorValue[Left_DT_Encoder] >= 660 && SensorValue[Left_DT_Encoder] < 1890)

		//	{
		//		motor[leftMotor] = -63;
		//		motor[rightMotor] = 0;
		//	}//turn
		//	else if (SensorValue[Left_DT_Encoder] >= 1890 && SensorValue[Left_DT_Encoder] < 2260)
		//	{
		//		motor[leftMotor] = -63;
		//		motor[rightMotor] = -63;
		//	}//move forward again
		//	else if (SensorValue[Left_DT_Encoder] >= 2260)
		//	{
		//		motor[leftMotor] = 0;
		//		motor[rightMotor] = 0;
		//		motor[leftShooterMotor] = 100;
		//		motor[rightShooterMotor] = 100;
		//		wait(8);
		//		motor[secondIntakeMotor] = 127;

		//	}//stop moving/fire
		//}//red side auton

		////blue side auton
		//else if (SensorValue [RedorBlueJumper] == 0)
		//{
		//	if (SensorValue [Right_DT_Encoder] <= 0 && SensorValue [Right_DT_Encoder] > -740)
		//	{
		//		motor[leftMotor] = -63;
		//		motor[rightMotor] = -63;
		//	}//first move forward
		//	if (SensorValue [Right_DT_Encoder] <= -740 && SensorValue [Right_DT_Encoder] > -1570)
		//	{
		//		motor[rightMotor] = -63;
		//		motor[leftMotor] = 0;
		//	}//turn
		//	else if (SensorValue [Right_DT_Encoder] <= -1570 && SensorValue [Right_DT_Encoder] > -2240)
		//	{
		//		motor[leftMotor] = -63;
		//		motor[rightMotor] = -63;
		//	}//move forward again
		//	else if (SensorValue [Right_DT_Encoder] <= -2240)
		//	{
		//		motor[leftMotor] = 0;
		//		motor[rightMotor] = 0;
		//		motor[leftShooterMotor] = 100;
		//		motor[rightShooterMotor] = 100;
		//		wait(8);
		//		motor[secondIntakeMotor] = 127;
		//	}
			//stop moving/fire
		}//blue side auton

	}//while loop
}//task autonomous

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              User Control Task                            */
/*                                                                           */
/*  This task is used to control your robot during the user control phase of */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/

task usercontrol()
{
	// User control code here, inside the loop

	while (true)
	{
		// This is the main execution loop for the user control program.
		// Each time through the loop your program should update motor + servo
		// values based on feedback from the joysticks.

		// ........................................................................
		// Insert user code here. This is where you use the joystick values to
		// update your motors, etc.
		// ........................................................................

		// Remove this function call once you have "real" code.
		//Variables
		//int firstintakeSpeed = 0;
		//int secondintakeSpeed = 0;


		//Basic Movement
		motor[leftMotor]  = vexRT[Ch3];   // Left Joystick Y value
		motor[rightMotor] = vexRT[Ch2];   // Right Joystick Y value

		//Shooter
		if(vexRT[Btn6U] == 1)
		{
			motor[leftShooterMotor] = 127;
			motor[rightShooterMotor] = 127;
		}// When 6U pressed fast
		else if(vexRT[Btn6D] == 1)
		{
			motor[leftShooterMotor] = 0;
			motor[rightShooterMotor] = 0;
		}//When 6D pressed stop


		//Intake(s)
		//FirstIntake (NEW)

		if(vexRT[Btn5U] == 1)
		{
			motor [firstIntakeMotor] = 127;
		}//When 5U pressed intake
		else if (vexRT[Btn7U] == 1)
		{
			motor [firstIntakeMotor] = -127;
		}//If 7U is pressed reverse
		else
			//if(vexRT[Btn7L] == 1) //toggleable if uncommented
		{
			motor[firstIntakeMotor] = 0;
		}// When nothing is pressed

		//SecondIntake (NEW)
		if(vexRT[Btn5D] == 1)
		{
			motor[secondIntakeMotor] = 127;
		}//When 5D is pressed intake
		else if(vexRT[Btn7D] == 1)
		{
			motor[secondIntakeMotor] = -127;
		}//When 7D is pressed reverse
		else
		{
			motor[secondIntakeMotor] = 0;
		}//When nothing is pressed

		//TEST CODE for shooter motors
		//if(vexRT[Btn8U] == 1)
		//{
		//	motor[leftShooterMotor] = 63;
		//}
		//else
		//{
		//	motor[leftShooterMotor] = 0;
		//}


		//if(vexRT[Btn8D] == 1)
		//{
		//	motor[rightShooterMotor] = 63;
		//}
		//else
		//{
		//	motor[rightShooterMotor] = 0;
		//}



	}
}
