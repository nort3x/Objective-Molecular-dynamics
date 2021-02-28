//
// Created by root on 1/6/21.
//

#ifndef MD_OBJECTIVE_LENNARD_JONES_POTENTIAL_H
#define MD_OBJECTIVE_LENNARD_JONES_POTENTIAL_H
#include "BodyWithForceField.h"
template <typename ValType> struct BodyWithLJP: BodyWithForceField<ValType>{

    using BodyWithForceField<ValType>::AcclerationField;
    using BodyWithForceField<ValType>::PotentialField;
    using BodyWithForceField<ValType>::Position;
    ValType eps;
    ValType sigma;
    ValType sigma_6;
    ValType near_cutoff,far_cutoff;
    ValType near_cutoffSq,far_cutoffSq;

    explicit BodyWithLJP(ValType eps1,ValType sigma,ValType n_cutoff=0.95,ValType f_cutoff=10){
        this->eps = eps1;
        this->sigma = sigma;
        this->near_cutoff = n_cutoff;
        this->far_cutoff = f_cutoff;
        this->near_cutoffSq = std::pow(near_cutoff,2);
        this->far_cutoffSq = std::pow(far_cutoff,2);

        sigma_6= std::pow(sigma,6);
        AcclerationField = [&](const BasicBody<double> &body, const double& time)->ThreeDimValue<double>{
            if(&body==this){
                return {0,0,0}; // no force on itself!
            } else{
                ThreeDimValue<double> rmrp = Position - body.Position; // grifiths style big R
                ValType check = rmrp.getNormSqure();
                if( check<=near_cutoffSq || check >= far_cutoffSq){ 
                    return {0,0,0};
                }else{
                    ThreeDimValue<double> ans = (24*eps*sigma_6)*( sigma_6*2*std::pow(check,-7)-std::pow(check,-4) )*rmrp;
                    return ans;
                }
            }
        };

        PotentialField = [&](const BasicBody<double> &body, const double& time)->double{
            if(&body==this){
                return 0; // no potential on itself!
            } else{

                ThreeDimValue<double> rmrp = Position - body.Position;

                ValType check = rmrp.getNormSqure();
                if(check<=near_cutoffSq ){//|| check >= far_cutoffSq){
                    return (4*eps*sigma_6)*(sigma_6*std::pow(near_cutoffSq,-6) - std::pow(near_cutoffSq,-3));
                    //return 0;
                }else if(check >= far_cutoffSq){
                    return 0;
                }
                else{
                    return  (4*eps*sigma_6)*(sigma_6*std::pow(check,-6) - std::pow(check,-3));;
                }

            }
        };
    }

    BodyWithLJP(const BodyWithLJP<ValType> &b){
        this->eps = b.eps;
        this->sigma = b.sigma;
        this->sigma_6 = b.sigma_6;
        this->near_cutoff = b.near_cutoff;
        this->far_cutoff = b.far_cutoff;
        this->Velocity = b.Velocity;
        this->Position = b.Position;
        this->Acceleration = b.Acceleration;

        AcclerationField = [&](const BasicBody<double> &body, const double& time)->ThreeDimValue<double>{
            if(&body==this || &body == &b){
                return {0,0,0}; // no force on itself!
            } else{
                ThreeDimValue<double> rmrp = Position - body.Position; // grifiths style big R
                ValType check = rmrp.getNormSqure();
                if(check<=near_cutoffSq || check >= far_cutoffSq){
                    return {0,0,0};
                }else{
                    ThreeDimValue<double> ans = (24*eps*sigma_6)*( sigma_6*2*std::pow(rmrp.getNormSqure(),-7)-std::pow(rmrp.getNormSqure(),-4) )*rmrp;
                    return ans;
                }
            }
        };

        PotentialField = [&](const BasicBody<double> &body, const double& time)->double{
            if(&body==this || &body == &b){
                return 0; // no potential on itself!
            } else{
                ThreeDimValue<double> rmrp = Position - body.Position; // grifiths style big R
                ValType check = rmrp.getNormSqure();
                if(check<=near_cutoffSq){
                    return (4*eps*sigma_6)*(sigma_6*std::pow(near_cutoffSq,-6) - std::pow(near_cutoffSq,-3));
                    //return 0;
                }else if(check >= far_cutoffSq){
                    return 0;
                }
                else{
                    return  (4*eps*sigma_6)*(sigma_6*std::pow(rmrp.getNormSqure(),-6) - std::pow(rmrp.getNormSqure(),-3));;
                }
            }
        };
    }

};
#endif //MD_OBJECTIVE_LENNARD_JONES_POTENTIAL_H
