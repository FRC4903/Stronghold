/*
 * @File:			Teleop.cpp
 * @Description:	Teleop class contains all of the logic that will be implementing
 * 					all of the other classes devleoped by various members.
 * @Author: 		Dilpreet Chana
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

	library->getControls()->driveBase();
	
	if (library->getSensors()->getSecondarySideButton())
	{
		library->getControls()->intake();
	}
	if (library->getSensors()->getSecondaryTrigger())
	{
		library->getControls()->trebuchet();
	}

	// Triangle mechanism
	if (library->getSensors()->getSecondaryPistonUp())
	{
		library->getControls()->liftTriangles();
	}
	else if (library->getSensors()->getSecondaryPistonDown())
	{
		library->getControls()->lowerTriangles();
	}
	else
	{
		library->getControls->stopTriangles();
	}

	library->getControls()->setTalons();
}
