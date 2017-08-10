//
//  CharacterStateWalk.hpp
//  CharacterBehavior
//
//  Created by weilove-jiajiaju on 2017/8/9.
//
//

#ifndef CharacterStateWalk_hpp
#define CharacterStateWalk_hpp

#include <stdio.h>
#include "cocos2d.h"
#include "Singleton.hpp"
#include "EntityState.hpp"
#include "Character.hpp"

class CharacterStateWalk: public EntityState<Character>, public Singleton<CharacterStateWalk>{
private:
public:
    virtual void enter(Character* character);
    virtual void execute(Character* character, float dt);
    virtual void exit(Character* character);
};

#endif /* CharacterStateWalk_hpp */
