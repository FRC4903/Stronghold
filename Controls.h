// Control.h

#ifndef CONTROL_H
#define CONTROL_H

#include "Resources.h"
#include "Data.h"

class Controls {
public:
	Controls();
	~Controls();

	/// <summary>
	/// Output PWM signals to base drive motors.
	/// Used to control the robot's maneuvering
	/// </summary>
	void driveBase();

	/// <summary>
	/// Update local variables for motor outputs
	/// </summary>
	void update();
};

#endif