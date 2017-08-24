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

Character::Character(int id, const CharacterConfig& config): BaseEntity(id), characterConfig(config){
    avatar = CharacterAvatar::createCharacterAvatar(characterConfig);
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
    this->avatar->destory();
    delete stateMachine;
    delete this;
}

void Character::setPosition(const BattleTile &battleTile){
    cocos2d::Vec2 position = BattleGridHelper::getPositionByBattleTile(battleTile);
    this->avatar->setPosition(position);
    this->avatar->setLocalZOrder(BattleGridHelper::getGroundZOrderByBattleTile(battleTile));
}

void Character::setPosition(const cocos2d::Vec2 &position){
    this->avatar->setPosition(position);
    this->avatar->setLocalZOrder(BattleGridHelper::getGronudZOrderByPosition(position));
}

void Character::setPosition(float x, float y){
    this->avatar->setPosition(x, y);
    this->avatar->setLocalZOrder(BattleGridHelper::getGronudZOrderByPosition(this->avatar->getPosition()));
}

void Character::update(float dt){
    stateMachine->update(dt);
}
