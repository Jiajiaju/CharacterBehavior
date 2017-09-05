//
//  CharacterHelper.hpp
//  CharacterBehavior
//
//  Created by weilove-jiajiaju on 2017/8/24.
//
//

#ifndef CharacterHelper_hpp
#define CharacterHelper_hpp

#include <stdio.h>
#include "cocos2d.h"
#include "Singleton.hpp"
#include "utility.hpp"

#include "CharacterConfig.hpp"

class Character;

class CharacterHelper: public Singleton<CharacterHelper>{
private:
public:
    static std::string getCharacterNormalFrameName(const CharacterConfig& characterConfig);
    static std::string getCharacterNormalFrameName(const std::string& characterTypeName);
    static std::string getCharacterFrameName(const CharacterConfig& characterConfig, int frameNumber);
    static std::string getCharacterFrameName(const std::string& characterTypeName, int frameNumber);
    
    static int getCharacterAttack(Character* attackCharacter, Character* defenceCharacter);
};

#endif /* CharacterHelper_hpp */
