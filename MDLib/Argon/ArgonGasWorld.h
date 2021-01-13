//
// Created by root on 1/6/21.
//

#ifndef MD_OBJECTIVE_ARGONGASWORLD_H
#define MD_OBJECTIVE_ARGONGASWORLD_H

#include "../PhysicalObjects/GasWorld.h"
#include "ArgonAtom.h"

class ArgonGasWorld: public GasWorld<ArgonAtom,double>{
public:

    explicit ArgonGasWorld(const unsigned int &numberOfBodies,double BoxLength) : GasWorld<ArgonAtom,double>(numberOfBodies,BoxLength){
        this->BoxLength = BoxLength;
    }

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
