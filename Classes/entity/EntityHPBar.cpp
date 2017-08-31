//
//  EntityHPBar.cpp
//  CharacterBehavior
//
//  Created by weilove-jiajiaju on 2017/8/31.
//
//

#include "EntityHPBar.hpp"

USING_NS_CC;

const std::map<EntityHPBarType, std::vector<std::string>> EntityHPBar::_barTypeConfig = {
    {EntityHPBarType::Big,    {"character_hp_bar_00.png", "character_hp_bar_01.png"}},
    {EntityHPBarType::Middle, {"character_hp_bar_10.png", "character_hp_bar_11.png"}},
    {EntityHPBarType::Small,  {"character_hp_bar_20.png", "character_hp_bar_21.png"}}
};

EntityHPBar* EntityHPBar::createEntityHPBar(EntityHPBarType type){
    EntityHPBar* bar = new (std::nothrow) EntityHPBar(type);
    if (bar && bar->init()){
        bar->autorelease();
        return bar;
    }
    delete bar;
    bar = nullptr;
    return nullptr;
}

bool EntityHPBar::init(){
    if (!Node::init()){
        return false;
    }
    
    assert(_barTypeConfig.find(_type) != _barTypeConfig.end());
    
    _bg = Sprite::createWithSpriteFrameName(_barTypeConfig.find(_type)->second.at(0));
    this->addChild(_bg);
    
    _process = Sprite::createWithSpriteFrameName(_barTypeConfig.find(_type)->second.at(1));
    Size processSize = _process->getContentSize();
    _process->setAnchorPoint(Vec2(0, 0.5));
    _process->setPosition(-processSize.width / 2, 0);
    this->addChild(_process);
    
    return true;
}

void EntityHPBar::updateHPRatio(float ratio){
    if (ratio <= 0){
        ratio = 0;
    }
    _process->setScaleX(ratio);
}
