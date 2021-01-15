//
// Created by root on 1/15/21.
//

#ifndef MD_OBJECTIVE_TEST_FREESPACE_H
#define MD_OBJECTIVE_TEST_FREESPACE_H
#include "BasicConstraint.h"
#include "../PhysicalObjects/MultiBodyWorld.h"
template <typename T>
class FreeSpace:public BasicConstraint<T>{
public:
    FreeSpace(){

    }

    void check(T& body)override{
        // just do nothing
    }
};
#endif //MD_OBJECTIVE_TEST_FREESPACE_H
