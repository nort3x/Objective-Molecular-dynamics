#include <iostream>
#include <fstream>

#include "MDLib/MDLib.h"
#include "MDLib/Argon/SpringWorld.h"
int main() {
    using namespace std;
//    ArgonGasWorld agw(300,10);
//    agw.RandomizePosition();
//    agw.RandomizeVelocity(20);
//    cout<<"started\n";
//    agw.setDynamics(0.01);
//    for (int i = 1; i < 10000; ++i) {
//        agw.ElapseInTime(1,0.01);
//        cout<<agw.getTotalKineticEnergy()+agw.getTotalPotentialEnergy()<<"\n";
//    }

    ofstream f;

    SpringWorld agw(2,1);
    agw.setDynamics(0.01,new VerletIntegrator<SpringAtom,double>(&agw,0.01),new RigidBoxConstraint<SpringAtom,double>(&agw));
    while (true){
        f.open("/root/Desktop/d.dat",ios_base::app);
        agw.ElapseInTime(0.01,0.01);
        system("sleep 0.01");
        f<<agw[1].Position<<"\t"<<agw[2].Position<<"\n";
        f.close();
    }


//    for (int i = 0; i < 10; ++i) {
//        agw.ElapseInTime(1,0.001);
//        cout<<agw.getTotalPotentialEnergy()+agw.getTotalKineticEnergy()<<"\n";
//    }


//ThreeDimValue<double> r = {1,0,0};
//    double t =0;
//    while (true){
//        f.open("/root/Desktop/d.dat",ios_base::app);
//        r = {cos(t),sin(t),t};
//        f<<r<<'\n';
//        t+=0.01;
//        system("sleep 0.01");
//        f.close();
//    }


    return 0;
}



