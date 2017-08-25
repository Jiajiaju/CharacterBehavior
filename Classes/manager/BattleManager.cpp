//
//  BattleManager.cpp
//  CharacterBehavior
//
//  Created by weilove-jiajiaju on 2017/8/2.
//
//

#include "BattleManager.hpp"
#include "GameManager.hpp"

void BattleMananger::enterBattle(){
    
    GameManagerInstance->resourceManager->loadAllCharacterFrameSheets();
    GameManagerInstance->resourceManager->loadAllBuildingFrameSheets();
    
    _battleScene = BattleScene::createScene();
    cocos2d::Director::getInstance()->runWithScene(_battleScene);
    
    _battleTouchListener = cocos2d::EventListenerTouchOneByOne::create();
    _battleTouchListener->onTouchBegan = std::bind(&BattleMananger::_onTouchBegan, this, std::placeholders::_1, std::placeholders::_2);
    _battleTouchListener->onTouchMoved = std::bind(&BattleMananger::_onTouchMoved, this, std::placeholders::_1, std::placeholders::_2);
    _battleTouchListener->onTouchEnded = std::bind(&BattleMananger::_onTouchEnded, this, std::placeholders::_1, std::placeholders::_2);
    cocos2d::Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(_battleTouchListener, _battleScene);
    
    _battleMapDrawNode = cocos2d::DrawNode::create();
    _battleMapDrawNode->setLineWidth(1);
    _battleMapDrawNode->setColor(cocos2d::Color3B(0, 0, 0));
    _battleScene->map->addChild(_battleMapDrawNode);
    
    _showMapGrid();
    _addCharater();
    _addBuilding();
}

void BattleMananger::_showMapGrid(){
    cocos2d::Size visibleSize = cocos2d::Director::getInstance()->getVisibleSize();
    for (int i = 0; i < MapConfig::tileColumn; ++i){
        _battleMapDrawNode->drawLine(cocos2d::Vec2(MapConfig::tileWidth * i, 0), cocos2d::Vec2(MapConfig::tileWidth * i, visibleSize.height), cocos2d::Color4F(0, 0, 0, 1));
    }
    
    for (int i = 0; i < MapConfig::tileRow; ++i){
        _battleMapDrawNode->drawLine(cocos2d::Vec2(0, i * MapConfig::tileWidth), cocos2d::Vec2(MapConfig::tileColumn * MapConfig::tileWidth, i * MapConfig::tileWidth), cocos2d::Color4F(0, 0, 0, 1));
    }
}

void BattleMananger::_addCharater(){
    cocos2d::Size visible = cocos2d::Director::getInstance()->getVisibleSize();
    Character* newCharacter = Character::createCharacter(GameManagerInstance->entityManager->getCharacterID(), "soldier_2");
    newCharacter->setPosition(BattleTile(1, 1));
//    newCharacter->setPosition(visible.width / 2, visible.height / 2);
    _battleScene->groundLayer->addChild(newCharacter->avatar);
    
    GameManagerInstance->scheduleOnce([newCharacter](){
        CCLOG("Hello!");
        newCharacter->targetTile = BattleTile(MapConfig::mapWidth - 1, MapConfig::mapHeight / 2);
    }, 3);
    
//    Character* newCharacter1 = Character::createCharacter(GameManagerInstance->entityManager->getCharacterID(), "enemy_2");
//    newCharacter1->setPosition(BattleTile(28, 10));
//    //    newCharacter->setPosition(visible.width / 2, visible.height / 2);
//    _battleScene->groundLayer->addChild(newCharacter1->avatar);
//    
//    Character* newCharacter2 = Character::createCharacter(GameManagerInstance->entityManager->getCharacterID(), "enemy_3");
//    newCharacter2->setPosition(BattleTile(35, 10));
//    //    newCharacter->setPosition(visible.width / 2, visible.height / 2);
//    _battleScene->groundLayer->addChild(newCharacter2->avatar);
}

void BattleMananger::_addBuilding(){
//    cocos2d::Size visible = cocos2d::Director::getInstance()->getVisibleSize();
//    Building* newBuilding = Building::createBuilding(GameManagerInstance->entityManager->getBuildingID(), "building_1");
//    newBuilding->setPosition(visible.width / 2, visible.height / 2);
//    _battleScene->groundLayer->addChild(newBuilding->avatar);
//    
//    Building* newBuilding1 = Building::createBuilding(GameManagerInstance->entityManager->getBuildingID(), "building_2");
//    newBuilding1->setPosition(visible.width, visible.height / 2);
//    _battleScene->groundLayer->addChild(newBuilding1->avatar);
    
}

bool BattleMananger::_onTouchBegan(cocos2d::Touch *touch, cocos2d::Event *event){
    return true;
}

void BattleMananger::_onTouchMoved(cocos2d::Touch *touch, cocos2d::Event *event){
    cocos2d::Vec2 delta = touch->getDelta();
    if (delta.x < 10 && delta.x > -10){
        return;
    }
    
    cocos2d::Vec2 mapCurrentPosition = _battleScene->map->getPosition();
    cocos2d::Size mapSize = _battleScene->map->getContentSize();
    cocos2d::Size visibleSize = cocos2d::Director::getInstance()->getVisibleSize();
    
    cocos2d::Vec2 mapNewPosition(mapCurrentPosition.x + delta.x, mapCurrentPosition.y);
    
    if (mapNewPosition.x < visibleSize.width - mapSize.width){
        mapNewPosition.x = visibleSize.width - mapSize.width;
    }
    if (mapNewPosition.x > 0){
        mapNewPosition.x = 0.0;
    }
    
    _battleScene->map->setPosition(mapNewPosition);
}

void BattleMananger::_onTouchEnded(cocos2d::Touch *touch, cocos2d::Event *event){
    
}
