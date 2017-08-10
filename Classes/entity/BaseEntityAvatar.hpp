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
    std::string _faceDirection = "left";
public:
    
    virtual void destory();
    
    virtual bool init();
    
    void turnLeft() { _faceDirection = "left"; _avatar->setFlippedX(false); }
    void turnRight(){ _faceDirection = "right"; _avatar->setFlippedX(true); }
    void turn();
    void turn(const std::string& direction);
    
};

#endif /* BaseEntityAvatar_hpp */
