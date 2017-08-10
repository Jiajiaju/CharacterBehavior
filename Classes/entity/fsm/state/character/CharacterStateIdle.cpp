//
//  CharacterStateIdle.cpp
//  CharacterBehavior
//
//  Created by weilove-jiajiaju on 2017/8/10.
//
//

#include "CharacterStateIdle.hpp"
#include "mathtool.hpp"

void CharacterStateIdle::enter(Character *charater){
    _timeCounter = 0;
}

void CharacterStateIdle::execute(Character *charater, float dt){
    _timeCounter += dt;
}

void CharacterStateIdle::exit(Character *charater){
    
}
