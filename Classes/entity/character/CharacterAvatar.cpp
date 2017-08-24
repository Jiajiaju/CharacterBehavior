//
//  CharacterAvatar.cpp
//  CharacterBehavior
//
//  Created by weilove-jiajiaju on 2017/8/8.
//
//

#include "CharacterAvatar.hpp"

#include "GameManager.hpp"

USING_NS_CC;

CharacterAvatar* CharacterAvatar::createCharacterAvatar(const CharacterConfig &config){
    CharacterAvatar* newCharacterAvatar = new (std::nothrow) CharacterAvatar(config);
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
    
    CCLOG("%s", GameManagerInstance->characterHelper->getCharacterNormalFrameName(characterConfig).c_str());
    
    _avatar = Sprite::createWithSpriteFrameName(GameManagerInstance->characterHelper->getCharacterNormalFrameName(characterConfig));
    _avatar->setAnchorPoint(Vec2(0.5, 0.15));
    this->addChild(_avatar);
    
    return true;
}
