/*
* @File:			Data.cpp
* @Description:	Data class contains instance of all variables used by program.
* 					It also controls how classes access each other and variables.
* @Author: 		Abhi Gupta
*/

#include "Data.h"

Data::Data() {
	controls = Controls();
	sensors = Sensors();
	brains = AI();
	auton = Auto();
	tele = Teleop();
}

Controls Data::getControls()
{
	return controls;
}

Sensors Data::getSensors()
{
	return sensors;
}

AI Data::getAI()
{
	return brains;
}

Auto Data::getAuto()
{
	return auton;
}

Teleop Data::getTele()
{
	return tele;
}