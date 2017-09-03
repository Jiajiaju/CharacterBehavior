//
//  CharacterStateWait.cpp
//  CharacterBehavior
//
//  Created by weilove-jiajiaju on 2017/9/3.
//
//

#include "CharacterStateWait.hpp"

#include "GameManager.hpp"

void CharacterStateWait::enter(Character *character){
    character->avatar->setSpriteFrame(GameManagerInstance->characterHelper->getCharacterNormalFrameName(character->characterConfig));
}

void CharacterStateWait::execute(Character *character, float dt){
//    CCLOG("I'm waitting! %d", character->getEntityID());
}

void CharacterStateWait::exit(Character *character){
    
}
