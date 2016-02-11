/*
 * @File:			Controls.cpp
 * @Description:	Constrols class handles output to motors and motor controllers.
 * @Author: 		Rikin Katyal
 */

#include "Controls.h"


Controls::Controls() {
	library = Data::getInstance();

 	// Get variables from Data class
 	update();

 	// Set starting variables
 	trianglesLowered = false;

 	resetSpeed();

    talon0 = new Talon(0);
    talon1 = new Talon(1);
    talon2 = new Talon(2);
    talon3 = new Talon(3);
}

Controls::~Controls() {
	// Controls destructor
	delete talon0;
	delete talon1;
	delete talon2;
	delete talon3;

	delete library;
}

void Controls::driveBase()
{
	// Get variables from Data class
	update();

	j_x = library->getSensors().getBaseMovementInputX() / moderator;
	j_y = library->getSensors().getBaseMovementInputY() / moderator;

	speedL += -j_y + j_x;
	speedR += -j_y - j_x;

	// Sets the talons for the base
	setDriveTalons(speedL, speedR);

	// reset speeds to 0
	resetSpeed();

}

void Controls::pivotLeft() {

}

void Controls::pivotRight() {

}

void Controls::grabBall() {

}

void Controls::reverseBall() {

}

void Controls::launchBall() {

}

void Controls::liftTriangles() {

}

void Controls::lowerTriangles() {

}

void Controls::toggleTriangles() {
	if (trianglesLowered) {
		liftTriangles();
	}
	else {
		lowerTriangles();
	}
}

void Controls::update() {

}

void Controls::resetSpeed() {
	speedL = 0.0;
	speedR = 0.0;
	j_x = 0.0;
	j_y = 0.0;
}

void Controls::setDriveTalons(double speedL, double speedR) {
	// Sets the talons for the base
	talon0->Set(-speedR);
	talon1->Set(-speedR);
	talon2->Set(speedL);
	talon3->Set(speedL);
}

void Controls::setTalon(Talon talon, double value) {
	talon.Set(value);
}

void Controls::setTalon(CANTalon talon, double value) {
	talon.Set(value);
}
