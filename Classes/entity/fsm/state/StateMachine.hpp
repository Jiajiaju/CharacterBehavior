//
//  StateMachine.hpp
//  CharacterBehavior
//
//  Created by weilove-jiajiaju on 2017/8/9.
//
//

#ifndef StateMachine_hpp
#define StateMachine_hpp

#include <stdio.h>
#include "EntityState.hpp"

template <typename Entity>
class StateMachine{
private:
    Entity* _owner = nullptr;
    EntityState<Entity>* _currentState = nullptr;
    EntityState<Entity>* _globalState = nullptr;
    EntityState<Entity>* _previousState = nullptr;
public:
    
    StateMachine(Entity* owner):_owner(owner){}
    
    void setCurrentState(EntityState<Entity>* state){ _currentState = state; }
    void setGlobalState(EntityState<Entity>* state){ _globalState = state; }
    void setPreviousState(EntityState<Entity>* state){ _previousState = state; }
    
    void changeState(EntityState<Entity>* state){
        assert(state != nullptr);
        if (_currentState != nullptr){
            _currentState->exit(_owner);
        }
        _currentState = state;
        _currentState->enter(_owner);
    }
    
    void update(float dt){
        if (_currentState != nullptr){
            _currentState->execute(_owner, dt);
        }
    }
};

#endif /* StateMachine_hpp */
