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
    T* past_buffer;
public:
    VerletIntegrator(MultiBodyWorld<T,K>* world,const K& dt){
        static_assert(std::is_base_of<BasicBody<K>,T>::value,"Should be derived from BasicBody");
        this->world = world;
        past_buffer = new T[world->getSize()]();
        world->updateAccelerationField();
        TakeNowBufferInPastBuffer(); // remember first config as now
        FirstIteration(dt);         // shift FutureBuffer a little
    }

    ~VerletIntegrator() override{
        delete [] past_buffer;
    };

    void timeElapse(const K &dt)override{
        TakeNowBufferInPastBuffer();
        // x(t0+dt) = vt0 * dt + 1/2 * a * dt^2
        for (int i = 0; i < world->getSize(); ++i) {
            world->BodyList[i].Position += dt*world->BodyList[i].Velocity
                                           +(0.5*std::pow(dt,2))*world->BodyList[i].Acceleration;
        }
        world->updateAccelerationField();
        for (int i = 0; i < world->getSize(); ++i) {
            world->BodyList[i].Velocity += 0.5*dt*(world->BodyList[i].Acceleration+past_buffer[i].Acceleration);
            // v(t0+dt) = vt0 + at0+a(t0+dt)*dt/2;
        }
    }

private:

    void TakeNowBufferInPastBuffer(){
        memcpy(past_buffer, world->BodyList, world->getSize() * sizeof(T));
    }
    void FirstIteration(const K& dt){
        // x(t0+dt) = vt0 * dt + 1/2 * a * dt^2
        for (int i = 0; i < world->getSize(); ++i) {
            world->BodyList[i].Position += dt*world->BodyList[i].Velocity
                    +(0.5*std::pow(dt,2))*world->BodyList[i].Acceleration;
        }
        world->updateAccelerationField();
        for (int i = 0; i < world->getSize(); ++i) {
            world->BodyList[i].Velocity += 0.5*dt*(world->BodyList[i].Acceleration+past_buffer[i].Acceleration);
            // v(t0+dt) = vt0 + at0+a(t0+dt)*dt/2;
        }
    }
};


#endif //MD_OBJECTIVE_TEST_VERLETINTEGRATOR_H
