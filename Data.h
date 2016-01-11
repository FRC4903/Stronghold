// Data.h

#ifndef DATA_H
#define DATA_H

#include <iostream>
#include "Controls.h"
#include "Sensors.h"
#include "Auto.h"
#include "AI.h"

class Data
{
private:
	static Controls controls;
	static Sensors sensors;
	static AI brains;
	static Auto auton;

public:
	static void init();
	static Sensors getSensors();
	static Auto getAuto();
	static Controls getControls();
	static AI getAI();
};

#endif