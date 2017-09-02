//
//  ConfigManager.cpp
//  CharacterBehavior
//
//  Created by weilove-jiajiaju on 2017/8/16.
//
//

#include "ConfigManager.hpp"

#pragma mark - common

void ConfigManager::init(){
    _loadCharacterConfig();
    _loadBuildingConfig();
    _loadCharacterWavesConfig();
}

#pragma mark - character & building

CharacterConfig ConfigManager::_makeCharacterConfigItem(rapidjson::Value &configItem){
    CharacterConfig characterConfig;
    characterConfig.type = configItem["type"].GetString();
    characterConfig.hp = configItem["hp"].GetInt();
    characterConfig.attack = configItem["attack"].GetInt();
    characterConfig.defence = configItem["defence"].GetInt();
    characterConfig.speed = configItem["speed"].GetInt();
    
    rapidjson::Value& walkConfigArray = configItem["animation_walk"];
    characterConfig.animation_walk[0] = walkConfigArray[0].GetInt();
    characterConfig.animation_walk[1] = walkConfigArray[1].GetInt();
    
    rapidjson::Value& attackConfigArray = configItem["animation_attack"];
    characterConfig.animation_attack[0] = attackConfigArray[0].GetInt();
    characterConfig.animation_attack[1] = attackConfigArray[1].GetInt();
    characterConfig.animation_attack[2] = attackConfigArray[2].GetInt();
    
    rapidjson::Value& deadConfigArray = configItem["animation_dead"];
    characterConfig.animation_dead[0] = deadConfigArray[0].GetInt();
    characterConfig.animation_dead[1] = deadConfigArray[1].GetInt();
    
    return characterConfig;
}

void ConfigManager::_loadCharacterConfig(){
    std::string configData = cocos2d::FileUtils::getInstance()->getStringFromFile("res/config/character_config.json");
    rapidjson::Document configDoc;
    configDoc.Parse<0>(configData.c_str());
    assert(!configDoc.HasParseError());
    rapidjson::Value& soldier = configDoc["soldier"];
    for (auto iter = soldier.MemberBegin(); iter != soldier.MemberEnd(); ++iter){
        std::string characterConfigKey = iter->name.GetString();
        rapidjson::Value& item = iter->value;
        CharacterConfig characterConfigValue = _makeCharacterConfigItem(item);
        _characterConfig[characterConfigKey] = characterConfigValue;
    }
    
    rapidjson::Value& enemy = configDoc["enemy"];
    for (auto iter = enemy.MemberBegin(); iter != enemy.MemberEnd(); ++iter){
        std::string characterConfigKey = iter->name.GetString();
        rapidjson::Value& item = iter->value;
        CharacterConfig characterConfigValue = _makeCharacterConfigItem(item);
        _characterConfig[characterConfigKey] = characterConfigValue;
    }
    
}

void ConfigManager::_loadBuildingConfig(){
    std::string configData = cocos2d::FileUtils::getInstance()->getStringFromFile("res/config/building_config.json");
    rapidjson::Document configDoc;
    configDoc.Parse<0>(configData.c_str());
    assert(!configDoc.HasParseError());
    for (auto iter = configDoc.MemberBegin(); iter != configDoc.MemberEnd(); ++iter){
        std::string buildingConfigKey = iter->name.GetString();
        rapidjson::Value& buildingConfigItem = iter->value;
        BuildingConfig buildingConfigValue;
        
        buildingConfigValue.appereance = buildingConfigItem["appereance"].GetString();
        buildingConfigValue.defence = buildingConfigItem["defence"].GetInt();
        
        buildingConfigValue.size[0] = buildingConfigItem["size"][0].GetInt();
        buildingConfigValue.size[1] = buildingConfigItem["size"][0].GetInt();
        
        buildingConfigValue.animation_produce[0] = buildingConfigItem["animation_produce"][0].GetInt();
        buildingConfigValue.animation_produce[1] = buildingConfigItem["animation_produce"][1].GetInt();
        
        rapidjson::Value& trainConfigArray = buildingConfigItem["train"];
        for (int i = 0; i < trainConfigArray.Capacity(); ++i){
            buildingConfigValue.train.push_back(trainConfigArray[i].GetString());
        }
        
        _buildingConfig[buildingConfigKey] = buildingConfigValue;
    }
}

const CharacterConfig& ConfigManager::getCharacterConfig(const std::string &typeName){
    assert(_characterConfig.find(typeName) != _characterConfig.end());
    return _characterConfig[typeName];
}

const BuildingConfig& ConfigManager::getBuildingConfig(const std::string &typeName){
    assert(_buildingConfig.find(typeName) != _buildingConfig.end());
    return _buildingConfig[typeName];
}

#pragma mark - waves

CharacterWaveConfig ConfigManager::_makeCharacterWaveConfigItem(rapidjson::Value &configItem){
    assert(configItem.IsArray());
    CharacterWaveConfig waveConfig;
    waveConfig.delay = configItem[0].GetInt();
    waveConfig.typeName = configItem[1].GetString();
    waveConfig.column = configItem[2].GetInt();
    waveConfig.row = configItem[3].GetInt();
    return waveConfig;
}

void ConfigManager::_loadCharacterWavesConfig(){
    std::string configData = cocos2d::FileUtils::getInstance()->getStringFromFile("res/config/character_waves_config.json");
    rapidjson::Document configDoc;
    configDoc.Parse<0>(configData.c_str());
    assert(!configDoc.HasParseError());
    
    for (auto iter = configDoc.Begin(); iter != configDoc.End(); ++iter){
        int waveID = (*iter)["waves_id"].GetInt();
        rapidjson::Value& configItem = (*iter)["waves"];
        assert(configItem.IsArray());
        for (auto itemIter = configItem.Begin(); itemIter != configItem.End(); ++itemIter){
            _characterWavesConfig[waveID].push_back(_makeCharacterWaveConfigItem(*itemIter));
        }
    }
    
//    CCLOG("%s", __func__);
//    for (auto iter = _characterWavesConfig.begin(); iter != _characterWavesConfig.end(); ++iter){
//        CCLOG("waves id: %d", iter->first);
//        for (auto iteriter = iter->second.begin(); iteriter != iter->second.end(); ++iteriter){
//            CCLOG("%s, %d, %d, %d", iteriter->typeName.c_str(), iteriter->delay, iteriter->column, iteriter->row);
//        }
//    }
}

const std::vector<CharacterWaveConfig>& ConfigManager::getCharacterWaves(int wavesID){
    assert(_characterWavesConfig.find(wavesID) != _characterWavesConfig.end());
    return _characterWavesConfig[wavesID];
}

