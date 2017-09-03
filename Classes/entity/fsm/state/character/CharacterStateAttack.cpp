//
//  CharacterStateAttack.cpp
//  CharacterBehavior
//
//  Created by weilove-jiajiaju on 2017/9/4.
//
//

#include "CharacterStateAttack.hpp"

#include "GameManager.hpp"
#include "CharacterStateWalk.hpp"
#include "CharacterStateDead.hpp"

void CharacterStateAttack::enter(Character *character){
    character->animationFrameCounter = character->characterConfig.animation_attack[0];
}

void CharacterStateAttack::execute(Character *character, float dt){
    if (character->isDead()){
        character->stateMachine->changeState(CharacterStateDead::getInstance());
        return;
    }
    
    // animation
    character->animationSpeedCounter += 1;
    if (character->animationSpeedCounter > character->animationSpeed){
        character->animationSpeedCounter = 0;
        character->animationFrameCounter += 1;
        if (character->animationFrameCounter > character->characterConfig.animation_attack[1]){
            character->animationFrameCounter = character->characterConfig.animation_attack[0];
        }
        
        character->avatar->setSpriteFrame(GameManagerInstance->characterHelper->getCharacterFrameName(character->characterConfig, character->animationFrameCounter));
    }
}

void CharacterStateAttack::exit(Character *character){
    
}
