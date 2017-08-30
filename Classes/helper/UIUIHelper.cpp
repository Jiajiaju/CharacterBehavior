//
//  UIUIHelper.cpp
//  CharacterBehavior
//
//  Created by weilove-jiajiaju on 2017/8/30.
//
//

#include "UIUIHelper.hpp"

cocos2d::Label* UIUIHelper::getLabel(const std::string &context, int frontSize, cocos2d::Node *parent, float x, float y, int zOrder){
    cocos2d::Label* label = cocos2d::Label::createWithSystemFont(context, "Arial", frontSize);
    label->setColor(cocos2d::Color3B(255, 255, 255));
    label->setPosition(x, y);
    parent->addChild(label, zOrder);
    return label;
}

cocos2d::Label* UIUIHelper::getLabel(const std::string &context, int frontSize, const cocos2d::Color3B &color, cocos2d::Node *parent, float x, float y, int zOrder){
    cocos2d::Label* label = cocos2d::Label::createWithSystemFont(context, "Arial", frontSize);
    label->setColor(color);
    label->setPosition(x, y);
    parent->addChild(label, zOrder);
    return label;
}
