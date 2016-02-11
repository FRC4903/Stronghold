/*
 * File Name:	Auto.cpp
 * Description:	Auto class handles all operations during the autonomous phase.
 * Manager:		Abhi Gupta
 */

#include "Auto.h"

Auto::Auto() {
	library = Data::getInstance();
}

Auto::~Auto()
{
	delete library;
}
