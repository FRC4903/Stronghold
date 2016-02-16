/*
 * @File:			Teleop.cpp
 * @Description:	Teleop class contains all of the logic that will be implementing
 * 					all of the other classes devleoped by various members.
 * @Author: 		Abhi Gupta
 */

#include "Teleop.h"
#include "Data.h"

Teleop::Teleop()
{
	// Teleop constructor
	library = Data::getInstance();
}

Teleop::~Teleop() {


}

void Teleop::run()
{
	// Tells Controls to drive base
	library->getControls()->driveBase();
	// library->getControls().driveBase(library->getSensors().getBaseMovementInputX(), library->getSensors().getBaseMovementInputY());
}
