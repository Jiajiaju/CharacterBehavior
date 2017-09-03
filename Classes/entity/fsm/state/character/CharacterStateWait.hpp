//
//  CharacterStateWait.hpp
//  CharacterBehavior
//
//  Created by weilove-jiajiaju on 2017/9/3.
//
//

#ifndef CharacterStateWait_hpp
#define CharacterStateWait_hpp

#include <stdio.h>
#include "cocos2d.h"
#include "Singleton.hpp"
#include "EntityState.hpp"
#include "Character.hpp"

class CharacterStateWait: public EntityState<Character>, public Singleton<CharacterStateWait>{
private:
public:
    virtual void enter(Character* character);
    virtual void execute(Character* character, float dt);
    virtual void exit(Character* character);
};

#endif /* CharacterStateWait_hpp */
