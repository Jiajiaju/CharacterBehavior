//
//  GameManager.cpp
//  CharacterBehavior
//
//  Created by weilove-jiajiaju on 2017/7/27.
//
//

#include "GameManager.hpp"

BattleMananger* GameManager::battleMananger = nullptr;
EntityManager* GameManager::entityManager = nullptr;
BattleGridHelper* GameManager::battleGridHelper = nullptr;

void GameManager::init(){
    this->battleMananger = BattleMananger::getInstance();
    this->entityManager  = EntityManager::getInstance();
    this->battleGridHelper = BattleGridHelper::getInstance();
}

void GameManager::startGame(){
    this->battleMananger->enterBattle();
}
