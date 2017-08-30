//
//  UIUIHelper.hpp
//  CharacterBehavior
//
//  Created by weilove-jiajiaju on 2017/8/30.
//
//

#ifndef UIUIHelper_hpp
#define UIUIHelper_hpp

#include <stdio.h>
#include "cocos2d.h"
#include "Singleton.hpp"

class UIUIHelper: public Singleton<UIUIHelper>{
private:
public:
    
    static cocos2d::Label* getLabel(const std::string& context, int frontSize, cocos2d::Node* parent, float x, float y, int zOrder = 0);
    static cocos2d::Label* getLabel(const std::string& context, int frontSize, const cocos2d::Color3B& color, cocos2d::Node* parent, float x, float y, int zOrder = 0);
};

#endif /* UIUIHelper_hpp */
