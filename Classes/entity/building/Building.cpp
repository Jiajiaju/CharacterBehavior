//
//  Building.cpp
//  CharacterBehavior
//
//  Created by weilove-jiajiaju on 2017/8/15.
//
//

#include "Building.hpp"

#include "GameManager.hpp"

Building::Building(int id):BaseEntity(id){
    avatar = BuildingAvatar::createBuildingAvatar();
    
    assert(avatar);
    
    GameManagerInstance->entityManager->registerBuilding(this, _id);
}

Building::~Building(){
    
}

Building* Building::createBuilding(int id){
    Building* building = new (std::nothrow) Building(id);
    if (building){
        return building;
    }
    
    delete building;
    building = nullptr;
    return nullptr;
}

void Building::destory(){
    this->avatar->destory();
    delete this;
}

void Building::update(float dt){
    
}

void Building::setPosition(const cocos2d::Vec2 &position){
    avatar->setPosition(position);
}

void Building::setPosition(float x, float y){
    avatar->setPosition(x, y);
}


