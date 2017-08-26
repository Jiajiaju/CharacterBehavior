//
//  Building.cpp
//  CharacterBehavior
//
//  Created by weilove-jiajiaju on 2017/8/15.
//
//

#include "Building.hpp"

#include "GameManager.hpp"

Building::Building(int id, const BuildingConfig& config): BaseEntity(id), buildingConfig(config){
    
    stateMachine = new (std::nothrow) StateMachine<Building>(this);
    
    assert(avatar);
    assert(stateMachine);
    
    GameManagerInstance->entityManager->registerBuilding(this, _id);
}

Building::~Building(){
    
}

Building* Building::createBuilding(int id, const BuildingConfig& config){
    Building* building = new (std::nothrow) Building(id, config);
    if (building){
        return building;
    }
    
    delete building;
    building = nullptr;
    return nullptr;
}
Building* Building::createBuilding(int id, const std::string& buildingTypeName){
    Building* building = new (std::nothrow) Building(id, GameManagerInstance->configManager->getBuildingConfig(buildingTypeName));
    if (building){
        return building;
    }
    
    delete building;
    building = nullptr;
    return nullptr;
}

void Building::destory(){
//    this->avatar->destory();
    delete stateMachine;
    delete this;
}

void Building::update(float dt){
    stateMachine->update(dt);
}

void Building::setPosition(const cocos2d::Vec2 &position){
    this->avatarNode->setPosition(position);
}

void Building::setPosition(float x, float y){
    this->avatarNode->setPosition(x, y);
}


