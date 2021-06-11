//
// Created by root on 1/13/21.
//

#ifndef MD_OBJECTIVE_TEST_MULTIBODYWORLD_H
#define MD_OBJECTIVE_TEST_MULTIBODYWORLD_H
#include "../BasicObjects/BasicWorld.h"
#include "BodyWithForceField.h"
#include "../MathObjects/DistributionFunctions.h"
#include "../Enums/Integrators.h"
#include "../MathObjects/Integrators/BasicIntegrator.h"
#include "../MathObjects/Constraints/BasicConstraint.h"

template <typename BodyType,typename percision>
class MultiBodyWorld:public BasicWorld<BodyType>{

protected:
    percision time=0;
    percision BoxLength;
    BasicIntegrator<percision> *basicIntegrator= nullptr;
    BasicConstraint<BodyType> *constraint = nullptr;
public:

    explicit MultiBodyWorld(const unsigned int& NumberOfBodies): BasicWorld<BodyType>(NumberOfBodies){
        static_assert(std::is_base_of<BodyWithForceField<percision>,BodyType>::value,"Should Be a Forced Body type" );
        this->BoxLength = BoxLength;
    }

    ~MultiBodyWorld(){
        delete basicIntegrator;
        delete constraint;
    }

    percision getTime(){
        return time;
    }

    static percision random_norm_unit(){
        return ((percision)std::rand()-((percision)RAND_MAX/2))/RAND_MAX;
    }

    void RandomizePosition(percision rc=1){
        for(int i=1;i<=this->getSize();i++){
            TRY:
            this->operator[](i).Position = {BoxLength*random_norm_unit(),
                                      BoxLength*random_norm_unit(),
                                      BoxLength*random_norm_unit()
            };
            if(BadChoiceOfPosition(i,rc))
                goto TRY;

        }
    }


    void RandomizeVelocity(percision VelocityMean){
        for (int i = 0; i <this->getSize() ; ++i) {
            this->DirectAccess()[i].Velocity = (VelocityMean/std::sqrt(this->getSize()))*RandomNormalizedVector<percision>();
        }
    };


    void updateAccelerationField(){
        for (int i = 0; i < this->getSize(); ++i) {
            this->BodyList[i].Acceleration = {0,0,0};
            for (int j = 0; j < i; ++j) {
                this->BodyList[i].Acceleration += this->BodyList[j].AcclerationField(this->BodyList[i], time);
                this->BodyList[j].Acceleration = -1*this->BodyList[j].Acceleration;
            }
        }
    }

    void setDynamics(const percision & dt,BasicIntegrator<percision> *heap_alloc_basicintegrator_type,BasicConstraint<BodyType>* _constraint){
        this->constraint = _constraint;
        basicIntegrator = heap_alloc_basicintegrator_type;
        basicIntegrator->init();
    }

    void ElapseInTime(const percision & HowMuch, percision dt){
        int n = std::abs(HowMuch/dt)+1;
        dt = HowMuch/n;
        for (int i = 0; i < n; ++i) {
            basicIntegrator->timeElapse(dt);
            time += dt;
        }
    }

    void ApplyConstraint(BodyType& body){
        constraint->check(body);
    }

    percision getBoxLength(){
        return BoxLength;
    }

private:
    bool BadChoiceOfPosition(int i,percision rc){

        percision rc_squared = std::pow(rc,2);
        for(int j=1;j<i;j++){
            if((this->operator[](i).Position -this->operator[](j).Position).getNormSqure()<=rc_squared){ // always try to avoid sqrt!
                return true;
            }
        }
        return false;
    }
};


#endif //MD_OBJECTIVE_TEST_MULTIBODYWORLD_H
