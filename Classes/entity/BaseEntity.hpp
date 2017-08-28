//
//  BaseEntity.hpp
//  CharacterBehavior
//
//  Created by weilove-jiajiaju on 2017/8/8.
//
//

#ifndef BaseEntity_hpp
#define BaseEntity_hpp

#include <stdio.h>
#include "cocos2d.h"

class BaseEntity{
private:
protected:
    int _id = -1;
    std::string _faceDirection = "right";
    BaseEntity(int id):_id(id) {
        _faceDirection = "right";
        this->avatarNode = cocos2d::Node::create();
        this->avatarNode->retain();
        
        this->avatar = cocos2d::Sprite::create();
        this->avatar->setAnchorPoint(cocos2d::Vec2(0.5, 0.15));
        this->avatarNode->addChild(this->avatar);
    }
    virtual ~BaseEntity(){
        this->avatarNode->release();
    }
public:
    
    cocos2d::Node* avatarNode = nullptr;
    cocos2d::Sprite* avatar = nullptr;
    
    virtual void destory();
    
    virtual void update(float dt) = 0;
    
    void turnLeft() { _faceDirection = "left"; avatar->setFlippedX(false); }
    void turnRight(){ _faceDirection = "right"; avatar->setFlippedX(true); }
    void turn();
    void turn(const std::string& direction);
};

#endif /* BaseEntity_hpp */
