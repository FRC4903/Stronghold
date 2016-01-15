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

Controls::driveBase() {

}

Controls::pivotLeft() {

}

Controls::pivotRight() {

}

Controls::grabBall() {

}

Controls::reverseBall() {
	
}

Controls::launchBall() {
	
}

Controls::liftTriangles() {
	
}

Controls::lowerTriangles() {
	
}

Controls::toggleTriangles() {
	if (Data::trianglesLowered) {
		this -> liftTriangles();
	} else {
		this -> lowerTriangles();
	}
}

Controls::update() {
	
}