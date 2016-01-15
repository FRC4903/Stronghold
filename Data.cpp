/*
 * @File:			Data.cpp
 * @Description:	Data class contains instance of all variables used by program.
 * 					It also controls how classes access each other and variables.
 * @Author: 		Abhi Gupta
 */

#include "Data.h"

void Data::init() {
	cout << "Initialize" << endl;
	trianglesLowered = true;
}

Controls Data::getControls() {
	return Data::controls;
}

Sensors Data::getSensors() {
	return Data::sensors;
}

AI Data::getAI() {
	return Data::brains;
}

Auto Data::getAuto() {
	return Data::auton;
}

bool Data::isTriangleLowered() {
	return Data::trianglesLowered
}