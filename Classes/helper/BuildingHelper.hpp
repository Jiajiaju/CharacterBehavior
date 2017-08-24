//
//  BuildingHelper.hpp
//  CharacterBehavior
//
//  Created by weilove-jiajiaju on 2017/8/24.
//
//

#ifndef BuildingHelper_hpp
#define BuildingHelper_hpp

#include <stdio.h>
#include "cocos2d.h"
#include "Singleton.hpp"
#include "BuildingConfig.hpp"

class BuildingHelper: public Singleton<BuildingHelper>{
private:
public:
    
    static std::string getBuildingNormalFrameName(const BuildingConfig& buildingConfig);
    static std::string getBuildingNormalFrameName(const std::string& buildingTypeName);
    static std::string getBuildingFrameName(const BuildingConfig& buildingConfig, int frameNumber);
    static std::string getBuildingFrameName(const std::string& buildingTypeName, int frameNumber);
};

#endif /* BuildingHelper_hpp */
