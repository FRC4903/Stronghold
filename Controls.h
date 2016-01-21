// Control.h

#ifndef CONTROL_H
#define CONTROL_H

#include "Resources.h"
#include "Data.h"

class Controls
{
public:
	Controls();
	~Controls();

	/// <summary>
	/// Moves the base of the robot by outputing
	/// PWM signals to the base CIM motors
	/// </summary>
	void driveBase(int x, int y);

	/// <summary>
	/// Pivots the robot left, while maintaining
	/// current position. Turns left wheel set 
	/// in reverse and right wheel set forward
	/// </summary>
	void pivotLeft();

	/// <summary>
	/// Pivots the robot right, while maintaining
	/// current position. Turns right wheel set 
	/// in reverse and left wheel set forward
	/// </summary>
	void pivotRight();

	/// <summary>
	/// Turns the wheels on the grabbing mechanism
	/// to intake the boulder by sending signal to
	/// Mini CIM motors
	/// </summary>
	void grabBall();

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
	/// Toggles the position of the triangle
	/// mechanism
	/// </summary>
	void toggleTriangles();

	/// <summary>
	/// Updates the local variables from the Data
	/// class to have consistent values for motor
	/// outputs
	/// </summary>
	void update();

	/// <summary>
	/// Resets the speed of each talon to 0
	/// </summary>
	void resetSpeed();

	/// <summary>
	/// Sets the Talon values for the drive system based on each speed
	/// </summary>
	void setDriveTalons(double speed1, double speed2, double speed3, double speed4);

	/// <summary>
	/// Sets the CANTalon value to the value passed
	/// in
	/// </summary>
	void setTalon(CANTalon talon, double value);

	/// <summary>
	/// Sets the Talon value to the value passed
	/// in
	/// </summary>
	void setTalon(Talon talon, double value);
	

	// Talons
	Talon talon1;
	Talon talon2;
	Talon talon3;
	Talon talon4;

	bool trianglesLowered;

	// Speed of each drive Talon
	double speed1;
	double speed2;
	double speed3;
	double speed4;

private:
	Data *library;

};

#endif
