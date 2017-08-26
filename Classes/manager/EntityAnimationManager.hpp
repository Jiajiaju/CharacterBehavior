//
//  EntityAnimationManager.hpp
//  CharacterBehavior
//
//  Created by weilove-jiajiaju on 2017/8/26.
//
//

#ifndef EntityAnimationManager_hpp
#define EntityAnimationManager_hpp

#include <stdio.h>
#include "cocos2d.h"
#include "Singleton.hpp"

class EntityAnimationManager: public Singleton<EntityAnimationManager>{
private:
    std::map<std::string, std::map<std::string, cocos2d::Animation*>> _characterAnimations;
    std::map<std::string, std::map<std::string, cocos2d::Animation*>> _buildingAnimations;
public:
    void loadCharacterAnimation(const std::string& characterTypeName);
    void loadBuildingAnimation(const std::string& buildingTypeName);
    
    cocos2d::Animation* getCharacterAnimation(const std::string& characterTypeName, const std::string& animationType);
    cocos2d::Animation* getBuildingAniamtion(const std::string& buildingTypeName, const std::string& animationType);
};

#endif /* EntityAnimationManager_hpp */
