//
//  Tile.hpp
//  CharacterBehavior
//
//  Created by weilove-jiajiaju on 2017/8/6.
//
//

#ifndef Tile_hpp
#define Tile_hpp

#include <stdio.h>

namespace PathFinder {
    class Tile{
    public:
        int column = 0;
        int row = 0;
        
        int fValue = 0;
        int gValue = 0;
        int hVAlue = 0;
        
        int cost = 0;
    };
}

#endif /* Tile_hpp */
