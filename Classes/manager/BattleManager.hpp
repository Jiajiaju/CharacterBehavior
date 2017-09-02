//
//  BattleManager.hpp
//  CharacterBehavior
//
//  Created by weilove-jiajiaju on 2017/8/2.
//
//

#ifndef BattleManager_hpp
#define BattleManager_hpp

#include <stdio.h>
#include "cocos2d.h"
#include "import.hpp"
#include "Singleton.hpp"

#include "BattleScene.hpp"
#include "Character.hpp"
#include "Building.hpp"

#include "CharacterWavesMaker.hpp"

class BattleMananger: public Singleton<BattleMananger>{
private:
    
#pragma mark: scene
    BattleScene* _battleScene = nullptr;
    cocos2d::EventListenerTouchOneByOne* _battleTouchListener = nullptr;
    cocos2d::DrawNode* _battleMapDrawNode = nullptr;
    
    bool _onTouchBegan(cocos2d::Touch* touch, cocos2d::Event* event);
    void _onTouchMoved(cocos2d::Touch* touch, cocos2d::Event* event);
    void _onTouchEnded(cocos2d::Touch* touch, cocos2d::Event* event);
    
#pragma mark: character
    
    CharacterWavesMaker* _characterWavesMaker = nullptr;
    
#pragma mark: debug
    void _showMapGrid();
    void _addCharater();
    void _addBuilding();
public:
    
    BattleScene* getBattleScene(){ return _battleScene; }
    
    void enterBattle();
    
    void update(float dt);
    
};

#endif /* BattleManager_hpp */
