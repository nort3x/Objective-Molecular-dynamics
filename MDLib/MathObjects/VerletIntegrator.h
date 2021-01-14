//
// Created by root on 1/13/21.
//

#ifndef MD_OBJECTIVE_TEST_VERLETINTEGRATOR_H
#define MD_OBJECTIVE_TEST_VERLETINTEGRATOR_H

#include "BasicIntegrator.h"
#include "../PhysicalObjects/MultiBodyWorld.h"
#include "../PhysicalObjects/BodyWithForceField.h"


template <typename T,typename K>
class VerletIntegrator : public BasicIntegrator<K> {
    MultiBodyWorld<T,K>* world;
public:
    VerletIntegrator(MultiBodyWorld<T,K>* world,const K& dt){
        static_assert(std::is_base_of<BasicBody<K>,T>::value,"Should be derived from BasicBody");
        this->world = world;
        world->updateAccelerationField();
        FirstIteration(dt);         // shift FutureBuffer a little
    }

    ~VerletIntegrator() override{
    };

    void timeElapse(const K &dt)override{
        FirstIteration(dt);
    }

private:

    void FirstIteration(const K& dt){
        // ehsan method!
        for (int i = 0; i < world->getSize(); ++i) {
            world->BodyList[i].Velocity += 0.5*dt*(world->BodyList[i].Acceleration);
            // v(t0+dt) = vt0 + at0+a(t0+dt)*dt/2;
        }
        // x(t0+dt) = xt0 + vt0*dt + 1/2*at0*dt^2
        for (int i = 0; i < world->getSize(); ++i) {
            world->BodyList[i].Position += dt*world->BodyList[i].Velocity;
        }
        world->updateAccelerationField();
        for (int i = 0; i < world->getSize(); ++i) {
            world->BodyList[i].Velocity += 0.5*dt*(world->BodyList[i].Acceleration);
            // v(t0+dt) = vt0 + at0+a(t0+dt)*dt/2;
        }
    }
};


#endif //MD_OBJECTIVE_TEST_VERLETINTEGRATOR_H
