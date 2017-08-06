//
//  CharacterAvatar.cpp
//  CharacterBehavior
//
//  Created by weilove-jiajiaju on 2017/8/6.
//
//

#include "CharacterAvatar.hpp"

USING_NS_CC;

CharacterAvatar::~CharacterAvatar(){
    this->release();
}

CharacterAvatar* CharacterAvatar::createCharacterAvatar(){
    CharacterAvatar* newCharacterAvatar = new (std::nothrow) CharacterAvatar();
    if (newCharacterAvatar && newCharacterAvatar->init()){
        newCharacterAvatar->retain();
        return newCharacterAvatar;
    }
    
    delete newCharacterAvatar;
    newCharacterAvatar = nullptr;
    return nullptr;
}

bool CharacterAvatar::init(){
    if (!Node::init()){
        return false;
    }
    
    _avatar = Sprite::createWithSpriteFrameName("soldier_1.png");
    _avatar->setAnchorPoint(Vec2(0.5, 0));
    this->addChild(_avatar);
    
    
    return true;
}
