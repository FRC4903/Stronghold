/*
 * @File:			Sensors.cpp
 * @Description:	Sensors class handles all input from ultrasonic sensors and
 * 					input methods. All input values from the sensors are stored
 *					in the Data class.
 * @Author:			Roman S.
 */

#include "Sensors.h"

Sensors::Sensors()
{
	library = &getLibrary();
}

Sensors::~Sensors()
{
	// Sensors deconstructor
}