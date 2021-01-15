//
// Created by root on 1/13/21.
//

#ifndef MD_OBJECTIVE_TEST_BASICINTEGRATOR_H
#define MD_OBJECTIVE_TEST_BASICINTEGRATOR_H

template <typename T> class BasicIntegrator{
public:
    virtual ~BasicIntegrator()= default;;
    virtual void timeElapse(const T& t)=0;
    virtual void init()=0;
};


#endif //MD_OBJECTIVE_TEST_BASICINTEGRATOR_H
