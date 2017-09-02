//
//  CharacterWavesMaker.cpp
//  CharacterBehavior
//
//  Created by weilove-jiajiaju on 2017/9/1.
//
//

#include "CharacterWavesMaker.hpp"

CharacterWavesMaker::CharacterWavesMaker(const std::vector<CharacterWaveConfig> config): _totalCounter(0.0f), _secondCounter(0.0f){
    for (auto iter = config.begin(); iter != config.end(); ++iter){
        _wavesConfig[iter->delay].push_back(*iter);
    }
}

void CharacterWavesMaker::makeUpdate(float dt){
    _secondCounter += dt;
    if (_secondCounter >= 1){
        _totalCounter += _secondCounter;
        _secondCounter = _secondCounter - 1;
        if (_wavesConfig.find(static_cast<int>(_totalCounter)) != _wavesConfig.end()){
            CCLOG("make character");
            for (auto iter = _wavesConfig[static_cast<int>(_totalCounter)].begin(); iter != _wavesConfig[static_cast<int>(_totalCounter)].end(); ++iter){
                CCLOG("make a %s", iter->typeName.c_str());
            }
        }
    }
}
