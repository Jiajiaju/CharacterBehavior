//
//  EntityManager.cpp
//  CharacterBehavior
//
//  Created by weilove-jiajiaju on 2017/8/8.
//
//

#include "EntityManager.hpp"

int EntityManager::_characterIDCounter = 0;

int EntityManager::getCharacterID(){
    return ++_characterIDCounter;
}
