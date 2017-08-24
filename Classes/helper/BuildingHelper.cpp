//
//  BuildingHelper.cpp
//  CharacterBehavior
//
//  Created by weilove-jiajiaju on 2017/8/24.
//
//

#include "BuildingHelper.hpp"

#include "utility.hpp"

#include "GameManager.hpp"

std::string BuildingHelper::getBuildingNormalFrameName(const BuildingConfig& buildingConfig){
    return std::string("building_") + intToString(buildingConfig.animation_produce[0]) + ".png";
}
std::string BuildingHelper::getBuildingNormalFrameName(const std::string& buildingTypeName){
    const BuildingConfig& buildingConfig = GameManagerInstance->configManager->getBuildingConfig(buildingTypeName);
    return std::string("building_") + intToString(buildingConfig.animation_produce[0]) + ".png";
}
std::string BuildingHelper::getBuildingFrameName(const BuildingConfig& buildingConfig, int frameNumber){
    return std::string("building_") + intToString(frameNumber) + ".png";
}
std::string BuildingHelper::getBuildingFrameName(const std::string& buildingTypeName, int frameNumber){
    return std::string("building_") + intToString(frameNumber) + ".png";
}
