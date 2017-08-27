//
//  CharacterStateWalk.cpp
//  CharacterBehavior
//
//  Created by weilove-jiajiaju on 2017/8/9.
//
//

#include "CharacterStateWalk.hpp"

#include "GameManager.hpp"

#include "CharacterStateIdle.hpp"

void CharacterStateWalk::enter(Character *character){
    character->animationFrameCounter = character->characterConfig.animation_walk[0];
    
}

void CharacterStateWalk::execute(Character *character, float dt){
    
    // animation
    character->aniamtionSpeedCounter += 1;
    if (character->aniamtionSpeedCounter > character->animationSpeed){
        character->aniamtionSpeedCounter = 0;
        character->animationFrameCounter += 1;
        if (character->animationFrameCounter > character->characterConfig.animation_walk[1]){
            character->animationFrameCounter = character->characterConfig.animation_walk[0];
        }
        
        character->avatar->setSpriteFrame(GameManagerInstance->characterHelper->getCharacterFrameName(character->characterConfig, character->animationFrameCounter));
    }
    
    // logic
    if (character->attackTarget){
        return;
    }
    
    if (character->targetTile != character->currentTile){
        return;
    }
    
    character->stateMachine->setCurrentState(CharacterStateIdle::getInstance());
    
}

void CharacterStateWalk::exit(Character *character){
    character->animationFrameCounter = character->characterConfig.animation_walk[0];
}
