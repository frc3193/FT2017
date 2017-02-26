// RobotBuilder Version: 2.0
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.


// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INCLUDES
#include "RobotMap.h"
#include "LiveWindow/LiveWindow.h"

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INCLUDES

// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=ALLOCATION
std::shared_ptr<SpeedController> RobotMap::chassisLeftA;
std::shared_ptr<SpeedController> RobotMap::chassisLeftB;
std::shared_ptr<SpeedController> RobotMap::chassisRightA;
std::shared_ptr<SpeedController> RobotMap::chassisRightB;
std::shared_ptr<RobotDrive> RobotMap::chassisRobotDrive;
std::shared_ptr<DoubleSolenoid> RobotMap::chassisShift;
std::shared_ptr<SpeedController> RobotMap::shooterLShoot;
std::shared_ptr<SpeedController> RobotMap::shooterRShoot;
std::shared_ptr<Encoder> RobotMap::shooterLEncoder;
std::shared_ptr<Encoder> RobotMap::shooterREncoder;
std::shared_ptr<SpeedController> RobotMap::intakeRoller;
std::shared_ptr<DoubleSolenoid> RobotMap::gearTilt;
std::shared_ptr<SpeedController> RobotMap::climberClimb;
std::shared_ptr<SpeedController> RobotMap::feederLeft;
std::shared_ptr<SpeedController> RobotMap::feederRight;

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=ALLOCATION

std::shared_ptr<ADXRS450_Gyro> RobotMap::chassisGyro;

void RobotMap::init() {
    // BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTORS
    LiveWindow *lw = LiveWindow::GetInstance();

    chassisLeftA.reset(new VictorSP(0));
    lw->AddActuator("Chassis", "LeftA", std::static_pointer_cast<VictorSP>(chassisLeftA));
    
    chassisLeftB.reset(new VictorSP(1));
    lw->AddActuator("Chassis", "LeftB", std::static_pointer_cast<VictorSP>(chassisLeftB));
    
    chassisRightA.reset(new VictorSP(8));
    lw->AddActuator("Chassis", "RightA", std::static_pointer_cast<VictorSP>(chassisRightA));
    
    chassisRightB.reset(new VictorSP(9));
    lw->AddActuator("Chassis", "RightB", std::static_pointer_cast<VictorSP>(chassisRightB));
    
    chassisRobotDrive.reset(new RobotDrive(chassisLeftA, chassisLeftB,
              chassisRightA, chassisRightB));
    
    chassisRobotDrive->SetSafetyEnabled(true);
        chassisRobotDrive->SetExpiration(0.1);
        chassisRobotDrive->SetSensitivity(0.5);
        chassisRobotDrive->SetMaxOutput(1.0);

    chassisShift.reset(new DoubleSolenoid(0, 2, 3));
    lw->AddActuator("Chassis", "Shift", chassisShift);
    
    shooterLShoot.reset(new VictorSP(2));
    lw->AddActuator("Shooter", "LShoot", std::static_pointer_cast<VictorSP>(shooterLShoot));
    
    shooterRShoot.reset(new VictorSP(6));
    lw->AddActuator("Shooter", "RShoot", std::static_pointer_cast<VictorSP>(shooterRShoot));
    
    shooterLEncoder.reset(new Encoder(0, 1, false, Encoder::k4X));
    lw->AddSensor("Shooter", "LEncoder", shooterLEncoder);
    shooterLEncoder->SetDistancePerPulse(1.0);
    shooterLEncoder->SetPIDSourceType(PIDSourceType::kRate);
    shooterREncoder.reset(new Encoder(2, 3, false, Encoder::k4X));
    lw->AddSensor("Shooter", "REncoder", shooterREncoder);
    shooterREncoder->SetDistancePerPulse(1.0);
    shooterREncoder->SetPIDSourceType(PIDSourceType::kRate);
    intakeRoller.reset(new VictorSP(5));
    lw->AddActuator("Intake", "Roller", std::static_pointer_cast<VictorSP>(intakeRoller));
    
    gearTilt.reset(new DoubleSolenoid(0, 0, 1));
    lw->AddActuator("Gear", "Tilt", gearTilt);
    
    climberClimb.reset(new Talon(4));
    lw->AddActuator("Climber", "Climb", std::static_pointer_cast<Talon>(climberClimb));
    
    feederLeft.reset(new VictorSP(3));
    lw->AddActuator("Feeder", "Left", std::static_pointer_cast<VictorSP>(feederLeft));
    
    feederRight.reset(new VictorSP(7));
    lw->AddActuator("Feeder", "Right", std::static_pointer_cast<VictorSP>(feederRight));
    


    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTORS

    chassisGyro.reset(new ADXRS450_Gyro(SPI::Port::kOnboardCS0));
}
