#include "WPILib.h"
#include "Commands/Command.h"
#include "Commands/ExampleCommand.h"
#include "CommandBase.h"
#include <stdio.h>

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

	//CameraServer *cam = CameraServer::GetInstance();
	//USBCamera *leCam = new USBCamera("cam0", true);

	void RobotInit()
	{
		CommandBase::init();
		chooser = new SendableChooser();
		chooser->AddDefault("Default Auto", new ExampleCommand());
		//chooser->AddObject("My Auto", new MyAutoCommand());
		SmartDashboard::PutData("Auto Modes", chooser);

		// Camera stuff
		//leCam->OpenCamera();
		//leCam->SetExposureManual(50);
		//cam->StartAutomaticCapture();
		CameraServer::GetInstance()->SetQuality(50);
		CameraServer::GetInstance()->StartAutomaticCapture();

		base_control = new Joystick(5);
		action_control = new Joystick(4);

		talon0 = new Talon(0);
		talon1 = new Talon(1);
		talon2 = new Talon(2);
		talon3 = new Talon(3);

		intake_motor = new CANTalon(4);
		holding_motor = new CANTalon(1);
		trebuchet_top_motor = new CANTalon(2);
		trebuchet_bot_motor = new CANTalon(3);

		intake_sensor = new DigitalInput(0);

		is_intaking = false;

		spearSolenoid = new DoubleSolenoid(6, 1, 2);

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
			treb_top = -1.0 * (((action_control->GetThrottle() - 1) / 2.0));
			treb_bot = 1.0 * (((action_control->GetThrottle() - 1) / 2.0));
			hold_val = 1.0;
		}
		// Lob the ball at low power from the shooter into the low goal
		if (action_control->GetRawButton(6)) {
			treb_top = 0.35;
			treb_bot = -0.35;
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
			speedL /= 2.0;
			speedR /= 2.0;
		}

		// Pneumatics section

		enabled = c->Enabled();
		pressureSwitch = c->GetPressureSwitchValue();
		current = c->GetCompressorCurrent();

		// Spears
		if (action_control->GetRawButton(7)) {
			spearSolenoid->Set(DoubleSolenoid::Value::kForward);
		} else if (action_control->GetRawButton(8)) {
			spearSolenoid->Set(DoubleSolenoid::Value::kReverse);
		}

		// Compressor
		if (action_control->GetRawButton(11)) {
			c->Start();
		} else if (action_control->GetRawButton(12)) {
			c->Stop();
		}


		// Set driving talons
		talon0->Set(speedR);
		talon1->Set(speedR);
		talon2->Set(-speedL);
		talon3->Set(-speedL);

		// Set shooting and intake talons
		std::cout << ((action_control->GetThrottle() - 1) / 2.0)*100 << std::endl;
		trebuchet_top_motor->Set(treb_top);
		trebuchet_bot_motor->Set(treb_bot);
		intake_motor->Set(-intake_val);
		holding_motor->Set(hold_val);

		if (current > 125.0) {
			// over pressure
		}

	}

	void TestPeriodic()
	{
		LiveWindow::GetInstance()->Run();
	}
};

START_ROBOT_CLASS(Robot)

