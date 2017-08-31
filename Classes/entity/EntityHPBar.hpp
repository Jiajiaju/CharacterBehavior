//
//  EntityHPBar.hpp
//  CharacterBehavior
//
//  Created by weilove-jiajiaju on 2017/8/31.
//
//

#ifndef EntityHPBar_hpp
#define EntityHPBar_hpp

#include <stdio.h>
#include "cocos2d.h"

enum class EntityHPBarType{
    Big,
    Middle,
    Small
};

class EntityHPBar: public cocos2d::Node{
private:
    
    const static std::map<EntityHPBarType, std::vector<std::string>> _barTypeConfig;
    
    EntityHPBarType _type = EntityHPBarType::Small;
    cocos2d::Sprite* _bg = nullptr;
    cocos2d::Sprite* _process = nullptr;
    
    EntityHPBar(EntityHPBarType type):_type(type) {}
public:
    
    static EntityHPBar* createEntityHPBar(EntityHPBarType type);
    virtual bool init();
    
    void updateHPRatio(float ratio);
};

#endif /* EntityHPBar_hpp */
