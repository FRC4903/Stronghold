// Data.h

#ifndef DATA_H
#define DATA_H

#include "Resources.h"
#include "Controls.h"
#include "Sensors.h"
#include "Auto.h"
#include "AI.h"

class Data
{
public:
	/// <summary>
	/// Initialize variables and objects within the data class.
	/// It is used in place of a Constructor
	/// </summary>
	Data();

	/// <summary>
	/// Public access to Sensors class.
	/// Allows other classes to access
	/// public methods from Sensors
	/// </summary>
	/// <returns>Returns public instance of Sensors</returns>
	Sensors getSensors();

	/// <summary>
	/// Public access to Auto class.
	/// Allows other classes to access
	/// public methods from Auto
	/// </summary>
	/// <returns>Returns public instance of Auto</returns>
	Auto getAuto();

	/// <summary>
	/// Public access to Controls class.
	/// Allows other classes to access
	/// public methods from Controls
	/// </summary>
	/// <returns>Returns public instance of Controls</returns>
	Controls getControls();

	/// <summary>
	/// Public access to AI class.
	/// Allows other classes to access
	/// public methods from AI
	/// </summary>
	/// <returns>Returns public instance of AI</returns>
	AI getAI();

private:
	Controls controls;
	Sensors	 sensors;
	AI	 brains;
	Auto	 auton;
};

#endif
