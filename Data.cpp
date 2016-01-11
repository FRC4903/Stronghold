test/*
 * File Name:	Data.cpp
 * Description:	Data class contains instance of all variables used by program.
 * 				Data class controls how classes access each other and variables.
 * Manager: 	Abhi Gupta
 */

#include "Data.h"

using namespace std;


void Data::init()
{
	Data::controls = new Controls();
	Data::sensors = new Sensors();
	Data::brains = new AI();
	Data::auton = new Auto();
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