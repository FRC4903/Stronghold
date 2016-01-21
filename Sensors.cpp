/*
 * File Name:	Sensors.cpp
 * Description:	Sensors class handles all input from various sensors and inputs.
 *				All input values can be accesed via methods contained in this class
 *				For more descriptive comments, look in the header file
 * Manager:			Roman S.
 *
 */

#include "Sensors.h"

 using namespace std;

 Sensors::Sensors()
 {
 	// Sensors constructor
 	base_control = new Joystick(0);
 }

 Sensors::~Sensors()
 {
 	// sensors destructor
 }

 Sensors::getBaseMovementInputX()
 {
 	// returns: x-axis of joystick for base
 	return base_control.GetRawAxis(0);
 }

 Sensors::getBaseMovementInputY()
 {
 	// returns: y-axis of joystick for base
 	return base_control.GetRawAxis(1);
 }