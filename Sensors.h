// Sensors.h

#ifndef SENSORS_H_
#define SENSORS_H_

#include "Resources.h"
class Data;
class Sensors
{
private:
	Joystick *base_control;
    Joystick *secondary_control;
	Data *library;

public:
    Sensors();
    // constructor
    ~Sensors();
    // destructor

    /// <summary>
    /// retruns values of the controller's primary X-axis(the one used for driving)
    /// </summary>
    double getBaseMovementInputX();

    /// <summary>
    /// retruns values of the controller's primary Y-axis(the one used for driving)
    /// </summary>
    double getBaseMovementInputY();

    /// <summary>
    /// returns the value of the controller's A button(For speed boost)
    /// </summary>
    bool getDriveControllerAButton();

    /// <summary>
    /// returns the value of the secondary controller's Trigger(for shooting the ball)
    /// </summary>
    bool getSecondaryTrigger();

    /// <summary>
    /// returns the value of the secondary controller's side(thumb) button(for intake of the ball)
    /// </summary>
    bool getSecondarySideButton();

    /// <summary>
    /// returns the value of the secondary controller's button 5(for the piston controls)
    /// </summary>
    bool getSecondaryPistonUp();

    /// <summary>
    /// returns the value of the secondary controller's button 3(for the piston controls)
    /// </summary>
    bool getSecondaryPistonDown();
};

#endif
