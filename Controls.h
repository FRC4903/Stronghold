// Control.h

#ifndef CONTROL_H
#define CONTROL_H

#include "resources.h"
#include "Data.h"

class Controls {

public:
	Controls();
	~Controls();
	void driveBase();
	void getData();
	void grabBall();
	void reverseBall();
	void launchBall();
};

#endif