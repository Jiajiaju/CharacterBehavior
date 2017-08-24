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
#include "CharacterConfig.hpp"
#include "utility.hpp"

class CharacterAvatar: public BaseEntityAvatar{
private:
    CharacterAvatar(const CharacterConfig& config):characterConfig(config){}
    ~CharacterAvatar(){}
public:
    
    CharacterConfig characterConfig;
    
    static CharacterAvatar* createCharacterAvatar(const CharacterConfig& config);
    virtual bool init();
};

#endif /* CharacterAvatar_hpp */
