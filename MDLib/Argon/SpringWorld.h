//
// Created by root on 1/14/21.
//

#ifndef MD_OBJECTIVE_TEST_SPRINGWORLD_H
#define MD_OBJECTIVE_TEST_SPRINGWORLD_H

#include "SpringAtoms.h"
#include "../PhysicalObjects/MultiBodyWorld.h"
#include "../MathObjects/VerletIntegrator.h"

class SpringWorld:public MultiBodyWorld<SpringAtom,double>{
    BasicIntegrator<double> *bs;
public:
    SpringWorld(const unsigned int &numberOfBodies, const double &boxLength) : MultiBodyWorld(numberOfBodies, boxLength) {
        BodyList[0].Position = {1,0,0};
        BodyList[0].Velocity = {+0.5,0,0};
        BodyList[1].Velocity = {-0.5,0.5,0.4};
        BodyList[1].Position = {-1,0,0};

        bs = new VerletIntegrator<SpringAtom,double>(this,0.001);
    }

    void ElapseInTime(const double & HowMuch, double dt){
        int n = std::abs(HowMuch/dt)+1;
        dt = HowMuch/n;
        for (int i = 0; i < n; ++i) {
            bs->timeElapse(dt);
            time += dt;
        }
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
