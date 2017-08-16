//
//  ConfigManager.hpp
//  CharacterBehavior
//
//  Created by weilove-jiajiaju on 2017/8/16.
//
//

#ifndef ConfigManager_hpp
#define ConfigManager_hpp

#include <stdio.h>
#include "cocos2d.h"
#include "Singleton.hpp"

class ConfigManager: public Singleton<ConfigManager>{
private:
    void _loadCharacterConfig();
    void _loadBuildingConfig();
public:
    void init();
};

#endif /* ConfigManager_hpp */
