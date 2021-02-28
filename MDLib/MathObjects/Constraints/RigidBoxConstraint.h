//
// Created by root on 1/15/21.
//

#ifndef MD_OBJECTIVE_TEST_RIGIDBOXCONSTRAINT_H
#define MD_OBJECTIVE_TEST_RIGIDBOXCONSTRAINT_H

#include "BasicConstraint.h"
#include "../../PhysicalObjects/MultiBodyWorld.h"

template <typename T,typename K>
class RigidBoxConstraint:public BasicConstraint<T>{
    K box_len;
public:
    RigidBoxConstraint(K boxLen){
        static_assert(std::is_base_of<BasicBody<K>,T>::value,"T should dervied from BasicBody");
        box_len = boxLen;
    }

    void check(T& body)override{
        int n1 =  body.Position.x1/box_len;
        int n2 =  body.Position.x2/box_len;
        int n3 =  body.Position.x3/box_len;

        if( std::abs(body.Position.x1) >= box_len ){
            if(body.Position.x1<0){
                body.Position.x1  = -box_len +std::fmod(std::abs(body.Position.x1),box_len);
            } else{
                body.Position.x1  = box_len -std::fmod(std::abs(body.Position.x1),box_len);
            }
        }

        if( std::abs(body.Position.x2 )>= box_len) {
            if(body.Position.x2<0){
                body.Position.x2  = -box_len +std::fmod(std::abs(body.Position.x2),box_len);
            } else{
                body.Position.x2  = box_len -std::fmod(std::abs(body.Position.x2),box_len);
            }
        }

        if( std::abs(body.Position.x3) >= box_len) {
            if(body.Position.x3<0){
                body.Position.x3  = -box_len +std::fmod(std::abs(body.Position.x3),box_len);
            }else{
                body.Position.x3  = box_len -std::fmod(std::abs(body.Position.x3),box_len);
            }
        }
        body.Velocity.x1 *= std::pow(-1,n1);
        body.Velocity.x2 *= std::pow(-1,n2);
        body.Velocity.x3 *= std::pow(-1,n3);
    }
};
#endif //MD_OBJECTIVE_TEST_RIGIDBOXCONSTRAINT_H
