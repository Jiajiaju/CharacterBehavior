//
//  EntityState.hpp
//  CharacterBehavior
//
//  Created by weilove-jiajiaju on 2017/8/9.
//
//

#ifndef EntityState_hpp
#define EntityState_hpp

#include <stdio.h>
#include "Singleton.hpp"

template <typename Entity>
class EntityState{
private:
    
public:
    virtual void enter(Entity* entity) = 0;
    virtual void execute(Entity* entity, float dt) = 0;
    virtual void exit(Entity* entity) = 0;
};

#endif /* EntityState_hpp */
