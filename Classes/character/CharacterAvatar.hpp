//
//  CharacterAvatar.hpp
//  CharacterBehavior
//
//  Created by weilove-jiajiaju on 2017/8/6.
//
//

#ifndef CharacterAvatar_hpp
#define CharacterAvatar_hpp

#include <stdio.h>
#include "cocos2d.h"

class CharacterAvatar: public cocos2d::Node{
private:
    CharacterAvatar(){};
    ~CharacterAvatar();
    
    cocos2d::Sprite* _avatar;
public:
    static CharacterAvatar* createCharacterAvatar();
    void destory();
    
    virtual bool init();
};

#endif /* CharacterAvatar_hpp */
