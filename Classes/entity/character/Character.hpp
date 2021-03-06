//
//  Character.hpp
//  CharacterBehavior
//
//  Created by weilove-jiajiaju on 2017/8/8.
//
//

#ifndef Character_hpp
#define Character_hpp

#include <stdio.h>
#include "cocos2d.h"

#include "import.hpp"
#include "setting.hpp"
#include "Vector2D.hpp"

#include "BaseEntity.hpp"

#include "StateMachine.hpp"

#include "BattleTile.hpp"

#include "AllModel.hpp"

#include "EntityHPBar.hpp"

enum class CharacterFaction{
    Blue,
    Red
};

#ifdef FSM

class Character: public BaseEntity{
private:
    Character(int id, const CharacterConfig& config, CharacterFaction faction);
    ~Character();
    
    BattleTile _targetTile;
    Vector2D _targetVector2D;
    
    int _hp = 0;
    EntityHPBar* _hpBar = nullptr;
    
    bool _isDead = true;
    bool _isExit = true;
public:
    
    CharacterConfig characterConfig;
    CharacterFaction characterFaction = CharacterFaction::Blue;
    
    static Character* createCharacter(int id, const CharacterConfig& config, CharacterFaction faction);
    static Character* createCharacter(int id, const std::string& typeName, CharacterFaction faction);
    virtual void destory();
    
    StateMachine<Character>* stateMachine = nullptr;
    
    virtual void update(float dt);
    
    void setPosition(float x, float y);
    void setPosition(const BattleTile& battleTile);
    void setPosition(const Vector2D& vector2D);
    Vector2D getPosition(){ return Vector2D(this->avatarNode->getPositionX(), this->avatarNode->getPositionY()); }
    BattleTile getFaceToTile();
    Vector2D getAttackPoint();
    void addTo(cocos2d::Node* parent){ parent->addChild(this->avatarNode); }
    void addTo(cocos2d::Node* parent, int zOrder){ parent->addChild(this->avatarNode, zOrder); }
    
//    std::vector<BattleTile> currentPath;
//    BattleTile lastTile;
    
    int animationFrameCounter = 0;
    int animationSpeedCounter = 0;
    int attackIntervalCounter = 0;
    int exitCounter = 0;
    
    BattleTile currentTile;
    Character* attackTarget = nullptr;
    void setTargetTile(const BattleTile& tile);
    BattleTile& getTargetTile(){ return _targetTile; }
    Vector2D& getTargetVector2D(){ return _targetVector2D; }
    
    bool isDead(){ return _isDead; }
    bool isExit(){ return _isExit; }
    void dead(){ _isDead = true; }
    void exit(){ _isExit = true; }
    void removeMeFromWorld();
    
    int getHP(){ return _hp; }
    void loseBlood(int loseValue);
};

#endif

#endif /* Character_hpp */
