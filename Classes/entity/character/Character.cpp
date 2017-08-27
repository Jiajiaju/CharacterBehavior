//
//  Character.cpp
//  CharacterBehavior
//
//  Created by weilove-jiajiaju on 2017/8/8.
//
//

#include "Character.hpp"

#include "GameManager.hpp"

#include "CharacterStateIdle.hpp"

USING_NS_CC;

Character::Character(int id, const CharacterConfig& config): BaseEntity(id), characterConfig(config){
    
    this->animationFrameCounter = characterConfig.animation_walk[0];
    this->avatar->setSpriteFrame(GameManagerInstance->characterHelper->getCharacterNormalFrameName(characterConfig));
    
    stateMachine = new (std::nothrow) StateMachine<Character>(this);
    
    assert(avatar);
    assert(stateMachine);
    
    stateMachine->setCurrentState(CharacterStateIdle::getInstance());
    
    GameManagerInstance->entityManager->registerCharacter(this, _id);
}

Character::~Character(){
}

Character* Character::createCharacter(int id, const CharacterConfig &config){
    Character* newCharacter = new (std::nothrow) Character(id, config);
    if (newCharacter){
        return newCharacter;
    }
    
    delete newCharacter;
    newCharacter = nullptr;
    return nullptr;
}

Character* Character::createCharacter(int id, const std::string &typeName){
    Character* newCharacter = new (std::nothrow) Character(id, GameManagerInstance->configManager->getCharacterConfig(typeName));
    if (newCharacter){
        return newCharacter;
    }
    
    delete newCharacter;
    newCharacter = nullptr;
    return nullptr;
}

void Character::destory(){
    delete stateMachine;
    delete this;
}

void Character::setPosition(const BattleTile &battleTile){
    cocos2d::Vec2 position = BattleGridHelper::getPositionByBattleTile(battleTile);
    this->avatarNode->setPosition(position);
    this->avatarNode->setLocalZOrder(BattleGridHelper::getGroundZOrderByBattleTile(battleTile));
    this->currentTile = battleTile;
}

void Character::setPosition(const cocos2d::Vec2 &position){
    this->avatarNode->setPosition(position);
    this->avatarNode->setLocalZOrder(BattleGridHelper::getGronudZOrderByPosition(position));
    this->currentTile = BattleGridHelper::getBattleTileByPosition(position);
}

void Character::setPosition(float x, float y){
    this->avatarNode->setPosition(x, y);
    this->avatarNode->setLocalZOrder(BattleGridHelper::getGronudZOrderByPosition(this->avatar->getPosition()));
    this->currentTile = BattleGridHelper::getBattleTileByPosition(cocos2d::Vec2(x, y));
}

void Character::setTargetTile(const BattleTile &tile){
    _targetTile = tile;
    _targetVector2D = GameManagerInstance->battleGridHelper->getVector2DByBattleTile(_targetTile);
}

void Character::update(float dt){
    stateMachine->update(dt);
}
