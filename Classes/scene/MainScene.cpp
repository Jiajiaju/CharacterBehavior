//
//  MainScene.cpp
//  CharacterBehavior
//
//  Created by weilove-jiajiaju on 2017/7/26.
//
//

#include "MainScene.hpp"
#include "Array2D.hpp"
#include "import.hpp"

USING_NS_CC;

MainScene* MainScene::create(){
    MainScene* scene = new (std::nothrow) MainScene();
    if (scene && scene->init()){
        scene->autorelease();
        return scene;
    }
    
    delete scene;
    scene = nullptr;
    return nullptr;
}

bool MainScene::init(){
    if (!Scene::init()){
        return false;
    }
    
    Size visible = Director::getInstance()->getVisibleSize();
    
    Sprite* mapBackground = Sprite::create("res/map/map.png");
    mapBackground->setAnchorPoint(Vec2(0, 0));
    this->addChild(mapBackground);
    
    Size backgroundSize = mapBackground->getContentSize();
    
    DrawNode* drawNode = DrawNode::create();
    drawNode->setLineWidth(1);
    drawNode->setColor(Color3B(0, 0, 0));
//    drawNode->drawLine(Vec2(0, 0), Vec2(visible.width / 2, visible.height), Color4F(0, 0, 0, 1));
    this->addChild(drawNode);
    
    for (int i = 0; i < MapConfig::tileColumn; ++i){
        drawNode->drawLine(Vec2(MapConfig::tileWidth * i, 0), Vec2(MapConfig::tileWidth * i, visible.height), Color4F(0, 0, 0, 1));
    }
    
    for (int i = 0; i < MapConfig::tileRow; ++i){
        drawNode->drawLine(Vec2(0, i * MapConfig::tileWidth), Vec2(visible.width, i * MapConfig::tileWidth), Color4F(0, 0, 0, 1));
    }
    
    return true;
}
