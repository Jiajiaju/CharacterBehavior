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

#ifdef FSM

class Character: public BaseEntity{
private:
    Character(int id, const CharacterConfig& config);
    ~Character();
    
    BattleTile _targetTile;
    Vector2D _targetVector2D;
    
    int _hp = 0;
    
    bool _isDead = false;
    bool _isExit = false;
public:
    
    CharacterConfig characterConfig;
    
    static Character* createCharacter(int id, const CharacterConfig& config);
    static Character* createCharacter(int id, const std::string& typeName);
    virtual void destory();
    
    StateMachine<Character>* stateMachine = nullptr;
    
    virtual void update(float dt);
    
    void setPosition(float x, float y);
    void setPosition(const BattleTile& battleTile);
    void setPosition(const Vector2D& vector2D);
    Vector2D getPosition(){ return Vector2D(this->avatarNode->getPositionX(), this->avatarNode->getPositionY()); }
    void addTo(cocos2d::Node* parent){ parent->addChild(this->avatarNode); }
    void addTo(cocos2d::Node* parent, int zOrder){ parent->addChild(this->avatarNode, zOrder); }
    
//    std::vector<BattleTile> currentPath;
//    BattleTile lastTile;
    
    int animationFrameCounter = 0;
    int animationSpeed = 5;
    int animationSpeedCounter = 0;
    int exitCounter = 0;
    
    BattleTile currentTile;
    Character* attackTarget;
    void setTargetTile(const BattleTile& tile);
    BattleTile& getTargetTile(){ return _targetTile; }
    Vector2D& getTargetVector2D(){ return _targetVector2D; }
    
    bool isDead(){ return _isDead; }
    bool isExit(){ return _isExit; }
    void dead(){ _isDead = true; }
    void exit(){ _isExit = true; }
    void removeMeFromWorld();
};

#endif

#endif /* Character_hpp */
