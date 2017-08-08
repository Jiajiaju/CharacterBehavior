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

#include "BattleTile.hpp"

#ifdef FSM

class Character: public BaseEntity{
private:
    Character(int id);
    ~Character();
public:
    
    static Character* createCharacter(int id);
    virtual void destory();
    
//    CharacterAvatar* avatar = nullptr;
    
    virtual void update(float dt);
    
    void setPosition(const cocos2d::Vec2& position);
    void setPosition(float x, float y);
    void setPosition(const BattleTile& battleTile);
    cocos2d::Vec2 getPosition(){ return avatar->getPosition(); }
    
};

#endif

#endif /* Character_hpp */
