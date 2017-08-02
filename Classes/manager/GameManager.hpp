//
//  GameManager.hpp
//  CharacterBehavior
//
//  Created by weilove-jiajiaju on 2017/7/27.
//
//

#ifndef GameManager_hpp
#define GameManager_hpp

#include <stdio.h>
#include "cocos2d.h"
#include "Singleton.hpp"

#include "BattleManager.hpp"

class GameManager: public Singleton<GameManager>{
private:
public:
    
    static BattleMananger* battleMananger;
    
    void init();
    
    void startGame();
};

#endif /* GameManager_hpp */
