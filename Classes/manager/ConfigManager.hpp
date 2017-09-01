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

#include "json/document.h"
#include "json/writer.h"
#include "json/stringbuffer.h"

#include "AllModel.hpp"

class ConfigManager: public Singleton<ConfigManager>{
    
#pragma mark - common
    
public:
    void init();
    
private:
    
#pragma mark - config & building
    CharacterConfig _makeCharacterConfigItem(rapidjson::Value& configItem);
    void _loadCharacterConfig();
    void _loadBuildingConfig();
    
    std::map<std::string, CharacterConfig> _characterConfig;
    std::map<std::string, BuildingConfig> _buildingConfig;
    
public:
    const CharacterConfig& getCharacterConfig(const std::string& typeName);
    const BuildingConfig& getBuildingConfig(const std::string& typeName);
    
#pragma mark - waves
private:
    std::map<int, std::vector<CharacterWaveConfig>> _characterWavesConfig;
    
    CharacterWaveConfig _makeCharacterWaveConfigItem(rapidjson::Value& configItem);
    void _loadCharacterWavesConfig();
    
public:
    const std::vector<CharacterWaveConfig>& getCharacterWaves(int wavesID);
    
};

#endif /* ConfigManager_hpp */
