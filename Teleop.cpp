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

Teleop::~Teleop()
{

}

void Teleop::run()
{
	library->getControls()->update();
	// Tells Controls to drive base
	library->getControls()->driveBase();
	
	if (library->getSensors()->getSecondarySideButton())
	{
		library->getControls()->intake();
	}
	if (library->getSensors()->getSecondaryTrigger())
	{
		library->getControls()->trebuchet();
	}
	if (library->getSensors()->getSecondaryPistonUp())
	{
		library->getControls()->liftTriangles();
	}
	if (library->getSensors()->getSecondaryPistonDown())
	{
		library->getControls()->lowerTriangles();
	}
}
