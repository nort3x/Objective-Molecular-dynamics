//
// Created by root on 1/6/21.
//

#ifndef MD_OBJECTIVE_ARGONGASWORLD_H
#define MD_OBJECTIVE_ARGONGASWORLD_H

#include "../PhysicalObjects/MultiBodyWorld.h"
#include "ArgonAtom.h"
#include "../Enums/Integrators.h"
#include "../MathObjects/BasicIntegrator.h"
#include "../MathObjects/VerletIntegrator.h"

class ArgonGasWorld: public MultiBodyWorld<ArgonAtom,double>{

private:
    BasicIntegrator<double> *basicIntegrator;
public:

    ArgonGasWorld(const unsigned int &numberOfBodies,double BoxLength) : MultiBodyWorld<ArgonAtom,double>(numberOfBodies, BoxLength){
        this->BoxLength = BoxLength;
    }

    ~ArgonGasWorld(){
        delete basicIntegrator;
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
    void setDynamics(const double & dt,Integrator integrator=Verlet_speed){
        switch (integrator) {
            case Verlet_speed:
                basicIntegrator = new VerletIntegrator<ArgonAtom,double>(this,dt);
                break;

        }
    }

    void ElapseInTime(const double & HowMuch, double dt){
        int n = std::abs(HowMuch/dt)+1;
        dt = HowMuch/n;
        for (int i = 0; i < n; ++i) {
            basicIntegrator->timeElapse(dt);
            time += dt;
        }
    }


};


#endif //MD_OBJECTIVE_ARGONGASWORLD_H
