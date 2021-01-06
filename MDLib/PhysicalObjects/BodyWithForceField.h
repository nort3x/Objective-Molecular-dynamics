//
// Created by root on 1/6/21.
//

#ifndef MD_OBJECTIVE_BODYWITHFORCEFIELD_H
#define MD_OBJECTIVE_BODYWITHFORCEFIELD_H

#include <functional>
#include "../BasicObjects/BasicBody.h"

template<typename T> struct BodyWithForceField: BasicBody<T>{
    std::function<ThreeDimValue<T>(const BasicBody<T>&,const T&)> forceField;
    std::function<T(const BasicBody<T>&,const T&)> potentialField;
};


#endif //MD_OBJECTIVE_BODYWITHFORCEFIELD_H
