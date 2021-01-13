//
// Created by root on 1/13/21.
//

#ifndef MD_OBJECTIVE_TEST_VERLETINTEGRATOR_H
#define MD_OBJECTIVE_TEST_VERLETINTEGRATOR_H

#include "BasicIntegrator.h"

template<typename T>
class VerletIntegrator: public BasicIntegrator<T>{


public:
    VerletIntegrator(){

    }

    ~VerletIntegrator() override{

    };

    void timeElapse(const T &t) override {

    }

};


#endif //MD_OBJECTIVE_TEST_VERLETINTEGRATOR_H
