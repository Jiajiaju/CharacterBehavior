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

class BattleMananger: public Singleton<BattleMananger>{
private:
    BattleScene* _battleScene = nullptr;
    cocos2d::DrawNode* _battleMapDrawNode = nullptr;
    
    void _showMapGrid();
public:
    
    BattleScene* getBattleScene(){ return _battleScene; }
    
    void enterBattle();
    
};

#endif /* BattleManager_hpp */
