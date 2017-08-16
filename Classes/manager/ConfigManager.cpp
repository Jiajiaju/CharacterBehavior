//
//  ConfigManager.cpp
//  CharacterBehavior
//
//  Created by weilove-jiajiaju on 2017/8/16.
//
//

#include "ConfigManager.hpp"

#include "json/document.h"
#include "json/writer.h"
#include "json/stringbuffer.h"

void ConfigManager::init(){
    _loadCharacterConfig();
    _loadBuildingConfig();
}

void ConfigManager::_loadCharacterConfig(){
    std::string configData = cocos2d::FileUtils::getInstance()->getStringFromFile("res/config/character_config.json");
    rapidjson::Document configDoc;
    configDoc.Parse<0>(configData.c_str());
    assert(!configDoc.HasParseError());
    rapidjson::Value& soldier = configDoc["soldier"];
    for (auto iter = soldier.MemberBegin(); iter != soldier.MemberEnd(); ++iter){
        CCLOG("%s", iter->name.GetString());
        rapidjson::Value& item = iter->value;
        CCLOG("%s, %d", item["type"].GetString(), item["attack"].GetInt());
    }
    
}

void ConfigManager::_loadBuildingConfig(){
    
}

const CharacterConfig& ConfigManager::getCharacterConfig(const std::string &typeName){
    assert(_characterConfig.find(typeName) != _characterConfig.end());
    return _characterConfig[typeName];
}

const BuildingConfig& ConfigManager::getBuildingConfig(const std::string &typeName){
    assert(_buildingConfig.find(typeName) != _buildingConfig.end());
    return _buildingConfig[typeName];
}
