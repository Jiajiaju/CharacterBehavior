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

void EntityManager::registerCharacter(Character *character, int id){
    assert(_characters.find(id) == _characters.end());
    _characters[id] = character;
}

void EntityManager::unregisterCharacter(Character *character, int id){
    if (_characters.find(id) == _characters.end()){
        return;
    }
    assert(_characters[id] == character);
    _characters.erase(id);
}

void EntityManager::unregisterCharacter(Character *character){
    for (auto iter = _characters.begin(); iter != _characters.end(); ++iter){
        if (iter->second == character){
            _characters.erase(iter);
            break;
        }
    }
}

void EntityManager::unregisterCharacter(int id){
    if (_characters.find(id) == _characters.end()){
        return;
    }
    _characters.erase(id);
}
