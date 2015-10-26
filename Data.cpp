/*
 * File Name:	Data.cpp
 * Description:	Data class contains instance of all variables used by program.
 * 				Data class controls how classes access each other and variables.
 */

#include "Data.h"

Data::Data() {
	// Data constructor
	Controls controls;
	Sensors sensors;
	AI brains;
	Auto auton;
}

Data::~Data() {
	// Data deconstructor
}