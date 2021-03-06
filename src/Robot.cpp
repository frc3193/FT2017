// RobotBuilder Version: 2.0
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.


#include "Robot.h"
#include "Preferences.h"
#include "SmartDashboard/SendableChooser.h"
#include "SmartDashboard/SmartDashboard.h"

// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INITIALIZATION
std::shared_ptr<Chassis> Robot::chassis;
std::shared_ptr<Shooter> Robot::shooter;
std::shared_ptr<Intake> Robot::intake;
std::shared_ptr<Gear> Robot::gear;
std::shared_ptr<Climber> Robot::climber;
std::shared_ptr<Feeder> Robot::feeder;
std::unique_ptr<OI> Robot::oi;

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INITIALIZATION

Preferences* Robot::robotPref = 0; // used for saving shootSpeed

void Robot::RobotInit() {
	RobotMap::init();
	robotPref = Preferences::GetInstance();
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTORS
    chassis.reset(new Chassis());
    shooter.reset(new Shooter());
    intake.reset(new Intake());
    gear.reset(new Gear());
    climber.reset(new Climber());
    feeder.reset(new Feeder());

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTORS
	// This MUST be here. If the OI creates Commands (which it very likely
	// will), constructing it during the construction of CommandBase (from
	// which commands extend), subsystems are not guaranteed to be
	// yet. Thus, their requires() statements may grab null pointers. Bad
	// news. Don't move it.
	oi.reset(new OI());

	// auto choosing; each option is selected via an int parameter to AutoCommand()
	autonomousChooser.AddDefault("StraightGear", "auto0");
	autonomousChooser.AddObject("Auto #1", "auto1");
	autonomousChooser.AddObject("BlueShootCross", "auto2");
	autonomousChooser.AddObject("BlueShootGear", "auto3");
	autonomousChooser.AddObject("RedShootCross", "auto4");
	autonomousChooser.AddObject("RedShootGear", "auto5");
	autonomousChooser.AddObject("BlueFarGear", "auto6");
	autonomousChooser.AddObject("RedFarGear", "auto7");



	SmartDashboard::PutData("Autonomous modes", &autonomousChooser);

	// Camera #1
	CameraServer::GetInstance()->StartAutomaticCapture(0);

	// initializing chassis as forwards
	Robot::chassis->mIsReversed = false;
  }

/**
 * This function is called when the disabled button is hit.
 * You can use it to reset subsystems before shutting down.
 */
void Robot::DisabledInit(){
	Robot::gear->tilt->Set(DoubleSolenoid::kForward); // Tilt gear
}

void Robot::DisabledPeriodic() {
	Scheduler::GetInstance()->Run();
}

void Robot::AutonomousInit() {
	// instantiate the command used for the autonomous period
	Robot::chassis->shift->Set(DoubleSolenoid::kReverse);
//	Robot::gear->tilt->Set(DoubleSolenoid::kReverse);
	Robot::gear->tilt->Set(DoubleSolenoid::kReverse); // Tilt gear back.
	autonomousCommand.reset(new AutoCommand(autonomousChooser.GetSelected()));

	if (autonomousCommand.get() != nullptr)
		autonomousCommand->Start();
}

void Robot::AutonomousPeriodic() {
	Scheduler::GetInstance()->Run();
}

void Robot::TeleopInit() {
	// This makes sure that the autonomous stops running when
	// teleop starts running. If you want the autonomous to
	// continue until interrupted by another command, remove
	// these lines or comment it out.
	if (autonomousCommand.get() != nullptr)
		autonomousCommand->Cancel();

	// necessary to avoid overwriting pre-existing preferences, if they exist
	// TODO: set default RPM of shootSpeed once determined!
	Robot::gear->tilt->Set(DoubleSolenoid::kReverse); // Tilt gear back.
	if (!Robot::robotPref->ContainsKey("shootSpeed"))
			Robot::robotPref->PutInt("shootSpeed", 1090);
		Robot::shooter->mDesiredSpeed = Robot::robotPref->GetInt("shootSpeed", 1090);
}

void Robot::TeleopPeriodic() {
	Scheduler::GetInstance()->Run();
}

void Robot::TestPeriodic() {
	lw->Run();
}

START_ROBOT_CLASS(Robot);

