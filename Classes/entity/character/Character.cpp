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

Character::Character(int id, const CharacterConfig& config, CharacterFaction faction): BaseEntity(id), characterConfig(config), characterFaction(faction){
    this->animationFrameCounter = characterConfig.animation_walk[0];
    this->avatar->setSpriteFrame(GameManagerInstance->characterHelper->getCharacterNormalFrameName(characterConfig));
    
    cocos2d::Size avatarSize = this->avatar->getContentSize();
    _hpBar = EntityHPBar::createEntityHPBar(EntityHPBarType::Small);
    _hpBar->setPosition(0, avatarSize.height - 10);
    this->avatarOver->addChild(_hpBar);
    
    stateMachine = new (std::nothrow) StateMachine<Character>(this);
    
    assert(avatar);
    assert(stateMachine);
    
    stateMachine->setCurrentState(CharacterStateIdle::getInstance());
    
    GameManagerInstance->entityManager->registerCharacter(this, _id);
    
    _hp = characterConfig.hp;
    _isDead = false;
    _isExit = false;
    
#ifdef DEBUG
    UIUIHelper::getLabel(intToString(_id), 20, this->avatarOver, 0, avatarSize.height);
#endif
}

Character::~Character(){
}

Character* Character::createCharacter(int id, const CharacterConfig &config, CharacterFaction faction){
    Character* newCharacter = new (std::nothrow) Character(id, config, faction);
    if (newCharacter){
        return newCharacter;
    }
    
    delete newCharacter;
    newCharacter = nullptr;
    return nullptr;
}

Character* Character::createCharacter(int id, const std::string &typeName, CharacterFaction faction){
    Character* newCharacter = new (std::nothrow) Character(id, GameManagerInstance->configManager->getCharacterConfig(typeName), faction);
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
    this->avatarNode->setLocalZOrder(BattleGridHelper::getGroundZOrder(battleTile));
    this->currentTile = battleTile;
}

void Character::setPosition(float x, float y){
    this->avatarNode->setPosition(x, y);
    Vector2D position(x, y);
    this->avatarNode->setLocalZOrder(BattleGridHelper::getGroundZOrder(position));
    this->currentTile = BattleGridHelper::getBattleTileByVector2D(position);
}

void Character::setPosition(const Vector2D &vector2D){
    this->avatarNode->setPosition(vector2D.x, vector2D.y);
    this->avatarNode->setLocalZOrder(BattleGridHelper::getGroundZOrder(vector2D));
    this->currentTile = BattleGridHelper::getBattleTileByVector2D(vector2D);
}

void Character::setTargetTile(const BattleTile &tile){
    _targetTile = tile;
    _targetVector2D = GameManagerInstance->battleGridHelper->getVector2DByBattleTile(_targetTile);
}

void Character::update(float dt){
    if (_hp <= 0 && _isDead == false){
        _isDead = true;
        return;
    }
    stateMachine->update(dt);
}

void Character::removeMeFromWorld(){
    GameManagerInstance->entityManager->unregisterCharacter(this);
    this->destory();
}

void Character::loseBlood(int loseValue){
    if (loseValue > _hp){
        loseValue = _hp;
    }
    _hp -= loseValue;
    _hpBar->updateHPRatio(static_cast<float>(_hp) / static_cast<float>(characterConfig.hp));
    if (_hp <= 0){
        _isDead = true;
    }
}
