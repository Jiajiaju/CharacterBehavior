//
//  CharacterStateIdle.cpp
//  CharacterBehavior
//
//  Created by weilove-jiajiaju on 2017/8/10.
//
//

#include "CharacterStateIdle.hpp"
#include "mathtool.hpp"

#include "CharacterStateWalk.hpp"

void CharacterStateIdle::enter(Character *character){
    _timeCounter = 0;
    _turnInterval = randomFloatRange(5, 10);
}

void CharacterStateIdle::execute(Character *character, float dt){
    _timeCounter += dt;
    if (character->getTargetTile().row != -1 && character->getTargetTile().column != -1 &&
        character->getTargetTile() != character->currentTile){
        character->stateMachine->setCurrentState(CharacterStateWalk::getInstance());
        return;
    }
    if (_timeCounter > _turnInterval){
        _timeCounter = _timeCounter - _turnInterval;
        _turnInterval = randomFloatRange(5, 10);
        character->turn();
    }
}

void CharacterStateIdle::exit(Character *character){
    _timeCounter = 0;
    _turnInterval = 0;
}
