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
}

void ConfigManager::_loadBuildingConfig(){
    
}
