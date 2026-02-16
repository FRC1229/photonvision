// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "Robot.h"

#include <frc2/command/CommandScheduler.h>
#include <cameraserver/CameraServer.h>
#include "networktables/NetworkTableInstance.h"
#include <photon/PhotonCamera.h>
#include <photon/targeting/PhotonPipelineResult.h>
#include <iostream>


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
  



  // frc2::CommandScheduler::GetInstance().Run();
  //unreadResults = m_container.m_vision->camera.GetAllUnreadResults();

  // m_container.m_vision->getCameraRobotPoses();

  // for (auto const& [id, obj] : m_container.m_vision->targetMap) {
  //   fmt::print("Key ID: {}, Struct Data -> ID: {}, X: {:.2f}, Y: {:.2f}, Z: {:.2f}\n", 
  //               id, obj.id, obj.x, obj.y, obj.z);
  // }
  
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
  // m_autonomousCommand = m_container.GetAutonomousCommand();

  // if (m_autonomousCommand) {
  //   m_autonomousCommand->Schedule();
  // }
}

void Robot::AutonomousPeriodic() {}

void Robot::TeleopInit() {
  // This makes sure that the autonomous stops running when
  // teleop starts running. If you want the autonomous to
  // continue until interrupted by another command, remove
  // this line or comment it out.
  // if (m_autonomousCommand) {
  //   m_autonomousCommand->Cancel();
  // }
  // camera{"cam1229_2"};
  //unreadResults = m_container.m_vision->camera.GetAllUnreadResults();
  
  frc::CameraServer::StartAutomaticCapture();
}

/**
 * This function is called periodically during operator control.
 */
void Robot::TeleopPeriodic() {
  std::vector<photon::PhotonPipelineResult> results = camera.GetAllUnreadResults();
  for (auto result : results) {
    if (result.HasTargets()) {
      // test this loop thorugh targets
      auto targets = result.GetTargets();
      for (auto target : targets) {
        std::cout << target.GetFiducialId() << std::endl;
      }
      // TTHIS IS CODE ISTN TESTED, PLEASE TEST
      
      // std::cout << result.GetTargets().size() << std::endl;
      // for (auto target : result.GetTargets()) {
      //   std::cout << target.GetBestCameraToTarget().X().value() << std::endl;
      // }
      // for (auto target : result.GetTargets()) {
      //   std::cout << target. << std::endl;
      // }

      // std::cout << " TRUE" << std::endl;
    } else {
      // std::cout << " FALSE" << std::endl;
    }
  }
  
  // myloopcounter++;
  
  // if (myloopcounter>=3000) {
  //   myloopcounter = 0;
  // }

  // nt::NetworkTableInstance inst = nt::NetworkTableInstance::GetDefault();
  // if (inst.IsConnected()) {
  //   if (m_container.m_vision == nullptr) {
  //     auto unreadResults = camera.GetAllUnreadResults();
  //     std::cout << "yay"  << std::endl;
  //   } else {
  //     std::cout << "jesse's fault" << std::endl;
  //   }
  //   // std::cout << "hello" << std::endl;
  //   // if (Is500msLoop(0)) {
  //   //   std::cout << "boom " << std::endl;
  //   //   unreadResults = m_container.m_vision->camera.GetAllUnreadResults();
  //   //   std::cout << "ran" << std::endl;
  //   // }
  // } else {
  //   std::cout << "banana" << std::endl;
  // }
  // // if (Is500msLoop(0) && m_container.m_vision->camera.IsConnected()) {
  // //   m_container.m_vision->getCameraRobotPoses();
  //   // std::cout << m_container.m_vision-> camera.IsConnected() << std::endl;
  //   //std::cout << m_container.m_vision->camera.IsConnected() << std::endl;
  // // } else if (Is500msLoop(0)) {
  // //   std::cout << "hello world" << std::endl;
  // // }
}

// bool Robot::Is500msLoop(int offset) {
//   bool retb = false;
//   if (((myloopcounter)%25) == 0) {
//     retb = true;
//   }
//   return retb;
// }

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
