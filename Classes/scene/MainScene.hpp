//
//  MainScene.hpp
//  CharacterBehavior
//
//  Created by weilove-jiajiaju on 2017/7/26.
//
//

#ifndef MainScene_hpp
#define MainScene_hpp

#include <stdio.h>
#include "cocos2d.h"

class MainScene: public cocos2d::Scene{
private:
public:
    
    static MainScene* create();
    
    virtual bool init();
};

#endif /* MainScene_hpp */
