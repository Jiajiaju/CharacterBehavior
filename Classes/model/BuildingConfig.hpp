//
//  BuildingConfig.hpp
//  CharacterBehavior
//
//  Created by weilove-jiajiaju on 2017/8/17.
//
//

#ifndef BuildingConfig_hpp
#define BuildingConfig_hpp

#include <stdio.h>

struct BuildingConfig{
    std::string appereance = "";
    int defence = 0;
    std::vector<std::string> train;
    int size[2] = {0, 0};
};

#endif /* BuildingConfig_hpp */
