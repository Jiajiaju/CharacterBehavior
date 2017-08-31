//
//  CharacterStateDead.cpp
//  CharacterBehavior
//
//  Created by weilove-jiajiaju on 2017/8/30.
//
//

#include "CharacterStateDead.hpp"

#include "GameManager.hpp"

#include "CharacterStateExit.hpp"

void CharacterStateDead::enter(Character *character){
    character->animationFrameCounter = character->characterConfig.animation_dead[0];
    character->animationSpeedCounter = 0;
    
    auto blood = cocos2d::Sprite::createWithSpriteFrameName("character_blood_0.png");
    blood->setAnchorPoint(cocos2d::Vec2(0.5, 0.5));
    character->avatarNode->addChild(blood);
}

void CharacterStateDead::execute(Character *character, float dt){
    // animation
    character->animationSpeedCounter += 1;
    if (character->animationSpeedCounter > character->animationSpeed){
        character->animationSpeedCounter = 0;
        character->animationFrameCounter += 1;
        character->avatar->setSpriteFrame(GameManagerInstance->characterHelper->getCharacterFrameName(character->characterConfig, character->animationFrameCounter));
        
        if (character->animationFrameCounter >= character->characterConfig.animation_dead[1]){
            character->exit();
            character->stateMachine->changeState(CharacterStateExit::getInstance());
            return;
        }
    }
    
}

void CharacterStateDead::exit(Character *character){
    
}
