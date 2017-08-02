//
//  GameManager.cpp
//  CharacterBehavior
//
//  Created by weilove-jiajiaju on 2017/7/27.
//
//

#include "GameManager.hpp"

#include "BattleScene.hpp"

BattleMananger* GameManager::battleMananger = nullptr;

void GameManager::init(){
    this->battleMananger = BattleMananger::getInstance();
}

void GameManager::startGame(){
    this->battleMananger->enterBattle();
}
