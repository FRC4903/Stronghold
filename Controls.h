// Control.h

#ifndef CONTROL_H
#define CONTROL_H

#include "Resources.h"
#include "Data.h"

class Controls {

public:
	Controls();
	~Controls();

	void driveBase();
	void pivotLeft();
	void pivotRight();

	void grabBall();
	void reverseBall();
	void launchBall();
	void liftTriangles();
	void lowerTriangles();

	void update();
};

#endif