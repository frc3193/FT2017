// RobotBuilder Version: 2.0
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.


#include "ShooterDefault.h"

// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTOR

ShooterDefault::ShooterDefault(): Command() {
        // Use requires() here to declare subsystem dependencies
    // eg. requires(Robot::chassis.get());
    // BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=REQUIRES
	Requires(Robot::shooter.get());
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=REQUIRES
}

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTOR

// Called just before this Command runs the first time
void ShooterDefault::Initialize() {

}

// Called repeatedly when this Command is scheduled to run
void ShooterDefault::Execute() {
	Robot::shooter->m_lRPM = Robot::shooter->lEncoder->GetRate();
	Robot::shooter->m_rRPM = Robot::shooter->rEncoder->GetRate();

	SmartDashboard::PutNumber("lRPM", Robot::shooter->m_lRPM);
	SmartDashboard::PutNumber("rRPM", Robot::shooter->m_rRPM);


	// use bang-bang & feed-forward combo to get shooters up to m_desiredSpeed
	if(Robot::shooter->m_shoot)
	{
		// left shooter bang-bang
		if (Robot::shooter->m_lRPM < Robot::shooter->m_desiredSpeed)
			Robot::shooter->lShoot->Set(1.0);
		else
			Robot::shooter->lShoot->Set(0.75);

		// right shooter bang-bang
		if (Robot::shooter->m_rRPM < Robot::shooter->m_desiredSpeed)
			Robot::shooter->rShoot->Set(1.0);
		else
			Robot::shooter->rShoot->Set(0.75);
	}
	else
	{
		Robot::shooter->lShoot->Set(0);
		Robot::shooter->rShoot->Set(0);
	}
}

// Make this return true when this Command no longer needs to run execute()
bool ShooterDefault::IsFinished() {
    return false;
}

// Called once after isFinished returns true
void ShooterDefault::End() {

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ShooterDefault::Interrupted() {

}