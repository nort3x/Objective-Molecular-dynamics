//
// Created by -H on 1/6/21.
//

/*
 *  most basic BasicBody type that can be inherited to build more useful BodyTypes
*/
#ifndef MD_OBJECTIVE_BASICBODY_H
#define MD_OBJECTIVE_BASICBODY_H

#include "ThreeDimValue.h"

template<typename ValType>
struct BasicBody{

    // most fundamental set of attributes a body can have
    ThreeDimValue<ValType> Position;
    ThreeDimValue<ValType> Velocity;
    ThreeDimValue<ValType> Force;

};



#endif //MD_OBJECTIVE_BASICBODY_H
