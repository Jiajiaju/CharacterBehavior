//
//  CharacterFindAttackTarget.hpp
//  CharacterBehavior
//
//  Created by weilove-jiajiaju on 2017/8/30.
//
//

#ifndef CharacterFindAttackTarget_hpp
#define CharacterFindAttackTarget_hpp

#include <stdio.h>
#include "cocos2d.h"
#include "mathtool.hpp"
#include "Singleton.hpp"

#include "Character.hpp"

class CharacterFindAttackTarget: public Singleton<CharacterFindAttackTarget>{
private:
    static Character* _processCharacterCurrentAttackTarget(Character* character);
    
    static Character* _findAttackTargetNearest(Character* character);
public:
    
    static Character* findAttackTarget(Character* character);
};

#endif /* CharacterFindAttackTarget_hpp */
