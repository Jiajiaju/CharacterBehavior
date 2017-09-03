//
//  CharacterStateAttack.hpp
//  CharacterBehavior
//
//  Created by weilove-jiajiaju on 2017/9/4.
//
//

#ifndef CharacterStateAttack_hpp
#define CharacterStateAttack_hpp

#include <stdio.h>
#include "cocos2d.h"
#include "Singleton.hpp"
#include "EntityState.hpp"
#include "Character.hpp"

class CharacterStateAttack: public EntityState<Character>, public Singleton<CharacterStateAttack>{
private:
public:
    virtual void enter(Character* character);
    virtual void execute(Character* character, float dt);
    virtual void exit(Character* character);
};

#endif /* CharacterStateAttack_hpp */
