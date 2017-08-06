//
//  BattleGridHelper.hpp
//  CharacterBehavior
//
//  Created by weilove-jiajiaju on 2017/8/6.
//
//

#ifndef BattleGridHelper_hpp
#define BattleGridHelper_hpp

#include <stdio.h>
#include "cocos2d.h"

#include "Array2D.hpp"
#include "Vector2D.hpp"
#include "Singleton.hpp"

#include "import.hpp"

#include "BattleTile.hpp"

class BattleGridHelper: public Singleton<BattleGridHelper>{
private:
    static int _groundBaseZOrder;
    static int _skyBaseZOReder;
public:
    static cocos2d::Vec2 getPositionByBattleTile(const BattleTile& battleTile);
    static BattleTile getBattleTileByPosition(const cocos2d::Vec2& position);
    static cocos2d::Vec2 dealPositionOffsetInTile(BattleTileFocus focus, const cocos2d::Vec2& positionLeftBottom);
    
    static int getGroundZOrderByBattleTile(const BattleTile& battleTile);
    static int getGronudZOrderByPosition(const cocos2d::Vec2& position);
    
    static int getSkyZOrderByBattleTile(const BattleTile& battleTile);
    static int getSkyZOrderByPosition(const cocos2d::Vec2& position);
};

#endif /* BattleGridHelper_hpp */
