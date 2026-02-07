// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc2/command/SubsystemBase.h>
#include <photon/PhotonCamera.h>
#include <photon/PhotonPoseEstimator.h>
#include <photon/PhotonUtils.h>
#include <vector>
#include <map>
#include <unordered_map>
class VisionSubsystem : public frc2::SubsystemBase {
 public:
  VisionSubsystem();
  struct TargetObj {
    int id = -1;
    double x = 0.0;
    double y = 0.0;
    double z = 0.0;
  };
  /**
   * Will be called periodically whenever the CommandScheduler runs.
   */
  void Periodic() override;

  std::shared_ptr<std::map<int, TargetObj>> targetResult;
  std::unordered_map<int, TargetObj> targetMap;
  photon::PhotonCamera camera{"1229_Camera"};
  photon::PhotonTrackedTarget BestResult();
  photon::PhotonTrackedTarget ClosestTarget();
  photon::PhotonPipelineResult getResult();
  void getCameraRobotPoses();
  
  bool wasPrevNull = false;
  bool gotCamResults = false;

 private:
  // Components (e.g. motor controllers and sensors) should generally be
  // declared private and exposed only through public methods.
  
};
