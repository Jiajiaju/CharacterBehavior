//
//  CharacterStateDead.hpp
//  CharacterBehavior
//
//  Created by weilove-jiajiaju on 2017/8/30.
//
//

#ifndef CharacterStateDead_hpp
#define CharacterStateDead_hpp

#include <stdio.h>
#include "Singleton.hpp"
#include "EntityState.hpp"
#include "Character.hpp"

class CharacterStateDead: public EntityState<Character>, public Singleton<CharacterStateDead>{
private:
public:
    virtual void enter(Character* character);
    virtual void execute(Character* character, float dt);
    virtual void exit(Character* character);
};

#endif /* CharacterStateDead_hpp */
