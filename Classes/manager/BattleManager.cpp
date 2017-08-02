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
}
