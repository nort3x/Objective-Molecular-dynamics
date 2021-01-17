//
// Created by root on 1/17/21.
//

#ifndef MD_OBJECTIVE_TEST_PERIODICBOUNDRYRECT_H
#define MD_OBJECTIVE_TEST_PERIODICBOUNDRYRECT_H
#include "BasicConstraint.h"
#include "cmath"
template <typename T,typename K>
class PeriodicBoundaryConditionBox:public BasicConstraint<T>{
    K box_len;
public:
    PeriodicBoundaryConditionBox(const K& boxlen){
        this->box_len = boxlen;
    }
    void check(T& body)override{
        if( std::abs(body.Position.x1 >= box_len) ){
            if(body.Position.x1<0){
                body.Position.x1  = box_len -std::fmod(std::abs(body.Position.x1),box_len);
            } else{
                body.Position.x1  = -box_len +std::fmod(std::abs(body.Position.x1),box_len);
            }
        }

        if( std::abs(body.Position.x2 >= box_len) ){
            if(body.Position.x2<0){
                body.Position.x2  = box_len -std::fmod(std::abs(body.Position.x2),box_len);
            } else{
                body.Position.x2  = -box_len +std::fmod(std::abs(body.Position.x2),box_len);
            }
        }

        if( std::abs(body.Position.x3 >= box_len) ){
            if(body.Position.x3<0){
                body.Position.x3  = box_len -std::fmod(std::abs(body.Position.x3),box_len);
            }else{
                body.Position.x3  = -box_len +std::fmod(std::abs(body.Position.x3),box_len);
            }
        }

    }
};

#endif //MD_OBJECTIVE_TEST_PERIODICBOUNDRYRECT_H
