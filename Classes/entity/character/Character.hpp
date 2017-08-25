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

#include "BaseEntity.hpp"
#include "CharacterAvatar.hpp"

#include "StateMachine.hpp"

#include "BattleTile.hpp"

#include "AllModel.hpp"

#ifdef FSM

class Character: public BaseEntity{
private:
    Character(int id, const CharacterConfig& config);
    ~Character();
public:
    
    CharacterConfig characterConfig;
    
    static Character* createCharacter(int id, const CharacterConfig& config);
    static Character* createCharacter(int id, const std::string& typeName);
    virtual void destory();
    
    StateMachine<Character>* stateMachine = nullptr;
    
    virtual void update(float dt);
    
    void setPosition(const cocos2d::Vec2& position);
    void setPosition(float x, float y);
    void setPosition(const BattleTile& battleTile);
    cocos2d::Vec2 getPosition(){ return avatar->getPosition(); }
    
//    std::vector<BattleTile> currentPath;
//    BattleTile lastTile;
    
    BattleTile currentTile;
    BattleTile targetTile;
    Character* attackTarget;
    
};

#endif

#endif /* Character_hpp */
