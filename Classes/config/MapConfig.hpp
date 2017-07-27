//
//  MapConfig.hpp
//  CharacterBehavior
//
//  Created by weilove-jiajiaju on 2017/7/28.
//
//

#ifndef MapConfig_hpp
#define MapConfig_hpp

#include <stdio.h>

class MapConfig{
public:
    static int mapWidth;
    static int mapHeight;
    
    static int tileColumn;
    static int tileRow;
    
    static int tileWidth;
};

int MapConfig::mapWidth = 3840;
int MapConfig::mapHeight = 1080;
int MapConfig::tileColumn = 96;
int MapConfig::tileRow = 27;
int MapConfig::tileWidth = 40;

#endif /* MapConfig_hpp */
