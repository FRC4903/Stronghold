/*
 * @File:			Controls.cpp
 * @Description:	Constrols class handles output to motors and motor controllers.
 * @Author: 		Rikin Katyal
 */

#include "Controls.h"
#include "Data.h"

Controls::Controls()
	// initialize talons
	: talon0(0),
	  talon1(1),
	  talon2(2),
	  talon3(3),
	  intake_motor(0),
	  holding_motor(1),
	  trebuchet_top_motor(2),
	  trebuchet_bot_motor(3),
	  triangleSolenoid(1, 2)
{
	library = Data::getInstance();

 	update();

 	reset();

}

Controls::~Controls() {
	// Controls destructor
}

void Controls::driveBase() {
	j_x = library->getSensors()->getBaseMovementInputX() / moderator;
	j_y = library->getSensors()->getBaseMovementInputY() / moderator;

	speedL += -j_y + j_x;
	speedR += -j_y - j_x;

	// Sets the talons for the base
	setDriveTalons();

	// reset speeds to 0
	reset();

}

void Controls::intake() {
	intake_value = 1.0;

	if (!library->getSensors()->getIntakeSensor()) {
		hold_value = 1.0;
	}
}

void Controls::trebuchet() {
	top_value = -1.0;
	bottom_value = 1.0;
}

void Controls::liftSpears() {
	spearSolenoid->Set(DoubleSolenoid::kForward);
}

void Controls::lowerSpears() {
	spearSolenoid->Set(DoubleSolenoid::kReverse);
}

void Controls::stopSpears() {
	spearSolenoid->Set(DoubleSolenoid::kOff);
}

void Controls::update() {
	if (library->getSensors()->getDriveControllerAButton()) {
		// boost driving when holding "A" button on controller
		moderator = 1.5;
	}
	else {
		// standard moderator
		moderator = 2.0;
	}

	reset();
}

void Controls::reset() {
	// drive variables
	speedL = 0.0;
	speedR = 0.0;
	j_x = 0.0;
	j_y = 0.0;

	// ball intake/holding variables
	intake_value = 0.0;
	hold_value = 0.0;

	// trebuchet variables
	top_value = 0.0;
	bottom_value = 0.0;
}

void Controls::setTalons() {
	// Sets the talons for the base
	talon0.Set(-speedR);
	talon1.Set(-speedR);
	talon2.Set(speedL);
	talon3.Set(speedL);

	// Set intake and holding talons
	intake_motor.Set(intake_value);
	holding_motor.Set(hold_value);

	// Set trebuchet talons
	trebuchet_top_motor.Set(top_value);
	trebuchet_bottom_motor.Set(bottom_value);
}