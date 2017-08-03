//
//  BattleManager.cpp
//  CharacterBehavior
//
//  Created by weilove-jiajiaju on 2017/8/2.
//
//

#include "BattleManager.hpp"

void BattleMananger::enterBattle(){
    _battleScene = BattleScene::createScene();
    cocos2d::Director::getInstance()->runWithScene(_battleScene);
    
    
    _battleMapDrawNode = cocos2d::DrawNode::create();
    _battleMapDrawNode->setLineWidth(1);
    _battleMapDrawNode->setColor(cocos2d::Color3B(0, 0, 0));
    _battleScene->map->addChild(_battleMapDrawNode);
    
//    _showMapGrid();
}

void BattleMananger::_showMapGrid(){
    cocos2d::Size visibleSize = cocos2d::Director::getInstance()->getVisibleSize();
    for (int i = 0; i < MapConfig::tileColumn; ++i){
        _battleMapDrawNode->drawLine(cocos2d::Vec2(MapConfig::tileWidth * i, 0), cocos2d::Vec2(MapConfig::tileWidth * i, visibleSize.height), cocos2d::Color4F(0, 0, 0, 1));
    }
    
    for (int i = 0; i < MapConfig::tileRow; ++i){
        _battleMapDrawNode->drawLine(cocos2d::Vec2(0, i * MapConfig::tileWidth), cocos2d::Vec2(visibleSize.width, i * MapConfig::tileWidth), cocos2d::Color4F(0, 0, 0, 1));
    }
}
