//
// Created by root on 1/15/21.
//

#ifndef MD_OBJECTIVE_TEST_RIGIDBOXCONSTRAINT_H
#define MD_OBJECTIVE_TEST_RIGIDBOXCONSTRAINT_H

#include "BasicConstraint.h"
#include "../PhysicalObjects/MultiBodyWorld.h"

template <typename T,typename K>
class RigidBoxConstraint:public BasicConstraint<T>{
    MultiBodyWorld<T,K> *world = nullptr;
public:
    RigidBoxConstraint(MultiBodyWorld<T,K>* world_ref){
        static_assert(std::is_base_of<BasicBody<K>,T>::value,"T should dervied from BasicBody");
        world = world_ref;
    }

    void check(T& body)override{
        int n1 =  body.Position.x1/world->getBoxLength();
        int n2 =  body.Position.x2/world->getBoxLength();
        int n3 =  body.Position.x3/world->getBoxLength();
        ThreeDimValue<K> new_pos;
        if(n1%2 == 0 ){
            new_pos.x1  = body.Position.x1 - n1*world->getBoxLength();
        }else{
            new_pos.x1  = world->getBoxLength() -  (body.Position.x1 - n1*world->getBoxLength());
        }
        if(n2%2 == 0 ){
            new_pos.x2  = body.Position.x2 - n2*world->getBoxLength();
        }else{
            new_pos.x2  = world->getBoxLength() -(body.Position.x2 - n2*world->getBoxLength());
        }
        if(n3%2 == 0 ){
            new_pos.x3  = body.Position.x3 - n3*world->getBoxLength();
        }else{
            new_pos.x3  = world->getBoxLength() - (body.Position.x3 - n3*world->getBoxLength());
        }
        body.Position = new_pos;
        body.Velocity.x1 *= std::pow(-1,n1);
        body.Velocity.x2 *= std::pow(-1,n2);
        body.Velocity.x3 *= std::pow(-1,n3);
    }
};
#endif //MD_OBJECTIVE_TEST_RIGIDBOXCONSTRAINT_H
