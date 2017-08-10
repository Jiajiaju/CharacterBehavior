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
BattleGridHelper* GameManager::battleGridHelper = nullptr;

void GameManager::init(){
    
    srand((unsigned)time(NULL));
    
    this->battleMananger = BattleMananger::getInstance();
    this->entityManager  = EntityManager::getInstance();
    this->battleGridHelper = BattleGridHelper::getInstance();
    
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
}
