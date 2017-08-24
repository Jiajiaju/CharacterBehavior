//
//  GameManager.hpp
//  CharacterBehavior
//
//  Created by weilove-jiajiaju on 2017/7/27.
//
//

#ifndef GameManager_hpp
#define GameManager_hpp

#include <stdio.h>
#include "cocos2d.h"
#include "Singleton.hpp"

#include "BattleManager.hpp"
#include "EntityManager.hpp"
#include "ConfigManager.hpp"

#include "BattleGridHelper.hpp"
#include "CharacterHelper.hpp"

class GameManager: public Singleton<GameManager>{
private:
public:
    
    static BattleMananger* battleMananger;
    static EntityManager*  entityManager;
    static ConfigManager*  configManager;
    
    static BattleGridHelper* battleGridHelper;
    static CharacterHelper*  characterHelper;
    
    void init();
    
    void startGame();
    
    void update(float dt);
};

#ifndef GameManagerInstance
#define GameManagerInstance (GameManager::getInstance())
#endif

#endif /* GameManager_hpp */
