// Data.h
#ifndef DATA_H
#define DATA_H

#include "Resources.h"
#include "Controls.h"
#include "Sensors.h"
#include "Teleop.h"
#include "Auto.h"
#include "AI.h"

class Data {
	Controls controls;
	Sensors	sensors;
	AI brains;
	Auto auton;
	Teleop tele;

	int talonIDs[] = {1, 2, 3, 4};

	CANTalon::CANTalon talons[] = {
		CANTalon::CANTalon(talonIDs[0]),
		CANTalon::CANTalon(talonIDs[1]),
		CANTalon::CANTalon(talonIDs[2]),
		CANTalon::CANTalon(talonIDs[3])
	};

public:
	enum Talon {
		FRONT_L,
		FRONT_R,
		BACK_L,
		BACK_R
	};

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

	/// <summary>
	/// Public access to Teleop class.
	/// Allows other classes to access
	/// public methods from Teleop
	/// </summary>
	/// <returns>Returns public instance of Teleop</returns>
	Teleop getTele();

	/// <summary>
	/// Public access to all talons connected to the robot.
	/// </summary>
	/// <returns>Returns private instance of CANTalon</returns>
	CANTalon::CANTalon getTalon(int motor) {
	}

};

#endif
