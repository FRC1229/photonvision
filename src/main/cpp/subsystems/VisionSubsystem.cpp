// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "subsystems/VisionSubsystem.h"
#include "networktables/NetworkTable.h"
#include "networktables/NetworkTableInstance.h"
#include "networktables/NetworkTableEntry.h"
#include "networktables/NetworkTableValue.h"
#include <frc/smartdashboard/SmartDashboard.h>
#include <span>
#include <vector>
#include <iostream>
#include <ostream>


VisionSubsystem::VisionSubsystem() = default;

// This method will be called once per s                                                                            cheduler run
void VisionSubsystem::Periodic() {}


photon::PhotonPipelineResult VisionSubsystem::getResult(){
    // if(camera.GetLatestResult().HasTargets()){
    //     return camera.GetLatestResult();
    // }
}

photon::PhotonTrackedTarget VisionSubsystem::BestResult(){
    // if(getResult().HasTargets()){
    //     return getResult().GetBestTarget();
    // }
   
}

// std::ostream& operator<<(std::ostream& out, const Course* course) {
//     out << course.getName();
//     return out;
// }

void VisionSubsystem::getCameraRobotPoses(){
    // auto result = camera.GetLatestResult();
    // bool hasTarget = result.HasTargets();
    // auto results = camera.GetAllUnreadResults();
    // for (int i = 0; i < results.size(); i++) {
    //     std::cout << "hello" << std::endl;
    // }
    // auto unreadResults = camera.GetAllUnreadResults();
    // for (const auto& result : unreadResults) {
    //     if (result.HasTargets()) {
    //         auto target = result.GetBestTarget();

    //         std::cout << "Yaw: " << target.GetYaw();

    //     } else {
    //         std::cout << "No Targets" << std::endl;
    //     }
    // }

    // return;
    
    // if (getResult().HasTargets()) {
        
    //     std::vector<photon::PhotonPipelineResult> unreadResults = camera.GetAllUnreadResults();
    //     if (unreadResults.empty()) {
    //         std::cout << "Camera has no results" << std::endl;
    //     } else {
    //         targetMap.clear();
    //         for (auto target : getResult().GetTargets()) {
    //             TargetObj targetObj;
    //             frc::Transform3d best_camera_to_target = target.GetBestCameraToTarget();

    //             targetObj.id = target.GetFiducialId();
    //             targetObj.x = best_camera_to_target.X().value();
    //             targetObj.y = best_camera_to_target.Y().value();
    //             targetObj.z = best_camera_to_target.Z().value();

    //             targetMap[targetObj.id] = targetObj;

                
    //         }
    //     }
    // }
    
}

