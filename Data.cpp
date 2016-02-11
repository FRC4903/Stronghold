/*
* @File:			Data.cpp
* @Description:	Data class contains instance of all variables used by program.
* 					It also controls how classes access each other and variables.
* @Author: 		Abhi Gupta
*/

#include "Data.h"

Data::Data()
    : Controls(),
      Sensors(),
      AI(),
      Auto(),
      Teleop()
{
}

Data::~Data()
{
    delete controls;
    delete sensors;
    delete brains;
    delete auton;
    delete tele;
}

static Data Data::library;

static Data *Data::getInstance()
{
	return &library;
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
