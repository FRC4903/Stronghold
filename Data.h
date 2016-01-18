// Data.h

#ifndef DATA_H
#define DATA_H

#include "Resources.h"
#include "Controls.h"
#include "Sensors.h"
#include "Auto.h"
#include "AI.h"

class Data {
	static Controls controls;
	static Sensors	sensors;
	static AI		brains;
	static Auto		auton;

public:
	/// <summary>
	/// Initialize variables and objects within the data class.
	/// It is used in place of a Constructor
	/// </summary>
	static void init();

	/// <summary>
	/// Public access to Sensors class.
	/// Allows other classes to access
	/// public methods from Sensors
	/// </summary>
	/// <returns>Returns public instance of Sensors</returns>
	static Sensors getSensors();

	/// <summary>
	/// Public access to Auto class.
	/// Allows other classes to access
	/// public methods from Auto
	/// </summary>
	/// <returns>Returns public instance of Auto</returns>
	static Auto getAuto();

	/// <summary>
	/// Public access to Controls class.
	/// Allows other classes to access
	/// public methods from Controls
	/// </summary>
	/// <returns>Returns public instance of Controls</returns>
	static Controls getControls();

	/// <summary>
	/// Public access to AI class.
	/// Allows other classes to access
	/// public methods from AI
	/// </summary>
	/// <returns>Returns public instance of AI</returns>
	static AI getAI();

};

#endif