//
//  BattleScene.cpp
//  CharacterBehavior
//
//  Created by weilove-jiajiaju on 2017/8/2.
//
//

#include "BattleScene.hpp"

#include "import.hpp"

USING_NS_CC;

BattleScene* BattleScene::createScene(){
    BattleScene* scene = new (std::nothrow) BattleScene();
    if (scene && scene->init()){
        scene->autorelease();
        return scene;
    }
    
    delete scene;
    scene = nullptr;
    return nullptr;
}

bool BattleScene::init(){
    if (!Scene::init()){
        return false;
    }
    
    this->map = Sprite::create("res/map/map.png");
    this->map->setAnchorPoint(Vec2(0, 0));
    this->addChild(this->map);
    Size backgroundSize = this->map->getContentSize();
    
    this->groundLayer = Node::create();
    this->map->addChild(this->groundLayer, 1);
    
    this->skyLayer = Node::create();
    this->map->addChild(this->skyLayer, 1);
    
    this->uiLayer = Node::create();
    this->addChild(this->uiLayer);
    
    Sprite* tree = Sprite::create("res/map/tree.png");
    tree->setPosition(backgroundSize.width / 2, backgroundSize.height / 2);
    this->groundLayer->addChild(tree);
    
    return true;
}
