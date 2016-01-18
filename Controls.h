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
	void driveBase();

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
	

	// Talons
	CANTalon t1;
	CANTalon t2;
	CANTalon t3;
	CANTalon t4;

	bool trianglesLowered;

private:
	Data *library;

};

#endif