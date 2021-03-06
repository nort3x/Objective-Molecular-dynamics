//
// Created by root on 1/14/21.
//

#ifndef MD_OBJECTIVE_TEST_SPRINGWORLD_H
#define MD_OBJECTIVE_TEST_SPRINGWORLD_H

#include "../Atoms/SpringAtoms.h"
#include "../../PhysicalObjects/MultiBodyWorld.h"
#include "../../MathObjects/Integrators/VerletIntegrator.h"

class SpringWorld:public MultiBodyWorld<SpringAtom,double>{
    BasicIntegrator<double> *bs;
public:
    SpringWorld(const unsigned int &numberOfBodies) : MultiBodyWorld(numberOfBodies) {

    }


    double getTotalKineticEnergy(){
        double total_V2 =0;
        for (int i = 0; i < getSize(); ++i) {
            total_V2 += BodyList[i].Velocity.getNormSqure();
        }
        return 0.5*total_V2;
    };

    double getTotalPotentialEnergy(){
        double Vt=0;
        for (int i = 0; i < getSize(); ++i) {
            for (int j = 0; j< getSize(); ++j) {
                Vt+=BodyList[i].PotentialField(BodyList[j], time);
            }
        }
        return Vt;
    }

};

#endif //MD_OBJECTIVE_TEST_SPRINGWORLD_H
