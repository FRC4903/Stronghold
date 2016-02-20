/*
 * @File:	Sensors.cpp
 * @Description:	Sensors class handles all input from various sensors and inputs.
 *				All input values can be accesed via methods contained in this class
 *				For more descriptive comments, look in the header file
 * @Author:			Roman S.
 *
 */

#include "Sensors.h"
#include "Data.h"

using namespace std;

Sensors::Sensors()
{

 	// Sensors constructor
 	base_control = new Joystick(0);
 	secondary_control = new Joystick(1)

 	intake_sensor = new DigitalInput(0);

	library = Data::getInstance();
}

Sensors::~Sensors()
{
 	// sensors destructor
 	delete base_control;
 	delete library;
}

double Sensors::getBaseMovementInputX()
{
 	// returns: x-axis of joystick for base
 	return base_control->GetRawAxis(0);
}

double Sensors::getBaseMovementInputY()
{
 	// returns: y-axis of joystick for base
 	return base_control->GetRawAxis(1);
}

bool Sensors::getDriveControllerAButton()
{
 	return base_control->GetRawButton(1);
}

bool Sensors::getSecondaryTrigger()
{
 	return secondary_control->GetRawButton(1);
}

bool Sensors::getSecondarySideButton()
{
 	return secondary_control->GetRawButton(2);
}

bool Sensors::getSecondaryPistonUp()
{
 	return secondary_control->GetRawButton(5);
}

bool Sensors::getSecondaryPistonDown()
{
 	return secondary_control->GetRawButton(3);
}

bool Sensors::getIntakeSensor()
{
	return intake_sensor->Get()
}
