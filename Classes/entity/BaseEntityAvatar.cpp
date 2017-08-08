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
    
    return true;
}
