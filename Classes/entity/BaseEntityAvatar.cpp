//
//  BaseEntityAvatar.cpp
//  CharacterBehavior
//
//  Created by weilove-jiajiaju on 2017/8/8.
//
//

#include "BaseEntityAvatar.hpp"

BaseEntityAvatar::BaseEntityAvatar(){
    
}

BaseEntityAvatar::~BaseEntityAvatar(){
}

void BaseEntityAvatar::destory(){
    this->release();
}

bool BaseEntityAvatar::init(){
    if (!cocos2d::Node::init()){
        return false;
    }
    
    _faceDirection = "left";
    
    return true;
}

void BaseEntityAvatar::turn(){
    if (_faceDirection == "left"){
        _faceDirection = "right";
        _avatar->setFlippedX(true);
    }else {
        _faceDirection = "left";
        _avatar->setFlippedX(false);
    }
}

void BaseEntityAvatar::turn(const std::string &direction){
    if (_faceDirection == direction){
        return;
    }
    this->turn();
}
