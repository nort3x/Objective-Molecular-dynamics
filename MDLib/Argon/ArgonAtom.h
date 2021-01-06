//
// Created by root on 1/6/21.
//

#ifndef MD_OBJECTIVE_ARGONATOM_H
#define MD_OBJECTIVE_ARGONATOM_H


#include "../PhysicalObjects/Lennard_Jones_potential.h"

struct ArgonAtom:public BodyWithLJP<double>{

    constexpr static const double ArgonMass = 1;
    constexpr static const double ArgonRad = 1;
    constexpr static const double eps = 1;
    constexpr static const double rc = 1;
    // more stuff
    ArgonAtom() : BodyWithLJP(eps) {

    }


};

#endif //MD_OBJECTIVE_ARGONATOM_H