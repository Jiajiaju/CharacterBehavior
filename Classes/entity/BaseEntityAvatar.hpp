//
//  BaseEntityAvatar.hpp
//  CharacterBehavior
//
//  Created by weilove-jiajiaju on 2017/8/8.
//
//

#ifndef BaseEntityAvatar_hpp
#define BaseEntityAvatar_hpp

#include <stdio.h>
#include "cocos2d.h"

class BaseEntityAvatar: public cocos2d::Node{
private:
protected:
    BaseEntityAvatar();
    ~BaseEntityAvatar() = 0;
    cocos2d::Sprite* _avatar;
public:
    
    virtual void destory();
    
    virtual bool init();
};

#endif /* BaseEntityAvatar_hpp */
