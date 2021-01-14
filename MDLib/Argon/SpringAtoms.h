//
// Created by root on 1/14/21.
//

#ifndef MD_OBJECTIVE_TEST_SPRINGATOMS_H
#define MD_OBJECTIVE_TEST_SPRINGATOMS_H
#include "../PhysicalObjects/BodyWithForceField.h"
#include "../BasicObjects/ThreeDimValue.h"

class SpringAtom:public BodyWithForceField<double>{

public:
    double k = 1;
    SpringAtom(){
        forceField = [&](const BasicBody<double>& body,const double &time)->ThreeDimValue<double>{
            if(&body == this){
                return {0,0,0};
            }
            else{
                ThreeDimValue<double> rp = (Position - body.Position);
                return k*rp;
            }
        };

        potentialField = [&](const BasicBody<double>& body,const double &time)->double{
            if(&body == this){
                return 0;
            }
            else{
                ThreeDimValue<double> rp = (Position - body.Position);
                return 0.5*k*rp.getNormSqure();
            }
        };
    }

};
#endif //MD_OBJECTIVE_TEST_SPRINGATOMS_H
