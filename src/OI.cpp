// RobotBuilder Version: 2.0
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.


#include "OI.h"

// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INCLUDES
#include "SmartDashboard/SmartDashboard.h"
#include "Commands/AutoCommand.h"
#include "Commands/AutoDrive.h"
#include "Commands/AutoTurn.h"
#include "Commands/ChassisReverse.h"
#include "Commands/ChassisShift.h"
#include "Commands/ChassisTankDrive.h"
#include "Commands/ClimberGo.h"
#include "Commands/ClimberStop.h"
#include "Commands/FeederGo.h"
#include "Commands/FeederStop.h"
#include "Commands/GearTilt.h"
#include "Commands/IntakeForward.h"
#include "Commands/IntakeStop.h"
#include "Commands/PlaceHolder.h"
#include "Commands/ShootToggle.h"
#include "Commands/ShooterDefault.h"


    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INCLUDES

OI::OI() {
    // Process operator interface input here.
    // BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTORS
    coDriver.reset(new Joystick(1));
    
    cRStick.reset(new JoystickButton(coDriver.get(), 10));
    cRStick->WhileHeld(new PlaceHolder());
    cLStick.reset(new JoystickButton(coDriver.get(), 9));
    cLStick->WhileHeld(new ClimberGo());
    cRBumper.reset(new JoystickButton(coDriver.get(), 6));
    cRBumper->WhenPressed(new ShootToggle());
    cLBumper.reset(new JoystickButton(coDriver.get(), 5));
    cLBumper->WhileHeld(new FeederGo());
    cY.reset(new JoystickButton(coDriver.get(), 4));
    cY->WhileHeld(new PlaceHolder());
    cX.reset(new JoystickButton(coDriver.get(), 3));
    cX->WhenPressed(new PlaceHolder());
    cB.reset(new JoystickButton(coDriver.get(), 2));
    cB->WhenPressed(new GearTilt());
    cA.reset(new JoystickButton(coDriver.get(), 1));
    cA->WhileHeld(new IntakeForward());
    driver.reset(new Joystick(0));
    
    dRStick.reset(new JoystickButton(driver.get(), 10));
    dRStick->WhenPressed(new ChassisShift());
    dLStick.reset(new JoystickButton(driver.get(), 9));
    dLStick->WhenPressed(new ChassisShift());
    dRBumper.reset(new JoystickButton(driver.get(), 6));
    dRBumper->WhenPressed(new ChassisReverse());
    dLBumper.reset(new JoystickButton(driver.get(), 5));
    dLBumper->WhenPressed(new ChassisReverse());
    dY.reset(new JoystickButton(driver.get(), 4));
    dY->WhileHeld(new PlaceHolder());
    dX.reset(new JoystickButton(driver.get(), 3));
    dX->WhileHeld(new PlaceHolder());
    dB.reset(new JoystickButton(driver.get(), 2));
    dB->WhileHeld(new PlaceHolder());
    dA.reset(new JoystickButton(driver.get(), 1));
    dA->WhileHeld(new PlaceHolder());

    // SmartDashboard Buttons
    SmartDashboard::PutData("AutoCommand", new AutoCommand());
    SmartDashboard::PutData("AutoTurn", new AutoTurn());
    SmartDashboard::PutData("AutoDrive", new AutoDrive());
    SmartDashboard::PutData("FeederStop", new FeederStop());
    SmartDashboard::PutData("FeederGo", new FeederGo());
    SmartDashboard::PutData("ClimberGo", new ClimberGo());
    SmartDashboard::PutData("ChassisShift", new ChassisShift());
    SmartDashboard::PutData("GearTilt", new GearTilt());
    SmartDashboard::PutData("IntakeForward", new IntakeForward());
    SmartDashboard::PutData("ShootToggle", new ShootToggle());
    SmartDashboard::PutData("ChassisReverse", new ChassisReverse());
    SmartDashboard::PutData("ClimberStop", new ClimberStop());
    SmartDashboard::PutData("IntakeStop", new IntakeStop());
    SmartDashboard::PutData("ShooterDefault", new ShooterDefault());
    SmartDashboard::PutData("ChassisTankDrive", new ChassisTankDrive());
    SmartDashboard::PutData("PlaceHolder", new PlaceHolder());

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTORS
}

// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=FUNCTIONS

std::shared_ptr<Joystick> OI::getdriver() {
   return driver;
}

std::shared_ptr<Joystick> OI::getcoDriver() {
   return coDriver;
}


    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=FUNCTIONS
