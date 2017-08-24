//
//  GameManager.cpp
//  CharacterBehavior
//
//  Created by weilove-jiajiaju on 2017/7/27.
//
//

#include "GameManager.hpp"
#include "mathtool.hpp"

BattleMananger* GameManager::battleMananger = nullptr;
EntityManager* GameManager::entityManager = nullptr;
ConfigManager* GameManager::configManager = nullptr;
ResourceManager* GameManager::resourceManager = nullptr;
BattleGridHelper* GameManager::battleGridHelper = nullptr;
CharacterHelper* GameManager::characterHelper = nullptr;
BuildingHelper* GameManager::buildingHelper = nullptr;

void GameManager::init(){
    
    srand((unsigned)time(NULL));
    
    this->battleMananger = BattleMananger::getInstance();
    this->entityManager  = EntityManager::getInstance();
    this->configManager  = ConfigManager::getInstance();
    this->resourceManager = ResourceManager::getInstance();
    this->battleGridHelper = BattleGridHelper::getInstance();
    this->characterHelper = CharacterHelper::getInstance();
    this->buildingHelper = BuildingHelper::getInstance();
    
    this->configManager->init();
    
    cocos2d::Director::getInstance()->getScheduler()->schedule(std::bind(&GameManager::update, this, std::placeholders::_1), cocos2d::Director::getInstance(), 0, false, "main_update");
    
}

void GameManager::startGame(){
    this->battleMananger->enterBattle();
}

void GameManager::update(float dt){
    auto characters = this->entityManager->getCharacters();
    for (auto iter = characters.begin(); iter != characters.end(); ++iter){
        iter->second->update(dt);
    }
    
    auto buildings = this->entityManager->getBuildings();
    for (auto iter = buildings.begin(); iter != buildings.end(); ++iter){
        iter->second->update(dt);
    }
}
