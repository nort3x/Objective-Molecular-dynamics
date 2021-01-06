//
// Created by root on 1/6/21.
//

#ifndef MD_OBJECTIVE_LENNARD_JONES_POTENTIAL_H
#define MD_OBJECTIVE_LENNARD_JONES_POTENTIAL_H
#include "BodyWithForceField.h"
template <typename ValType> struct BodyWithLJP: public BodyWithForceField<ValType>{
    using BodyWithForceField<ValType>::forceField;
    using BodyWithForceField<ValType>::potentialField;
    using BodyWithForceField<ValType>::Position;

    explicit BodyWithLJP(ValType eps){
        forceField = [&](const BasicBody<double> &body, const double& time)->ThreeDimValue<double>{
            if(&body==this){
                return {0,0,0}; // no force on itself!
            } else{
                ThreeDimValue<double> rmrp = Position - body.Position;
                return (4*eps)*(6*std::pow(rmrp.getNormSqure(),-4) - 12*std::pow(rmrp.getNormSqure(),-7))*rmrp;
            }
        };

        potentialField = [&](const BasicBody<double> &body, const double& time)->double{
            if(&body==this){
                return 0; // no potential on itself!
            } else{
                ThreeDimValue<double> rmrp = Position - body.Position;
                return (4*eps)*(std::pow(rmrp.getNormSqure(),-6) - std::pow(rmrp.getNormSqure(),-3));
            }
        };
    }

};
#endif //MD_OBJECTIVE_LENNARD_JONES_POTENTIAL_H
