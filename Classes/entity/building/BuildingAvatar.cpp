//
//  BuildingAvatar.cpp
//  CharacterBehavior
//
//  Created by weilove-jiajiaju on 2017/8/15.
//
//

#include "BuildingAvatar.hpp"


BuildingAvatar* BuildingAvatar::createBuildingAvatar(){
    BuildingAvatar* buildingAvatar = new (std::nothrow) BuildingAvatar();
    if (buildingAvatar && buildingAvatar->init()){
        buildingAvatar->retain();
        return buildingAvatar;
    }
    
    delete buildingAvatar;
    buildingAvatar = nullptr;
    return nullptr;
}

bool BuildingAvatar::init(){
    if (!BaseEntityAvatar::init()){
        return false;
    }
    
    _avatar = cocos2d::Sprite::createWithSpriteFrameName("building_1.png");
    _avatar->setAnchorPoint(cocos2d::Vec2(0.5, 0));
    this->addChild(_avatar);
    
    return true;
}
