//
//  CharacterStateWait.cpp
//  CharacterBehavior
//
//  Created by weilove-jiajiaju on 2017/9/3.
//
//

#include "CharacterStateWait.hpp"

#include "GameManager.hpp"

#include "CharacterStateWalk.hpp"
#include "CharacterFindAttackTarget.hpp"

void CharacterStateWait::enter(Character *character){
    character->avatar->setSpriteFrame(GameManagerInstance->characterHelper->getCharacterNormalFrameName(character->characterConfig));
}

void CharacterStateWait::execute(Character *character, float dt){
//    CCLOG("I'm waitting! %d", character->getEntityID());
    CharacterFindAttackTarget::findAttackTarget(character);
    if (character->attackTarget){
        character->stateMachine->changeState(CharacterStateWalk::getInstance());
    }
}

void CharacterStateWait::exit(Character *character){
    
}
