//
//  ResourceManager.cpp
//  CharacterBehavior
//
//  Created by weilove-jiajiaju on 2017/8/24.
//
//

#include "ResourceManager.hpp"

#include "utility.hpp"

std::size_t ResourceManager::characterFrameSheetNumber = 1;
std::size_t ResourceManager::buildingFrameSheetNumber = 1;

void ResourceManager::loadAllCharacterFrameSheets(){
    for (std::size_t i = 1; i <= this->characterFrameSheetNumber; ++i){
        std::string sheetPlist = std::string("res/character/character") + intToString(static_cast<int>(i)) + ".plist";
        cocos2d::SpriteFrameCache::getInstance()->addSpriteFramesWithFile(sheetPlist);
    }
}

void ResourceManager::loadAllBuildingFrameSheets(){
    for (std::size_t i = 1; i <= this->buildingFrameSheetNumber; ++i){
        std::string sheetPlist = std::string("res/building/building") + intToString(static_cast<int>(i)) + ".plist";
        cocos2d::SpriteFrameCache::getInstance()->addSpriteFramesWithFile(sheetPlist);
    }
}
