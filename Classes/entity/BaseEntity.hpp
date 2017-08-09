//
//  BaseEntity.hpp
//  CharacterBehavior
//
//  Created by weilove-jiajiaju on 2017/8/8.
//
//

#ifndef BaseEntity_hpp
#define BaseEntity_hpp

#include <stdio.h>
#include "BaseEntityAvatar.hpp"

class BaseEntity{
private:
protected:
    int _id = -1;
    BaseEntity(int id):_id(id) {}
    virtual ~BaseEntity(){
        
    }
public:
    
    BaseEntityAvatar* avatar = nullptr;
    
    virtual void destory();
    
    virtual void update(float dt) = 0;
};

#endif /* BaseEntity_hpp */
