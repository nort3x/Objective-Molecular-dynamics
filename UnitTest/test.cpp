#include <iostream>
#include "../MDLib/MDLib.h"

const char* Check(const bool &b ){
    if(b){
        return "Works";
    } else{
        return "Failed!";
    }

}

template <typename T>
void happDestructor(T t){

}


bool ThreeDimValue_test(){
    ThreeDimValue<double> vec = {3,4,0};
    bool p =  (vec.getNormSqure() == 25)&&(vec.getNorm() == 5)
    &&(vec.getNormalize().x1 == 0.2*vec.x1)
    &&(vec.getDotProduct({1,1,1}) == 7)
    &&(vec.operator-({1,0,0}).x1 == 2);
    vec+={1,0,0};
    return p&&(vec.x1 ==4);
}


bool BasicWorld_test(){
    BasicWorld<double> bw_empty,bw_filled(10),bw_copied(bw_filled);
    bw_filled[2] = 12;
    bool c1= (bw_copied[2]==0);
    happDestructor(bw_copied);
    happDestructor(bw_filled);
    return c1;
}

bool BodyWithForceField_test(){
    BodyWithForceField<double> bwf;
    BasicBody<double> body = {1,1,1};
    bwf.forceField = [&bwf](const BasicBody<double>& body,const double& t)->ThreeDimValue<double>{
        if(&bwf==&body){
            return {0,0,0};
        } else{
            return {1,1,1};
        }
    };

    bool c1 =  (bwf.forceField(bwf,0).x1 == 0)&&((bwf.forceField(body,0).x1 == 1));
    return c1;
}

bool BodyWithLJP_test(){
    BodyWithLJP<double> b1(12),b2(12);
    b1.Position = {1,1,1};
    b2.Position = {1.1,1,1};
    BodyWithLJP<double> b3(b1);
    bool c1=  (b1.forceField(b1,0).x1==0)&&(b1.forceField(b2,0).x1!=0);
    bool c3=  (b3.forceField(b3,0).x1 ==0);
    double x1 =  b3.forceField(b2,0).x1;
    double x2 = b1.forceField(b2,0).x1;
    bool c2 = (b3.forceField(b1,0).x1 == 0);
    bool c4 = (b1.forceField(b3,0).x1 == 0);
    bool c5=  (x1==x2);
    return c1&&c3&&c5&&c2&&!c4;
}
bool ArgonAtomTest(){
    ArgonAtom a1;
    a1.Position = {1,1,1};
    ArgonAtom a2;
    ArgonAtom a3 = a1;
    bool c1 = a1.forceField(a2,0).x1 == a1.forceField(a2,0).x1;
    return c1;
}

bool GasWorld_test(){
    GasWorld<ArgonAtom,double> gw(10,10);
    gw.RandomizePosition();
    return true;
}

bool ArgonGasWorld_test(){
    ArgonGasWorld ag(10,12);
    ag.RandomizeVelocity(1);
    ag.RandomizePosition();
    ag.updateForce();
   double x =  ag.getTotalPotentialEnergy();
    double x2 = ag.getTotalKineticEnergy();
    return true;
}


int main(){
    using namespace std;

    cout<< "ThreeDim: "<<Check(ThreeDimValue_test())<<"\n";
    cout<< "BasicWorld: "<<Check(BasicWorld_test())<<"\n";
    cout<< "BodyWithForce: "<<Check(BodyWithForceField_test())<<"\n";
    cout<< "BodyWithLJP: "<<Check(BodyWithLJP_test())<<"\n";
    cout<< "ArgonAtom: "<<Check(ArgonAtomTest())<<"\n";
    cout<< "GasWorld: "<<Check(GasWorld_test())<<"\n";
    cout<< "ArgonGasWorld: "<<Check(ArgonGasWorld_test())<<"\n";


    return 0;
}