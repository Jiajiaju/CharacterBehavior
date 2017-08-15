//
//  CharacterStateFindTarget.hpp
//  CharacterBehavior
//
//  Created by weilove-jiajiaju on 2017/8/14.
//
//

#ifndef CharacterStateFindTarget_hpp
#define CharacterStateFindTarget_hpp

#include <stdio.h>
#include "Singleton.hpp"
#include "EntityState.hpp"
#include "Character.hpp"

class CharacterStateFindTarget: public EntityState<Character>, public Singleton<CharacterStateFindTarget>{
private:
public:
    virtual void enter(Character* character);
    virtual void execute(Character* character, float dt);
    virtual void exit(Character* character);
};

#endif /* CharacterStateFindTarget_hpp */
