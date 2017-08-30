//
//  CharacterStateExit.hpp
//  CharacterBehavior
//
//  Created by weilove-jiajiaju on 2017/8/30.
//
//

#ifndef CharacterStateExit_hpp
#define CharacterStateExit_hpp

#include <stdio.h>
#include "Singleton.hpp"
#include "EntityState.hpp"
#include "Character.hpp"

class CharacterStateExit: public EntityState<Character>, public Singleton<CharacterStateExit>{
private:
    static int _exitFrameNumber;
public:
    virtual void enter(Character* character);
    virtual void execute(Character* character, float dt);
    virtual void exit(Character* character);
};

#endif /* CharacterStateExit_hpp */
