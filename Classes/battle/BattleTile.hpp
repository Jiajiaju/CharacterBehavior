//
//  BattleTile.hpp
//  CharacterBehavior
//
//  Created by weilove-jiajiaju on 2017/8/6.
//
//

#ifndef BattleTile_hpp
#define BattleTile_hpp

#include <stdio.h>

/***************************************************
//  LeftTop -------- CentreTop -------- RightTop
//     |                                    |
//     |                                    |
//     |                                    |
// LeftMiddle ---- CentreMiddle ------ RightMiddle
//     |                                    |
//     |                                    |
// LeftBottom ---- CentreBottom ------ RightBottom
****************************************************/

enum class BattleTileFocus{
    LeftTop,
    CentreTop,
    RightTop,
    
    LeftMiddle,
    CentreMiddle,
    RightMiddle,
    
    LeftBottom,
    CentreBottom,
    RightBottom
};

class BattleTile{
public:
    BattleTile():row(-1), column(-1) {}
    BattleTile(int paramColumn, int paramRow):column(paramColumn), row(paramRow) {}
    BattleTileFocus focus = BattleTileFocus::CentreMiddle;
    int column = 0;
    int row = 0;
    
    int cost = 0;
    
    bool operator==(const BattleTile& rhs){ return (row == rhs.row && column == rhs.column); }
    bool operator!=(const BattleTile& rhs){ return (row != rhs.row || column != rhs.column); }
};

#endif /* BattleTile_hpp */
