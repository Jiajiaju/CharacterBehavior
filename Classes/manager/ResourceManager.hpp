//
//  ResourceManager.hpp
//  CharacterBehavior
//
//  Created by weilove-jiajiaju on 2017/8/24.
//
//

#ifndef ResourceManager_hpp
#define ResourceManager_hpp

#include <stdio.h>
#include "cocos2d.h"
#include "Singleton.hpp"

class ResourceManager: public Singleton<ResourceManager>{
private:
public:
    
    static std::size_t characterFrameSheetNumber;
    static std::size_t buildingFrameSheetNumber;
    
    void loadAllCharacterFrameSheets();
    void loadAllBuildingFrameSheets();
};

#endif /* ResourceManager_hpp */
