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

#include "CharacterFindAttackTarget.hpp"
#include "CharacterStateIdle.hpp"
#include "CharacterStateDead.hpp"
#include "CharacterStateWait.hpp"
#include "CharacterStateAttack.hpp"

void CharacterStateWalk::enter(Character *character){
    character->animationFrameCounter = character->characterConfig.animation_walk[0];
}

void CharacterStateWalk::execute(Character *character, float dt){
    
    if (character->isDead()){
        character->stateMachine->changeState(CharacterStateDead::getInstance());
        return;
    }
    
    // animation
    character->animationSpeedCounter += 1;
    if (character->animationSpeedCounter > character->characterConfig.animation_walk_speed){
        character->animationSpeedCounter = 0;
        character->animationFrameCounter += 1;
        if (character->animationFrameCounter > character->characterConfig.animation_walk[1]){
            character->animationFrameCounter = character->characterConfig.animation_walk[0];
        }
        
        character->avatar->setSpriteFrame(GameManagerInstance->characterHelper->getCharacterFrameName(character->characterConfig, character->animationFrameCounter));
    }
    
    // attack about logic
    CharacterFindAttackTarget::findAttackTarget(character);
    if (character->attackTarget){
        
//        CCLOG("got attack target: %d -> %d", character->getEntityID(), character->attackTarget->getEntityID());
//        CCLOG("current tile: %d, (%d, %d)", character->getEntityID(), character->currentTile.column, character->currentTile.row);
        
        Vector2D selfCurrentVector = character->getPosition();
        Vector2D targetPointVector = character->attackTarget->getAttackPoint();
        Vector2D targetVector = character->attackTarget->getPosition();
        
        if ((fabsf(selfCurrentVector.x - targetPointVector.x) < character->characterConfig.speed * dt) && (fabsf(selfCurrentVector.y - targetPointVector.y) < character->characterConfig.speed * dt)){
            character->stateMachine->changeState(CharacterStateAttack::getInstance());
            character->attackTarget->stateMachine->changeState(CharacterStateAttack::getInstance());
        }
        
        Vector2D direction = targetPointVector - selfCurrentVector;
        direction.normalize();
        Vector2D deltaPosition = direction * character->characterConfig.speed * dt;
        character->setPosition(selfCurrentVector + deltaPosition);
        if (selfCurrentVector.x > targetVector.x){
            character->turnLeft();
        }else{
            character->turnRight();
        }
        return;
    }
    
    // wait about logic
    Vector2D& targetVector2D = character->getTargetVector2D();
    if (targetVector2D.x < 0.01f || targetVector2D.x >= MapConfig::tileColumn * MapConfig::tileWidth || targetVector2D.y < 0.01f || targetVector2D.y >= MapConfig::tileRow * MapConfig::tileWidth){
        character->stateMachine->changeState(CharacterStateWait::getInstance());
        return;
    }
    
    // walk to target about logic
    if (character->getTargetTile() != character->currentTile){
//        CCLOG("current tile: (%d, %d)", character->currentTile.column, character->currentTile.row);
//        CCLOG("target tile: (%d, %d)", character->getTargetTile().column, character->getTargetTile().row);
//        CCLOG(" ");
        
        Vector2D currentVector = BattleGridHelper::getVector2DByBattleTile(character->currentTile);
        Vector2D targetVector = character->getTargetVector2D();
        Vector2D direction = targetVector - currentVector;
        direction.normalize();
//        Vector2D deltaPosition = Vector2D(direction.x * character->characterConfig.speed * dt, direction.y * character->characterConfig.speed * dt);
        Vector2D deltaPosition = direction * character->characterConfig.speed * dt;
        Vector2D currentPosition = character->getPosition();
        character->setPosition(currentPosition + deltaPosition);
        
        if (targetVector.x > currentVector.x){
            character->turnRight();
        }else {
            character->turnLeft();
        }
        
//        CCLOG("delta: (%f, %f)", deltaPosition.x, deltaPosition.y);
        
        return;
    }
    
    character->stateMachine->changeState(CharacterStateIdle::getInstance());
    
}

void CharacterStateWalk::exit(Character *character){
    character->animationFrameCounter = character->characterConfig.animation_walk[0];
}
