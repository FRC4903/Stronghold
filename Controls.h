// Control.h

#ifndef CONTROL_H
#define CONTROL_H

#include "Resources.h"
#include "Data.h"

class Controls {
<<<<<<< HEAD

=======
>>>>>>> upstream/develop
public:
	Controls();
	~Controls();

<<<<<<< Updated upstream
<<<<<<< Updated upstream
	/// <summary>
	/// Output PWM signals to base drive motors.
	/// Used to control the robot's maneuvering
	/// </summary>
	void driveBase();
<<<<<<< HEAD
	void getData();
	void grabBall();
	void reverseBall();
	void launchBall();
=======

	/// <summary>
	/// Update local variables for motor outputs
	/// </summary>
	void update();
>>>>>>> upstream/develop
=======
	void driveBase();
	void pivotLeft();
	void pivorRight();

	void grabBall();
	void reverseBall();
	void launchBall();
=======
	void driveBase();
	void pivotLeft();
	void pivorRight();

	void grabBall();
	void reverseBall();
	void launchBall();
>>>>>>> Stashed changes
	void liftTriangles();
	void lowerTriangles();

	void getData();
<<<<<<< Updated upstream
>>>>>>> Stashed changes
=======
>>>>>>> Stashed changes
};

#endif