//
// Created by root on 1/6/21.
//

#ifndef MD_OBJECTIVE_ARGONATOM_H
#define MD_OBJECTIVE_ARGONATOM_H


#include "../../PhysicalObjects/Lennard_Jones_potential.h"


struct ArgonAtom:public BodyWithLJP<double>{

    constexpr static const double mass = 1;
    constexpr static const double Rad = 1;
    constexpr static const double eps = 1;
    constexpr static const double rc = 1;
    // more stuff
    ArgonAtom() : BodyWithLJP(eps,1) {

    }
    ArgonAtom(const ArgonAtom& atm):BodyWithLJP<double>(atm){

    }


};

#endif //MD_OBJECTIVE_ARGONATOM_H
