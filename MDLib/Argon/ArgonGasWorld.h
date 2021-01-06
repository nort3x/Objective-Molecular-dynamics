//
// Created by root on 1/6/21.
//

#ifndef MD_OBJECTIVE_ARGONGASWORLD_H
#define MD_OBJECTIVE_ARGONGASWORLD_H

#include <cstdlib>
#include "../BasicObjects/BasicWorld.h"
#include "ArgonAtom.h"
#include "../PhysicalObjects/DistributionFunctions.h"

class ArgonGasWorld: public BasicWorld<ArgonAtom>{
private:
    double time;
    double BoxLength;
public:

    explicit ArgonGasWorld(const unsigned int &numberOfBodies,double BoxLength) : BasicWorld(numberOfBodies){
        this->BoxLength = BoxLength;
    }

    // populate position
    void RandomizePosition(double rc=ArgonAtom::rc){
        for(int i=1;i<=getSize();i++){
            TRY:
            operator[](i).Position = {BoxLength*(double)std::rand()/RAND_MAX,
                                    BoxLength*(double)std::rand()/RAND_MAX,
                                    BoxLength*(double)std::rand()/RAND_MAX };
            if(BadChoiceOfPosition(i,rc))
                goto TRY;

        }
    }
    bool BadChoiceOfPosition(int i,double rc){

        double rc_squared = std::pow(rc,2);
        for(int j=1;j<i;j++){
            if((operator[](i).Position -operator[](j).Position).getNormSqure()<=rc_squared){ // always try to avoid sqrt!
                return true;
            }
        }
        return false;
    }

    // populate velocity
    void RandomizeVelocity(double Tempture,double VelocityStepSize,DistributionFunction df,double VelocityMean=1){
        switch (df) {
            case uniform:
                for (int i = 0; i <getSize() ; ++i) {
                    DirectAccess()[i].Velocity = (VelocityMean/getSize())*RandomNormalizedVector<double>();
                }
                break;
            case Boltzmann:   // Boltzmann doesnt work , need more testing
                int i=1;
                double vel =0,O;
                BoltzmannDist<double> bd(ArgonAtom::ArgonMass,Tempture);
                while (i<getSize()){
                    O = bd.getFraction(vel,vel+VelocityStepSize,VelocityStepSize);
                    for (int j = i; j <O; ++j){
                        operator[](j).Velocity = (vel + (double )VelocityStepSize/2) * (RandomNormalizedVector<double>());
                    }
                    i+= (int)O;
                    vel += VelocityStepSize;
                }
                break;
        }
    };

    double getTotalKineticEnergy(){
        double total_V2 =0;
        for (int i = 0; i < getSize(); ++i) {
            total_V2 += DirectAccess()[i].Velocity.getNormSqure();
        }
        return 0.5*ArgonAtom::ArgonMass*total_V2;
    };

    double getTotalPotentialEnergy(){
        double Vt=0;
        for (int i = 0; i < getSize(); ++i) {
            for (int j = 0; j < i; ++j) {
                Vt+=DirectAccess()[i].potentialField(DirectAccess()[j],time);
            }
        }
        return Vt;
    }
};


#endif //MD_OBJECTIVE_ARGONGASWORLD_H
