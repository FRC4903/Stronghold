/*
 * @File:			Controls.cpp
 * @Description:	Constrols class handles output to motors and motor controllers.
 * @Author: 		Rikin Katyal
 */

#include "Controls.h"


Controls::Controls() {
	library = &getLibrary();
 	
 	// Get variables from Data class
 	this -> update();

 	// Initialize Talons for drive system
 	t1 = CANTalon(DN1);
 	t2 = CANTalon(DN2);
 	t3 = CANTalon(DN3);
 	t4 = CANTalon(DN4);

 	// Set starting variables
 	trianglesLowered = false;

}

Controls::~Controls() {
	// Controls destructor
}

void Controls::driveBase() {

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
		this -> liftTriangles();
	}
	else {
		this -> lowerTriangles();
	}
}

void Controls::update() {
	
}