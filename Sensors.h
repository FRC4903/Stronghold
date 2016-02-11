// Sensors.h

#ifndef SENSORS_H_
#define SENSORS_H_

#include "Resources.h"

class Sensors
{
private:
    Joystick *base_control;
    Data *library;

public:
    Sensors();
    // constructor
    ~Sensors();
    // destructor

    // these methods get the user input for the base controls
    double getBaseMovementInputX();
    // returns: X-axis
    double getBaseMovementInputY();
    // returns: Y-axis
};

#endif
