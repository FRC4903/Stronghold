/*
 * @File:			Controls.cpp
 * @Description:	Constrols class handles output to motors and motor controllers.
 * @Author: 		Rikin Katyal
 */

#include "Controls.h"

<<<<<<< HEAD
// Initialize Talons for drive system
t1 = new CANTalon(DN1);
t2 = new CANTalon(DN2);
t3 = new CANTalon(DN3);
t4 = new CANTalon(DN4);
=======
using namespace std;
>>>>>>> d36e69d42905c0183949739d6c046db35bba6af2

Controls::Controls() {
 	// Controls constructor
}

Controls::~Controls() {
	// Controls destructor
}

<<<<<<< HEAD
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
=======
/// <summary>
/// Moves the base of the robot
/// </summary>
void Controls::driveBase() {

}

/// <summary>
///	Pivots the robot left, while maintaining position
/// </summary>
void Controls::pivotLeft() {

}

/// <summary>
///	Pivots the robot right, while maintaining position
/// </summary>
void Controls::pivotRight() {

}

/// <summary>
///	Grabs the ball in front of robot
/// </summary>
void Controls::grabBall() {

}

/// <summary>
///	Shoots the ball out by reversing the grab ball mechanism
/// </summary>
void Controls::reverseBall() {
	
}

/// <summary>
///	Launches the ball using the shooting mechanism
/// </summary>
void Controls::launchBall() {
	
}

/// <summary>
///	Lifts the triangle mechanism to lift porticullis
/// </summary>
void Controls::liftTriangles() {

}

/// <summary>
///	Lowers the triangle mechanism to push down the chevel de frise
/// </summary>
void Controls::lowerTriangles() {
	
}

/// <summary>
///	Updates the data so all data used is consistent
/// </summary>
void Controls::update() {
>>>>>>> d36e69d42905c0183949739d6c046db35bba6af2
	
}