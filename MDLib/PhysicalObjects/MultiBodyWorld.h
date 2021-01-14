//
// Created by root on 1/13/21.
//

#ifndef MD_OBJECTIVE_TEST_MULTIBODYWORLD_H
#define MD_OBJECTIVE_TEST_MULTIBODYWORLD_H
#include "../BasicObjects/BasicWorld.h"
#include "BodyWithForceField.h"
#include "../MathObjects/DistributionFunctions.h"
#include "../Enums/Integrators.h"
#include "../MathObjects/BasicIntegrator.h"

template <typename BodyType,typename percision>
class MultiBodyWorld:public BasicWorld<BodyType>{

protected:
    percision time=0;
    percision BoxLength;
public:

    explicit MultiBodyWorld(const unsigned int& NumberOfBodies, const percision& BoxLength): BasicWorld<BodyType>(NumberOfBodies){
        static_assert(std::is_base_of<BodyWithForceField<percision>,BodyType>::value,"Should Be a Forced Body type" );
        this->BoxLength = BoxLength;
    }

    double getTime(){
        return time;
    }

    void RandomizePosition(double rc=1){
        for(int i=1;i<=this->getSize();i++){
            TRY:
            this->operator[](i).Position = {BoxLength*(double)std::rand()/RAND_MAX,
                                      BoxLength*(double)std::rand()/RAND_MAX,
                                      BoxLength*(double)std::rand()/RAND_MAX };
            if(BadChoiceOfPosition(i,rc))
                goto TRY;

        }
    }


    void RandomizeVelocity(double VelocityMean){
        for (int i = 0; i <this->getSize() ; ++i) {
            this->DirectAccess()[i].Velocity = (VelocityMean/this->getSize())*RandomNormalizedVector<double>();
        }
    };


    void updateAccelerationField(){
        for (int i = 0; i < this->getSize(); ++i) {
            this->BodyList[i].Acceleration = {0,0,0};
            for (int j = 0; j < this->getSize(); ++j) {
                this->BodyList[i].Acceleration += this->BodyList[j].AcclerationField(this->BodyList[i], time);
            }
        }
    }


private:
    bool BadChoiceOfPosition(int i,percision rc){

        double rc_squared = std::pow(rc,2);
        for(int j=1;j<i;j++){
            if((this->operator[](i).Position -this->operator[](j).Position).getNormSqure()<=rc_squared){ // always try to avoid sqrt!
                return true;
            }
        }
        return false;
    }
};


#endif //MD_OBJECTIVE_TEST_MULTIBODYWORLD_H
