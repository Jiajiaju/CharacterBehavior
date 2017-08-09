//
//  EntityManager.hpp
//  CharacterBehavior
//
//  Created by weilove-jiajiaju on 2017/8/8.
//
//

#ifndef EntityManager_hpp
#define EntityManager_hpp

#include <stdio.h>
#include "Singleton.hpp"

#include "Character.hpp"

class EntityManager: public Singleton<EntityManager>{
private:
    static int _characterIDCounter;
    
    std::map<int, Character*> _characters;
public:
    
    int getCharacterID();

    std::map<int, Character*>& getCharacters(){ return _characters; }
    void registerCharacter(Character* character, int id);
    void unregisterCharacter(Character* character, int id);
    void unregisterCharacter(Character* character);
    void unregisterCharacter(int id);
    Character* getCharacterByID(int id);
};

#endif /* EntityManager_hpp */
