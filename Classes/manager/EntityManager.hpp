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
#include "Building.hpp"

class EntityManager: public Singleton<EntityManager>{
private:
    static int _characterIDCounter;
    static int _buildingIDCounter;
    
    std::map<int, Character*> _characters;
    std::map<int, Building*> _buildings;
public:
    
    int getCharacterID();
    std::map<int, Character*>& getCharacters(){ return _characters; }
    void registerCharacter(Character* character, int id);
    void unregisterCharacter(Character* character, int id);
    void unregisterCharacter(Character* character);
    void unregisterCharacter(int id);
    Character* getCharacterByID(int id);
    
    int getBuildingID();
    std::map<int, Building*>& getBuildings(){ return _buildings; }
    void registerBuilding(Building* building, int id);
    void unregisterBuilding(Building* building, int id);
    void unregisterBuilding(Building* building);
    void unregisterBuilding(int id);
    Building* getBuildingByID(int id);
};

#endif /* EntityManager_hpp */
