// RobotBuilder Version: 2.0
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.


#include "ChassisTankDrive.h"
#define LEFT_Y_AXIS 1
#define RIGHT_Y_AXIS 5

// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTOR

ChassisTankDrive::ChassisTankDrive(): Command() {
        // Use requires() here to declare subsystem dependencies
    // eg. requires(Robot::chassis.get());
    // BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=REQUIRES
	Requires(Robot::chassis.get());
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=REQUIRES
}

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTOR

// Called just before this Command runs the first time
void ChassisTankDrive::Initialize() {

}

// Called repeatedly when this Command is scheduled to run
void ChassisTankDrive::Execute() {
	// if reversed, flips left and right inputs so left joystick still drives left side and vice-versa
	if (Robot::chassis->mIsReversed)
	{
		Robot::chassis->robotDrive->TankDrive(Robot::oi->getdriver()->GetRawAxis(RIGHT_Y_AXIS),
											  Robot::oi->getdriver()->GetRawAxis(LEFT_Y_AXIS));
	}
	else
	{
		Robot::chassis->robotDrive->TankDrive(Robot::oi->getdriver()->GetRawAxis(LEFT_Y_AXIS),
											  Robot::oi->getdriver()->GetRawAxis(RIGHT_Y_AXIS));
	}

	SmartDashboard::PutNumber("Left Drive", Robot::chassis->leftEncoder->Get());
	SmartDashboard::PutNumber("Right Drive", Robot::chassis->rightEncoder->Get());
	SmartDashboard::PutNumber("GyroAngle", Robot::chassis->gyro->GetAngle());
}

// Make this return true when this Command no longer needs to run execute()
bool ChassisTankDrive::IsFinished() {
    return false;
}

// Called once after isFinished returns true
void ChassisTankDrive::End() {

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ChassisTankDrive::Interrupted() {

}
