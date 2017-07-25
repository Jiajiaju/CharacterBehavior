//
//  MainScene.cpp
//  CharacterBehavior
//
//  Created by weilove-jiajiaju on 2017/7/26.
//
//

#include "MainScene.hpp"

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
    
    Sprite* mapBackground = Sprite::create("res/map/map.png");
    mapBackground->setAnchorPoint(Vec2(0, 0));
    this->addChild(mapBackground);
    
    return true;
}
