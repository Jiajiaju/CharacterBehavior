//
//  BuildingAvatar.hpp
//  CharacterBehavior
//
//  Created by weilove-jiajiaju on 2017/8/15.
//
//

#ifndef BuildingAvatar_hpp
#define BuildingAvatar_hpp

#include <stdio.h>
#include "BaseEntityAvatar.hpp"

#include "BuildingConfig.hpp"

class BuildingAvatar: public BaseEntityAvatar{
private:
    BuildingAvatar(const BuildingConfig& config):buildingConfig(config){}
    ~BuildingAvatar(){}
public:
    
    BuildingConfig buildingConfig;
    
    static BuildingAvatar* createBuildingAvatar(const BuildingConfig& config);
    virtual bool init();
};

#endif /* BuildingAvatar_hpp */
