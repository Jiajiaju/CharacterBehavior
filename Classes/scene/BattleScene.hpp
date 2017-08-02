//
//  BattleScene.hpp
//  CharacterBehavior
//
//  Created by weilove-jiajiaju on 2017/8/2.
//
//

#ifndef BattleScene_hpp
#define BattleScene_hpp

#include <stdio.h>
#include "cocos2d.h"

class BattleScene: public cocos2d::Scene{
private:
public:
    
    static BattleScene* createScene();
    
    virtual bool init();
};

#endif /* BattleScene_hpp */
