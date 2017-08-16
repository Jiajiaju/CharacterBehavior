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

#include "AllModel.hpp"

class ConfigManager: public Singleton<ConfigManager>{
private:
    void _loadCharacterConfig();
    void _loadBuildingConfig();
    
    std::map<std::string, CharacterConfig> _characterConfig;
    std::map<std::string, BuildingConfig> _buildingConfig;
    
public:
    void init();
    
    const CharacterConfig& getCharacterConfig(const std::string& typeName);
    const BuildingConfig& getBuildingConfig(const std::string& typeName);
};

#endif /* ConfigManager_hpp */
