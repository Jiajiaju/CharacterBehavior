//
//  BaseEntity.cpp
//  CharacterBehavior
//
//  Created by weilove-jiajiaju on 2017/8/8.
//
//

#include "BaseEntity.hpp"

void BaseEntity::destory(){
    delete this;
}

void BaseEntity::turn(){
    if (_faceDirection == "left"){
        _faceDirection = "right";
        this->avatar->setFlippedX(false);
    }else {
        _faceDirection = "left";
        this->avatar->setFlippedX(true);
    }
}

void BaseEntity::turn(const std::string &direction){
    if (_faceDirection == direction){
        return;
    }
    this->turn();
}
