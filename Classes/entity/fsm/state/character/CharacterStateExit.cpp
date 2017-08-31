//
//  CharacterStateExit.cpp
//  CharacterBehavior
//
//  Created by weilove-jiajiaju on 2017/8/30.
//
//

#include "CharacterStateExit.hpp"

int CharacterStateExit::_exitFrameNumber = 60;

void CharacterStateExit::enter(Character *character){
    character->exitCounter = 0;
}

void CharacterStateExit::execute(Character *character, float dt){
    character->exitCounter += 1;
    if (character->exitCounter >= _exitFrameNumber / 2){
        character->avatar->setVisible(false);
    }
    if (character->exitCounter >= _exitFrameNumber){
        character->removeMeFromWorld();
    }
}

void CharacterStateExit::exit(Character *character){
    
}
