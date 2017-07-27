//
//  Singleton.hpp
//  CharacterBehavior
//
//  Created by weilove-jiajiaju on 2017/7/27.
//
//

#ifndef Singleton_hpp
#define Singleton_hpp

#include <stdio.h>

template <typename Node>
class Singleton{
private:
    
    static Node* _instancePointer;
    
    Singleton(const Singleton& singleton){}
    Singleton& operator=(const Singleton& singleton){}
    
protected:
    
    Singleton(){}
    ~Singleton(){
        delete _instancePointer;
    }
    
public:
    
    static Node* volatile getInstance(){
        if (_instancePointer == nullptr){
            _instancePointer = new (std::nothrow) Node();
            assert(_instancePointer != nullptr);
        }
        return _instancePointer;
    }
};

template <typename Node>
Node* Singleton<Node>::_instancePointer = nullptr;

#endif /* Singleton_hpp */
