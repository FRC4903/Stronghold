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

}

Controls::~Controls() {
	// Controls destructor
}

void Controls::driveBase(int x, int y) {

	int moderator = 2.0;

	// Get variables from Data class
	update();

	// Driving base left/right
	if (x != 0) {
		// Divide by 2 to moderate speed
		speed1 += x / moderator;
		speed2 += x / moderator;
		speed3 += x / moderator;
		speed4 += x / moderator;
	}

	// Driving base up/down
	if (y != 0) {
		// Divide by 2 to moderate speed
		speed1 += y / moderator;
		speed2 += y / moderator;
		speed3 += y / moderator;
		speed4 += y / moderator;
	}

	// Sets the talons for the base
	setDriveTalons(speed1, speed2, speed3, speed4);

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
	speed1 = 0;
	speed2 = 0;
	speed3 = 0;
	speed4 = 0;
}

void Controls::setDriveTalons(double speed1, double speed2, double speed3, double speed4) {
	// Sets the talons for the base

	setTalon(library->getTalon(library->FRONT_L), speed1);
	setTalon(library->getTalon(library->FRONT_R), speed2);
	setTalon(library->getTalon(library->BACK_L), speed3);
	setTalon(library->getTalon(library->BACK_R), speed4);
}

void Controls::setTalon(Talon talon, double value) {
	talon.Set(value);
}

void Controls::setTalon(CANTalon talon, double value) {
	talon.Set(value);
}
