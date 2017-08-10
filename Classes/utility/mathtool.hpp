//
//  mathtool.hpp
//  CharacterBehavior
//
//  Created by weilove-jiajiaju on 2017/8/10.
//
//

#ifndef mathtool_hpp
#define mathtool_hpp

#include <stdio.h>
#include <time.h>
#include <math.h>

inline int randomIntRange(int rhs){
    return rand() % rhs;
}

inline int randomIntRange(int lhs, int rhs){
    return (rand() % (rhs - lhs)) + lhs;
}

inline float randomFloatRange(float lhs, float rhs){
    float base = rand() / (float)RAND_MAX;
    return (rhs - lhs) * base + lhs;
}
inline float randomFloatRange(float rhs){
    float base = rand() / (float)RAND_MAX;
    return rhs * base;
}
inline float randomFloatRange(int lhs, int rhs){
    float base = rand() / (float)RAND_MAX;
    return (rhs - lhs) * base + lhs;
}
inline float randomFloatRange(int rhs){
    float base = rand() / (float)RAND_MAX;
    return rhs * base;
}

#endif /* mathtool_hpp */
