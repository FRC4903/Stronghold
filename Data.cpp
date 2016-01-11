/*
 * File Name:	Data.cpp
 * Description:	Data class contains instance of all variables used by program.
 * 				Data class controls how classes access each other and variables.
 * Manager: 	Abhi Gupta
 */

#include "Data.h"

void Data::init()
{
	// Setup inital values for all variables
	Data::controls;
	Data::sensors;
	Data::brains;
	Data::auton;
}

Controls Data::getControls()
{
	return Data::controls;
}

Sensors Data::getSensors()
{
	return Data::sensors;
}

AI Data::getAI()
{
	return Data::brains;
}

Auto Data::getAuto()
{
	return Data::auton;
}