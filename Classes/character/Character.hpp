//
//  Character.hpp
//  CharacterBehavior
//
//  Created by weilove-jiajiaju on 2017/8/5.
//
//

#ifndef Character_hpp
#define Character_hpp

#include <stdio.h>
#include "cocos2d.h"

#include "import.hpp"

#include "CharacterAvatar.hpp"

class Character{
private:
    Character();
    ~Character();
public:
    
    static Character* createCharacter();
    void destory();
    
    CharacterAvatar* avatar = nullptr;
    
    void setPosition(const cocos2d::Vec2& position){ avatar->setPosition(position); }
    void setPosition(float x, float y){ avatar->setPosition(x, y); }
    cocos2d::Vec2 getPosition(){ return avatar->getPosition(); }
    
};

#endif /* Character_hpp */
