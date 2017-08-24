//
//  BuildingAvatar.cpp
//  CharacterBehavior
//
//  Created by weilove-jiajiaju on 2017/8/15.
//
//

#include "BuildingAvatar.hpp"

#include "GameManager.hpp"


BuildingAvatar* BuildingAvatar::createBuildingAvatar(const BuildingConfig& config){
    BuildingAvatar* buildingAvatar = new (std::nothrow) BuildingAvatar(config);
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
    
    _avatar = cocos2d::Sprite::createWithSpriteFrameName(GameManagerInstance->buildingHelper->getBuildingNormalFrameName(buildingConfig));
    _avatar->setAnchorPoint(cocos2d::Vec2(0.5, 0));
    this->addChild(_avatar);
    
    return true;
}
