//
//  CharacterFindAttackTarget.cpp
//  CharacterBehavior
//
//  Created by weilove-jiajiaju on 2017/8/30.
//
//

#include "CharacterFindAttackTarget.hpp"

#include "GameManager.hpp"

Character* CharacterFindAttackTarget::_processCharacterCurrentAttackTarget(Character *character){
    if (character->attackTarget == nullptr){
        return nullptr;
    }
    
    if (character->attackTarget->isDead() || character->attackTarget->isExit()){
        return nullptr;
    }
    
    return character->attackTarget;
    
}

Character* CharacterFindAttackTarget::findAttackTarget(Character *character){
    return _findAttackTargetNearest(character);
}

Character* CharacterFindAttackTarget::_findAttackTargetNearest(Character *character){
    character->attackTarget = _processCharacterCurrentAttackTarget(character);
    if (character->attackTarget){
        return character->attackTarget;
    }
    std::map<int, Character*>& characters = GameManagerInstance->entityManager->getCharacters();
    Character* targetCharacter = nullptr;
    for (auto iter = characters.begin(); iter != characters.end(); ++iter){
        
        if (iter->second == character){
            continue;
        }
        if (iter->second->isDead() || iter->second->isExit()){
            continue;
        }
        if (iter->second->characterFaction == character->characterFaction){
            continue;
        }
        
        if (targetCharacter == nullptr){
            targetCharacter = iter->second;
        }else {
            if ( EntityManager::getEntityDistanceSquare(character, iter->second) < EntityManager::getEntityDistanceSquare(character, targetCharacter) ){
                targetCharacter = iter->second;
            }
        }
    }
    character->attackTarget = targetCharacter;
    return targetCharacter;
}
