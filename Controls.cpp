/*
 * @File:			Controls.cpp
 * @Description:	Constrols class handles output to motors and motor controllers.
 * @Author: 		Rikin Katyal
 */

#include "Controls.h"
#include "Data.h"

Controls::Controls()
	: talon0(0),
	  talon1(1),
	  talon2(2),
	  talon3(3),
	  intake_motor(0),
	  holding_motor(1),
	  trebuchet_top_motor(2),
	  trebuchet_bot_motor(3)
{
	library = Data::getInstance();

 	// Get variables from Data class
 	update();

 	// Set starting variables
 	trianglesLowered = false;

 	reset();

}

Controls::~Controls()
{
	// Controls destructor
}

void Controls::driveBase()
{
	j_x = library->getSensors()->getBaseMovementInputX() / moderator;
	j_y = library->getSensors()->getBaseMovementInputY() / moderator;

	speedL += -j_y + j_x;
	speedR += -j_y - j_x;

	// Sets the talons for the base
	setDriveTalons();

	// reset speeds to 0
	reset();

}

void Controls::intake()
{
	intake_val = 1.0;
	if (!library->getSensors()->getIntakeSensor())
	{
		hold_val = 1.0;
	}
}

void Controls::trebuchet()
{
	top_val = -1.0;
	bot_val = 1.0;
}

void Controls::liftTriangles()
{
	if (trianglesLowered)
	{
		// Do the thing
		trianglesLowered = false;
	}

}

void Controls::lowerTriangles()
{
	if (!trianglesLowered)
	{
		// Do thing
		trianglesLowered = true;
	}
}

void Controls::update()
{
	if (library->getSensors()->getDriveControllerAButton())
	{
		moderator = 1.5;
	}
	else
	{
		moderator = 2.0;
	}
	reset();
}

void Controls::reset()
{
	speedL = 0.0;
	speedR = 0.0;
	j_x = 0.0;
	j_y = 0.0;
	intake_val = 0.0;
	hold_val = 0.0;
	top_val = 0.0;
	bot_val = 0.0;
}

void Controls::setTalons()
{
	// Sets the talons for the base
	talon0.Set(-speedR);
	talon1.Set(-speedR);
	talon2.Set(speedL);
	talon3.Set(speedL);

	intake_motor.Set(intake_val);
	holding_motor.Set(hold_val);
	trebuchet_top_motor.Set(top_val);
	trebuchet_bot_motor.Set(bot_val);
}