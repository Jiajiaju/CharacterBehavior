//
//  Character.cpp
//  CharacterBehavior
//
//  Created by weilove-jiajiaju on 2017/8/5.
//
//

#include "Character.hpp"

Character::Character(){
    this->avatar = CharacterAvatar::createCharacterAvatar();
}

Character::~Character(){
}

Character* Character::createCharacter(){
    Character* newCharacter = new (std::nothrow) Character();
    if (newCharacter){
        return newCharacter;
    }
    
    delete newCharacter;
    newCharacter = nullptr;
    return nullptr;
}

void Character::destory(){
    this->avatar->destory();
    delete this;
}
