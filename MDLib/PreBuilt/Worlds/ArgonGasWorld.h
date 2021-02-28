//
// Created by root on 1/6/21.
//

#ifndef MD_OBJECTIVE_ARGONGASWORLD_H
#define MD_OBJECTIVE_ARGONGASWORLD_H

#include "../../PhysicalObjects/MultiBodyWorld.h"
#include "../Atoms/ArgonAtom.h"
#include "../../Enums/Integrators.h"
#include "../../MathObjects/Integrators/BasicIntegrator.h"
#include "../../MathObjects/Integrators/VerletIntegrator.h"

class ArgonGasWorld: public MultiBodyWorld<ArgonAtom,double>{

public:

    ArgonGasWorld(const unsigned int &numberOfBodies ,const double& BoxLength ) : MultiBodyWorld<ArgonAtom,double>(numberOfBodies){
        this->BoxLength = BoxLength;
    }

    double getTotalKineticEnergy(){
        double total_V2 =0;
        for (int i = 0; i < getSize(); ++i) {
            total_V2 += DirectAccess()[i].Velocity.getNormSqure();
        }
        return 0.5*ArgonAtom::mass*total_V2;
    };

    double getTotalPotentialEnergy(){
        double Vt=0;
        for (int i = 0; i < getSize(); ++i) {
            for (int j = 0; j < i; ++j) {
                Vt+=DirectAccess()[i].PotentialField(DirectAccess()[j], time);
            }
        }
        return Vt;
    }



};


#endif //MD_OBJECTIVE_ARGONGASWORLD_H
