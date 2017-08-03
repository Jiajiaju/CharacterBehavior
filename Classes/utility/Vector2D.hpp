//
//  Vector2D.hpp
//  CharacterBehavior
//
//  Created by weilove-jiajiaju on 2017/8/3.
//
//

#ifndef Vector2D_hpp
#define Vector2D_hpp

#include <stdio.h>
#include <math.h>

class Vector2D{
private:
    
public:
    
    float x = 0;
    float y = 0;
    
    Vector2D(): x(0), y(0) {}
    Vector2D(float paramX, float paramY): x(paramX), y(paramY) {}
    Vector2D(const Vector2D& vector2D): x(vector2D.x), y(vector2D.y) {}
    
    Vector2D& operator=(const Vector2D& vector2D){
        this->x = vector2D.x;
        this->y = vector2D.y;
        return *this;
    }
    Vector2D operator+(const Vector2D& vector2D){
        Vector2D newVector2D(this->x + vector2D.x, this->y + vector2D.y);
        return newVector2D;
    }
    Vector2D operator-(const Vector2D& vector2D){
        Vector2D newVector2D(this->x - vector2D.x, this->y - vector2D.y);
        return newVector2D;
    }
    Vector2D operator*(float number){
        Vector2D newVector2D(this->x * number, this->y * number);
        return newVector2D;
    }
    Vector2D operator/(float number){
        Vector2D newVector2D(this->x / number, this->y / number);
        return newVector2D;
    }
    
    void normalize(){
        float distance = sqrtf((this->x * this->x) * (this->y * this->y));
        this->x = this->x / distance;
        this->y = this->y / distance;
    }
    Vector2D getNormalize(){
        float distance = sqrtf((this->x * this->x) * (this->y * this->y));
        Vector2D newVector2D(this->x / distance, this->y / distance);
        return newVector2D;
    }
    
    float getDistance(){
        return sqrtf((this->x * this->x) * (this->y * this->y));
    }
    
};

#endif /* Vector2D_hpp */
