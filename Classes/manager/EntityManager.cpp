//
//  EntityManager.cpp
//  CharacterBehavior
//
//  Created by weilove-jiajiaju on 2017/8/8.
//
//

#include "EntityManager.hpp"

int EntityManager::_characterIDCounter = 1000;
int EntityManager::_buildingIDCounter  = 3000;

float EntityManager::getEntityDistanceSquare(BaseEntity *lhs, BaseEntity *rhs){
    return getDistanceSquare(lhs->avatarNode->getPosition(), rhs->avatarNode->getPosition());
}

float EntityManager::getEntityDistance(BaseEntity *lhs, BaseEntity *rhs){
    return getDistance(lhs->avatarNode->getPosition(), rhs->avatarNode->getPosition());
}

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

int EntityManager::getBuildingID(){
    return ++_buildingIDCounter;
}

void EntityManager::registerBuilding(Building *building, int id){
    assert(_buildings.find(id) == _buildings.end());
    _buildings[id] = building;
}

void EntityManager::unregisterBuilding(Building *building, int id){
    assert(_buildings.find(id)->second == building);
    _buildings.erase(id);
}

void EntityManager::unregisterBuilding(Building *building){
    for (auto iter = _buildings.begin(); iter != _buildings.end(); ++iter){
        if (iter->second == building){
            _buildings.erase(iter);
            break;
        }
    }
}

void EntityManager::unregisterBuilding(int id){
    if (_buildings.find(id) == _buildings.end()){
        return;
    }
    _buildings.erase(id);
}
