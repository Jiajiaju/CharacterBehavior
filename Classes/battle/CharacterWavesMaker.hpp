//
//  CharacterWavesMaker.hpp
//  CharacterBehavior
//
//  Created by weilove-jiajiaju on 2017/9/1.
//
//

#ifndef CharacterWavesMaker_hpp
#define CharacterWavesMaker_hpp

#include <stdio.h>
#include "Character.hpp"
#include "AllModel.hpp"

class CharacterWavesMaker{
private:
    std::map<int, std::vector<CharacterWaveConfig>> _wavesConfig;
    float _totalCounter = 0.0f;
    float _secondCounter = 0.0f;
public:
    CharacterWavesMaker(const std::vector<CharacterWaveConfig> config);
    
    void makeUpdate(float dt);
};

#endif /* CharacterWavesMaker_hpp */
