//
//  CharacterHelper.cpp
//  CharacterBehavior
//
//  Created by weilove-jiajiaju on 2017/8/24.
//
//

#include "CharacterHelper.hpp"

#include "GameManager.hpp"

std::string CharacterHelper::getCharacterNormalFrameName(const CharacterConfig &characterConfig){
    return std::string("character_") + intToString(characterConfig.animation_walk[0]) + ".png";
}

std::string CharacterHelper::getCharacterNormalFrameName(const std::string &characterTypeName){
    const CharacterConfig characterConfig = GameManagerInstance->configManager->getCharacterConfig(characterTypeName);
    return std::string("character_") + intToString(characterConfig.animation_walk[0]) + ".png";
}

std::string CharacterHelper::getCharacterFrameName(const CharacterConfig &characterConfig, int frameNumber){
    return std::string("character_") + intToString(frameNumber) + ".png";
}

std::string CharacterHelper::getCharacterFrameName(const std::string &characterTypeName, int frameNumber){
    const CharacterConfig characterConfig = GameManagerInstance->configManager->getCharacterConfig(characterTypeName);
    return std::string("character_") + intToString(frameNumber) + ".png";
}
