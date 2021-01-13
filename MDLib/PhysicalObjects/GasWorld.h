//
// Created by root on 1/13/21.
//

#ifndef MD_OBJECTIVE_TEST_GASWORLD_H
#define MD_OBJECTIVE_TEST_GASWORLD_H
#include "../BasicObjects/BasicWorld.h"
#include "BodyWithForceField.h"
#include "../MathObjects/DistributionFunctions.h"

template <typename BodyType,typename percision>
class GasWorld: public BasicWorld<BodyType>{

protected:
    percision time=0;

    using BasicWorld<BodyType>::getSize;
    using BasicWorld<BodyType>::operator[];
    using BasicWorld<BodyType>::DirectAccess;
    using BasicWorld<BodyType>::BodyList;

    percision BoxLength;
public:
    explicit GasWorld(const unsigned int& NumberOfBodies,const percision& BoxLength):BasicWorld<BodyType>(NumberOfBodies){
        static_assert(std::is_base_of<BodyWithForceField<percision>,BodyType>::value,"Should Be a Forced Body type" );
        this->BoxLength = BoxLength;
    }

    double getTime(){
        return time;
    }

    void RandomizePosition(double rc=1){
        for(int i=1;i<=getSize();i++){
            TRY:
            operator[](i).Position = {BoxLength*(double)std::rand()/RAND_MAX,
                                      BoxLength*(double)std::rand()/RAND_MAX,
                                      BoxLength*(double)std::rand()/RAND_MAX };
            if(BadChoiceOfPosition(i,rc))
                goto TRY;

        }
    }

    void RandomizeVelocity(double VelocityMean){
        for (int i = 0; i <getSize() ; ++i) {
            DirectAccess()[i].Velocity = (VelocityMean/getSize())*RandomNormalizedVector<double>();
        }
    };


    void updateForce(){
        for (int i = 0; i < getSize(); ++i) {
            for (int j = 0; j < getSize(); ++j) {
                BodyList[i].Force += BodyList[j].forceField(BodyList[i],time);
            }
        }
    }

    void setCalculator(){}

private:
    bool BadChoiceOfPosition(int i,double rc){

        double rc_squared = std::pow(rc,2);
        for(int j=1;j<i;j++){
            if((operator[](i).Position -operator[](j).Position).getNormSqure()<=rc_squared){ // always try to avoid sqrt!
                return true;
            }
        }
        return false;
    }
};


#endif //MD_OBJECTIVE_TEST_GASWORLD_H
