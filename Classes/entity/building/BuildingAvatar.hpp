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

class BuildingAvatar: public BaseEntityAvatar{
private:
    BuildingAvatar(){}
    ~BuildingAvatar(){}
public:
    
    static BuildingAvatar* createBuildingAvatar();
    virtual bool init();
};

#endif /* BuildingAvatar_hpp */
