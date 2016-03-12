
#include "WPILib.h"
#include "Commands/Command.h"
#include "Commands/ExampleCommand.h"
#include "CommandBase.h"

class Robot: public IterativeRobot
{
private:
	std::unique_ptr<Command> autonomousCommand;
	SendableChooser *chooser;

	Joystick *base_control;
	Joystick *action_control;

	CANTalon *intake_motor;
	CANTalon *holding_motor;
	CANTalon *trebuchet_top_motor;
	CANTalon *trebuchet_bot_motor;

	Talon *talon0;
	Talon *talon1;
	Talon *talon2;
	Talon *talon3;

	DoubleSolenoid *spearSolenoid;

	Compressor *c;

	DigitalInput *intake_sensor;

	double speedL, speedR;
	double hold_val;
	double treb_top, treb_bot;
	double intake_val;

	bool is_intaking;

	bool enabled;
	bool pressureSwitch;

	float current;

	void RobotInit()
	{
		CommandBase::init();
		chooser = new SendableChooser();
		chooser->AddDefault("Default Auto", new ExampleCommand());
		//chooser->AddObject("My Auto", new MyAutoCommand());
		SmartDashboard::PutData("Auto Modes", chooser);

		base_control = new Joystick(5);
		action_control = new Joystick(4);

		talon0 = new Talon(0);
		talon1 = new Talon(1);
		talon2 = new Talon(2);
		talon3 = new Talon(3);

		intake_motor = new CANTalon(0);
		holding_motor = new CANTalon(1);
		trebuchet_top_motor = new CANTalon(2);
		trebuchet_bot_motor = new CANTalon(3);

		intake_sensor = new DigitalInput(0);

		is_intaking = false;

		c = new Compressor(0);
	}

	/**
     * This function is called once each time the robot enters Disabled mode.
     * You can use it to reset any subsystem information you want to clear when
	 * the robot is disabled.
     */
	void DisabledInit()
	{
	}

	void DisabledPeriodic()
	{
		Scheduler::GetInstance()->Run();
	}

	/**
	 * This autonomous (along with the chooser code above) shows how to select between different autonomous modes
	 * using the dashboard. The sendable chooser code works with the Java SmartDashboard. If you prefer the LabVIEW
	 * Dashboard, remove all of the chooser code and uncomment the GetString code to get the auto name from the text box
	 * below the Gyro
	 *
	 * You can add additional auto modes by adding additional commands to the chooser code above (like the commented example)
	 * or additional comparisons to the if-else structure below with additional strings & commands.
	 */
	void AutonomousInit()
	{
		/* std::string autoSelected = SmartDashboard::GetString("Auto Selector", "Default");
		if(autoSelected == "My Auto") {
			autonomousCommand.reset(new MyAutoCommand());
		} else {
			autonomousCommand.reset(new ExampleCommand());
		} */

		autonomousCommand.reset((Command *)chooser->GetSelected());

		if (autonomousCommand != NULL)
			autonomousCommand->Start();
	}

	void AutonomousPeriodic()
	{
		Scheduler::GetInstance()->Run();
	}

	void TeleopInit()
	{
		// This makes sure that the autonomous stops running when
		// teleop starts running. If you want the autonomous to
		// continue until interrupted by another command, remove
		// this line or comment it out.
		if (autonomousCommand != NULL)
			autonomousCommand->Cancel();
	}

	void TeleopPeriodic()
	{
		Scheduler::GetInstance()->Run();

		// Reset all values
		speedL = 0.0;
		speedR = 0.0;
		treb_top = 0.0;
		treb_bot = 0.0;
		hold_val = 0.0;
		intake_val = 0.0;

		double j_x = base_control->GetRawAxis(0);
		double j_y = base_control->GetRawAxis(1);

		// Shoot
		if (action_control->GetRawButton(1)) {
			treb_top = 1.0;
			treb_bot = -1.0;
			hold_val = 1.0;
		}
		// Lob the ball at low power from the shooter into the low goal
		if (action_control->GetRawButton(6)) {
			treb_top = 0.5;
			treb_bot = -0.5;
			hold_val = 1.0;
		}
		// Reverse the ball back out the intake part
		if (action_control->GetRawButton(4)) {
			intake_val = -1.0;
			hold_val = -1.0;
		}
		// Intake the ball
		if (action_control->GetRawButton(2)) {
			hold_val = 1.0;
			intake_val = 1.0;
		}

		// Driving
		speedL += -j_y - j_x;
		speedR += -j_y + j_x;

		// Maximum drive motor speed
		if (base_control->GetRawButton(1)) {
			speedL /= 1.0;
			speedR /= 1.0;
		}
		// Slow drive motor speed for little adjustments in robot position
		else if (base_control->GetRawButton(2)) {
			speedL /= 3.0;
			speedR /= 3.0;
		}
		// Regular speed of drive motors
		else {
			speedL /= 1.75;
			speedR /= 1.75;
		}

		// Pneumatics section

		enabled = c->Enabled();
		pressureSwitch = c->GetPressureSwitchValue();
		current = c->GetCompressorCurrent();

		// Spears
		if (action_control->GetRawButton(7)) {
			spearSolenoid->Set(DoubleSolenoid::kForward);
		} else if (action_control->GetRawButton(8)) {
			spearSolenoid->Set(DoubleSolenoid::kReverse);
		}
		if (action_control->GetRawButton(9)) {
			spearSolenoid->Set(DoubleSolenoid::kOff);
		}

		// Compressor
		if (action_control->GetRawButton(11)) {
			c->SetClosedLoopControl(true);
		} else if (action_control->GetRawButton(12)) {
			c->SetClosedLoopControl(false);
		}


		// Set driving talons
		talon0->Set(speedR);
		talon1->Set(speedR);
		talon2->Set(-speedL);
		talon3->Set(-speedL);

		// Set shooting and intake talons
		trebuchet_top_motor->Set(-treb_top);
		trebuchet_bot_motor->Set(-treb_bot);
		intake_motor->Set(-intake_val);
		holding_motor->Set(hold_val);

	}

	void TestPeriodic()
	{
		LiveWindow::GetInstance()->Run();
	}
};

START_ROBOT_CLASS(Robot)

