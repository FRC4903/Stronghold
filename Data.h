// Data.h

#ifndef DATA_H_
#define DATA_H_

#include <iostream>
#include "Controls.h"
#include "Sensors.h"
#include "Auto.h"
#include "AI.h"

class Data
{
public:
	static void init();
	static Sensors getSensors();
	static Auto getAuto();
	static Controls getControls();
	static AI getAI();

private:
	static Controls controls;
	static Sensors sensors;
	static AI brains;
	static Auto auton;
};

#endif