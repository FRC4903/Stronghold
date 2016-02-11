// Data.h
#ifndef DATA_H
#define DATA_H

#include "Controls.h"
#include "Sensors.h"
#include "Teleop.h"
#include "Auto.h"
#include "AI.h"

class Data
{
private:
	Controls *controls;
	Sensors	*sensors;
	AI *brains;
	Auto *auton;
	Teleop *tele;
	static Data library;

public:
	/// <summary>
	/// Initialize variables and objects within the data class.
	/// It is used in place of a Constructor
	/// </summary>
	Data();

	/// <summary>
	/// Deallocate pointers to all classes
	/// </summary>
	~Data();

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

	/// <summary>
	/// Public access to Teleop class.
	/// Allows other classes to access
	/// public methods from Teleop
	/// </summary>
	/// <returns>Returns public instance of Teleop</returns>
	Teleop getTele();

	static Data *getInstance();
};

#endif
