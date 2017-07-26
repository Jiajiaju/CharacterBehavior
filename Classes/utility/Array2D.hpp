//
//  Array2D.hpp
//  CharacterBehavior
//
//  Created by weilove-jiajiaju on 2017/7/27.
//
//

#ifndef Array2D_hpp
#define Array2D_hpp

#include <stdio.h>

template <typename Data>
class Array2D {
private:
    
    std::size_t _maxX = 0;
    std::size_t _maxY = 0;
    
    Data* _array = nullptr;
    
public:
    Array2D(std::size_t x, std::size_t y):
    _maxX(x), _maxY(y){
        _array = new Data[_maxX * _maxY];
    }
    
    Array2D(const Array2D& array2D){
        _maxX = array2D._maxX;
        _maxY = array2D._maxY;
        
        _array = array2D._array;
    }
    
    ~Array2D(){
        _maxX = 0;
        _maxY = 0;
        delete [] _array;
    }
    
    Array2D& operator=(const Array2D& array2D){
        _maxX = array2D._maxX;
        _maxY = array2D._maxY;
        if (_array){
            delete [] _array;
        }
        _array = array2D._array;
    }
    
    std::size_t getX(){ return _maxX; }
    std::size_t getY(){ return _maxY; }
    
    Data* operator[](int x){
        assert(x < _maxX);
        return (_array + x * _maxY);
    }
    
    
};

#endif /* Array2D_hpp */
