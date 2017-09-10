//
//  CharacterConfig.hpp
//  CharacterBehavior
//
//  Created by weilove-jiajiaju on 2017/8/17.
//
//

#ifndef CharacterConfig_hpp
#define CharacterConfig_hpp

#include <stdio.h>

struct CharacterConfig{
    std::string type = "";
    int hp = 0;
    int attack = 0;
    int defence = 0;
    int speed = 0;
    int attack_interval = 0;
    
    int real_height = 0;
    float anchor_point[2] = {0.0, 0.0};
    
    
    int animation_stand[2] = {0, 0};
    int animation_stand_speed = 0;
    
    int animation_walk[2] = {0, 0};
    int animation_walk_speed = 0;
    
    int animation_attack[3] = {0, 0, 0};
    int animation_attack_speed = 0;
    
    int animation_dead[2] = {0, 0};
    int animation_dead_speed = 0;
    
    int can_remote_attack = 0;
    int animation_remote_attack[3] = {0, 0, 0};
    std::string bullet = "";
    
    int can_range_attack = 0;
    int animation_range_attack[3] = {0, 0, 0};
    
};

#endif /* CharacterConfig_hpp */
