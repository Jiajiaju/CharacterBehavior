//
//  MainScene.cpp
//  CharacterBehavior
//
//  Created by weilove-jiajiaju on 2017/7/26.
//
//

#include "MainScene.hpp"
#include "Array2D.hpp"

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
    
    Array2D<int> array(5, 10);
    
    CCLOG("(%d, %d)", static_cast<int>(array.getX()), static_cast<int>(array.getY()));
    
    for (int i = 0; i < array.getX(); ++i){
        for (int j = 0; j < array.getY(); ++j){
            CCLOG("%d, %d: %d", i, j, i * 10 + j);
            array[i][j] = i * 10 + j;
        }
    }
    
    CCLOG("");
    
    for (int i = 0; i < array.getX(); ++i){
        for (int j = 0; j < array.getY(); ++j){
            CCLOG("%d, %d: %d", i, j, array[i][j]);
        }
    }
    
    CCLOG("%d, %d, %d, %d, %d", array[0][0], array[0][1], array[0][2], array[0][3], array[0][4]);
    
    return true;
}
