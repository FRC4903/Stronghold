/*
 * @File:			Controls.cpp
 * @Description:	Constrols class handles output to motors and motor controllers.
 * @Author: 		Rikin Katyal
 */

#include "Controls.h"

// Initialize Talons for drive system
t1 = new CANTalon(DN1);
t2 = new CANTalon(DN2);
t3 = new CANTalon(DN3);
t4 = new CANTalon(DN4);

Controls::Controls() {
 	// Controls constructor
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
	if (Data::trianglesLowered) {
		this -> liftTriangles();
	} else {
		this -> lowerTriangles();
	}
}

void Controls::update() {
	
}