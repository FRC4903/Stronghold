// Teleop.h

#ifndef TELEOP_H
#define TELEOP_H

#include "Resources.h"

class Teleop {
public:
	Teleop();
	~Teleop();

	/// <summary>
	/// Runs the teleop code
	/// </summary>
	void run();

private:
	Data *library;
};


#endif