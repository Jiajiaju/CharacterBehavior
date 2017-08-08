//
//  EntityManager.hpp
//  CharacterBehavior
//
//  Created by weilove-jiajiaju on 2017/8/8.
//
//

#ifndef EntityManager_hpp
#define EntityManager_hpp

#include <stdio.h>
#include "Singleton.hpp"

class EntityManager: public Singleton<EntityManager>{
private:
    static int _characterIDCounter;
public:
    
    int getCharacterID();
};

#endif /* EntityManager_hpp */
