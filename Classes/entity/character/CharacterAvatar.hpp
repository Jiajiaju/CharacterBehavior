//
//  CharacterAvatar.hpp
//  CharacterBehavior
//
//  Created by weilove-jiajiaju on 2017/8/8.
//
//

#ifndef CharacterAvatar_hpp
#define CharacterAvatar_hpp

#include <stdio.h>
#include "BaseEntityAvatar.hpp"

class CharacterAvatar: public BaseEntityAvatar{
private:
    CharacterAvatar(){}
    ~CharacterAvatar(){}
public:
    
    static CharacterAvatar* createCharacterAvatar();
    virtual bool init();
};

#endif /* CharacterAvatar_hpp */
