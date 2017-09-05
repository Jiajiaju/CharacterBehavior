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
    character->attackIntervalCounter = 0;
}

void CharacterStateAttack::execute(Character *character, float dt){
    if (character->isDead()){
        character->stateMachine->changeState(CharacterStateDead::getInstance());
        return;
    }
    
    // animation
    if (character->animationFrameCounter == character->characterConfig.animation_attack[2]){
        character->attackIntervalCounter += 1;
        if (character->attackIntervalCounter <= character->characterConfig.attack_interval){
            return;
        }
        character->attackIntervalCounter = 0;
    }
    character->animationSpeedCounter += 1;
    if (character->animationSpeedCounter > character->characterConfig.animation_attack_speed){
        character->animationSpeedCounter = 0;
        character->animationFrameCounter += 1;
        if (character->animationFrameCounter > character->characterConfig.animation_attack[2]){
            character->animationFrameCounter = character->characterConfig.animation_attack[0];
        }
        
        character->avatar->setSpriteFrame(GameManagerInstance->characterHelper->getCharacterFrameName(character->characterConfig, character->animationFrameCounter));
        
        if (character->animationFrameCounter == character->characterConfig.animation_attack[1]){
            int attack = CharacterHelper::getCharacterAttack(character, character->attackTarget);
            character->attackTarget->loseBlood(attack);
            if (character->isDead()){
                character->stateMachine->changeState(CharacterStateDead::getInstance());
            }
            if (character->attackTarget->isDead()){
                character->attackTarget->stateMachine->changeState(CharacterStateDead::getInstance());
                character->stateMachine->changeState(CharacterStateWalk::getInstance());
            }
        }
    }
}

void CharacterStateAttack::exit(Character *character){
    
}
