/*
 * @File:			Teleop.cpp
 * @Description:	Teleop class contains all of the logic that will be implementing
 * 					all of the other classes devleoped by various members.
 * @Author: 		Abhi Gupta
 */

#include "Teleop.h"

Teleop::Teleop() {
	// Teleop constructor
	library = &conjure::getLibrary();
}

Teleop::~Teleop() {
	// Teleop deconstructor
}

void Teleop::run() {
	library.getControls().driveBase(library.getSensors().getBaseMovementInputX(), library.getSensors().getBaseMovementInputY());
}