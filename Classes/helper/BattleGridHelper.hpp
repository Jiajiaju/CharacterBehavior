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
    
    static Vector2D getVector2DByBattleTile(const BattleTile& battleTile);
    static BattleTile getBattleTileByVector2D(const Vector2D& vector2D);
    
    
    static cocos2d::Vec2 dealPositionOffsetInTile(BattleTileFocus focus, const cocos2d::Vec2& positionLeftBottom);
    
    static int getGroundZOrder(const BattleTile& battleTile);
    static int getGroundZOrder(const Vector2D& vector2D);
    
    static int getSkyZOrder(const BattleTile& battleTile);
    static int getSkyZOrder(const Vector2D& vector2D);
    
};

#endif /* BattleGridHelper_hpp */
