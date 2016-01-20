#ifndef RESOURCES_H
#define RESOURCES_H

#include <iostream>
#include "Data.h"
#include "WPILib.h"
#include "CANTalon.h"

using namespace std;

Data library = Data();

Data getLibrary()
{
	return library;
}

#endif
