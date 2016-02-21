// Control.h

#ifndef CONTROL_H
#define CONTROL_H
#include "Resources.h"

//#include "Data.h"
class Data;

class Controls
{
public:
	Controls();
	~Controls();

	/// <summary>
	/// Moves the base of the robot by outputing
	/// PWM signals to the base CIM motors
	/// </summary>
	void driveBase();

	/// <summary>
	/// Turns the wheels on the grabbing mechanism
	/// to intake the boulder by sending signal to
	/// Mini CIM motors
	/// </summary>
	void intake();

	/// <summary>
	/// Turns the wheels on the grabbing mechanism
	/// in reverse to shoot out the boulder by
	/// sending signal to Mini CIM mottors
	/// </summary>
	void reverseBall();

	/// <summary>
	/// Turns the wheels on the shooting mechanism
	/// to launch the boulder off the ramp by
	/// sending signal to Mini CIM motors
	/// </summary>
	void launchBall();

	/// <summary>
	/// Trebuchet does something
	/// </summary>
	void trebuchet();

	/// <summary>
	/// Lifts the triangle mechanism to lift the
	/// porticullis defense
	/// </summary>
	void liftTriangles();

	/// <summary>
	/// Lowers the triangle mechanism to lower the
	/// cheval de frise defense
	/// </summary>
	void lowerTriangles();

	/// <summary>
	/// Updates the local variables from the Data
	/// class to have consistent values for motor
	/// outputs
	/// </summary>
	void update();

	/// <summary>
	/// Resets the speed of each talon to 0
	/// </summary>
	void reset();

	/// <summary>
	/// Sets all talons to their respective variable value
	/// </summary>
	void setTalons();

private:
	Data *library;

	// Drive Talons
	Talon talon0;
	Talon talon1;
	Talon talon2;
	Talon talon3;

	// Action Talons
	CANTalon intake_motor;
	CANTalon holding_motor;
	CANTalon trebuchet_top_motor;
	CANTalon trebuchet_bot_motor;

	// triangle mechanism status
	bool trianglesLowered;

	// moderator for driving
	int moderator = 2.0;

	// joystick x and y
	double j_x, j_y;

	// Speed of each drive Talon
	double speedR, speedL;
	double intake_value;
	double hold_value;
	double top_value, bottom_value;
};

#endif
