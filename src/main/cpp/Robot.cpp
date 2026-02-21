// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "Robot.h"

#include <frc2/command/CommandScheduler.h>
#include <cameraserver/CameraServer.h>
#include "networktables/NetworkTableInstance.h"
#include <photon/PhotonCamera.h>
#include <photon/targeting/PhotonPipelineResult.h>
#include <photon/struct/PhotonTrackedTargetStruct.h>
#include <iostream>
#include <cmath>


Robot::Robot() {}

/**
 * This function is called every 20 ms, no matter the mode. Use
 * this for items like diagnostics that you want to run during disabled,
 * autonomous, teleoperated and test.
 *
 * <p> This runs after the mode specific periodic functions, but before
 * LiveWindow and SmartDashboard integrated updating.
 */
void Robot::RobotPeriodic() {

}

/**
 * This function is called once each time the robot enters Disabled mode. You
 * can use it to reset any subsystem information you want to clear when the
 * robot is disabled.
 */
void Robot::DisabledInit() {}

void Robot::DisabledPeriodic() {}

/**
 * This autonomous runs the autonomous command selected by your {@link
 * RobotContainer} class.
 */
void Robot::AutonomousInit() {
  //m_container.m_arm.CalibrateEncoderValue();
  m_container.m_drive.ZeroHeading();
  m_container.m_drive.ResetEncoders();
  m_container.m_drive.ResetOdometry(frc::Pose2d{2_m,7_m,frc::Rotation2d{0_deg}});
  
  m_autonomousCommand = m_container.getAutonomousCommand();

  if (m_autonomousCommand) {                      //This code checks if `m_autonomousCommand` is not null and, if valid, 
    m_autonomousCommand->Schedule();               //schedules it to run during the autonomous period.
  }
}


void Robot::AutonomousPeriodic() {}
void Robot::TeleopInit() {
  m_container.m_drive.ZeroHeading();
  m_container.m_drive.ResetEncoders();
  m_container.m_drive.ResetOdometry(frc::Pose2d{0_m,0_m,frc::Rotation2d{0_deg}});

  // This makes sure that the autonomous stops running when
  // teleop starts running. If you want the autonomous to
  // continue until interrupted by another command, remove
  // this line or comment it out.
  //m_container.m_arm.CalibrateEncoderValue();

  
  if (m_autonomousCommand) {
    m_autonomousCommand->Cancel();
  }
  m_container.m_drive.ZeroHeading();
  frc::CameraServer::StartAutomaticCapture();
}


/**
 * This function is called periodically during operator control.
 */
void Robot::TeleopPeriodic() {
  
  myloopcounter++;
  
  if (myloopcounter>=3000) {
    myloopcounter = 0;
  }

  if (Is500msLoop(0)) {
    myloopcounter = 0;
    m_container.m_vision->getCameraRobotPoses();
    
  }


}

bool Robot::Is500msLoop(int offset) {
  bool retb = false;
  if (((myloopcounter)%25) == 0) {
    retb = true;
  }
  return retb;
}

/**
 * This function is called periodically during test mode.
 */
void Robot::TestPeriodic() {}

/**
 * This function is called once when the robot is first started up.
 */
void Robot::SimulationInit() {}

/**
 * This function is called periodically whilst in simulation.
 */
void Robot::SimulationPeriodic() {}

#ifndef RUNNING_FRC_TESTS
int main() {
  return frc::StartRobot<Robot>();
}
#endif
