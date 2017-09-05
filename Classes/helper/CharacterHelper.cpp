//
//  CharacterHelper.cpp
//  CharacterBehavior
//
//  Created by weilove-jiajiaju on 2017/8/24.
//
//

#include "CharacterHelper.hpp"

#include "GameManager.hpp"
#include "Character.hpp"

std::string CharacterHelper::getCharacterNormalFrameName(const CharacterConfig &characterConfig){
    return std::string("character_") + intToString(characterConfig.animation_stand[0]) + ".png";
}

std::string CharacterHelper::getCharacterNormalFrameName(const std::string &characterTypeName){
    const CharacterConfig characterConfig = GameManagerInstance->configManager->getCharacterConfig(characterTypeName);
    return std::string("character_") + intToString(characterConfig.animation_stand[0]) + ".png";
}

std::string CharacterHelper::getCharacterFrameName(const CharacterConfig &characterConfig, int frameNumber){
    return std::string("character_") + intToString(frameNumber) + ".png";
}

std::string CharacterHelper::getCharacterFrameName(const std::string &characterTypeName, int frameNumber){
    return std::string("character_") + intToString(frameNumber) + ".png";
}

int CharacterHelper::getCharacterAttack(Character *attackCharacter, Character *defenceCharacter){
    int attack = static_cast<float>(attackCharacter->characterConfig.attack) * (1 - static_cast<float>(defenceCharacter->characterConfig.defence) / 100.0f);
    if (attack > 100){
        attack = 100;
    }
    if (attack < 0){
        attack = 0;
    }
    return attack;
}
