/*
 * @File:			Data.cpp
 * @Description:	Data class contains instance of all variables used by program.
 * 					It also controls how classes access each other and variables.
 * @Author: 		Abhi Gupta
 */

#include "Data.h"

void Data::init() {
	cout << "Initialize" << endl;

	Data::controls = Controls::Controls();
	Data::sensors = Sensors::Sensors();
	Data::brains = AI::AI();
	Data::auton = Auto::Auto();
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