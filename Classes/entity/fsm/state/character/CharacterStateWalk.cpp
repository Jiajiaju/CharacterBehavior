//
//  CharacterStateWalk.cpp
//  CharacterBehavior
//
//  Created by weilove-jiajiaju on 2017/8/9.
//
//

#include "CharacterStateWalk.hpp"
#include "Vector2D.hpp"

#include "GameManager.hpp"

#include "CharacterStateIdle.hpp"

void CharacterStateWalk::enter(Character *character){
    character->animationFrameCounter = character->characterConfig.animation_walk[0];
    
}

void CharacterStateWalk::execute(Character *character, float dt){
    
    // animation
    character->aniamtionSpeedCounter += 1;
    if (character->aniamtionSpeedCounter > character->animationSpeed){
        character->aniamtionSpeedCounter = 0;
        character->animationFrameCounter += 1;
        if (character->animationFrameCounter > character->characterConfig.animation_walk[1]){
            character->animationFrameCounter = character->characterConfig.animation_walk[0];
        }
        
        character->avatar->setSpriteFrame(GameManagerInstance->characterHelper->getCharacterFrameName(character->characterConfig, character->animationFrameCounter));
    }
    
    // logic
    if (character->attackTarget){
        return;
    }
    
    if (character->getTargetTile() != character->currentTile){
        CCLOG("current tile: (%d, %d)", character->currentTile.column, character->currentTile.row);
        CCLOG("target tile: (%d, %d)", character->getTargetTile().column, character->getTargetTile().row);
        CCLOG(" ");
        
        Vector2D currentVector = BattleGridHelper::getVector2DByBattleTile(character->currentTile);
        Vector2D targetVector = character->getTargetVector2D();
        Vector2D direction = targetVector - currentVector;
        direction.normalize();
        Vector2D deltaPosition = Vector2D(direction.x * character->characterConfig.speed * dt, direction.y * character->characterConfig.speed * dt);
        cocos2d::Vec2 currentPosition = character->avatarNode->getPosition();
        character->setPosition(currentPosition.x + deltaPosition.x, currentPosition.y + deltaPosition.y);
        
        CCLOG("delta: (%f, %f)", deltaPosition.x, deltaPosition.y);
        
        return;
    }
    
    character->stateMachine->setCurrentState(CharacterStateIdle::getInstance());
    
}

void CharacterStateWalk::exit(Character *character){
    character->animationFrameCounter = character->characterConfig.animation_walk[0];
}
