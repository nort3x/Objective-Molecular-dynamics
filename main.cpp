#include <iostream>
#include <fstream>

#include "MDLib/MDLib.h"
#include "MDLib/PreBuilt/Worlds/SpringWorld.h"
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

    auto* co = new MultiConstraint<SpringAtom>();

    SpringWorld agw(3);
    //agw.RandomizeVelocity(3);
    agw[1].Velocity = {1,0,0};
    co->Append(new RigidBoxConstraint<SpringAtom,double>(5));
//    co->Append([](SpringAtom& s){
//       if(s.Position.getDotProduct({1,1,1})>0){
//           s.Velocity += {1,1,1};
//       }
//    });
co->Append(new PeriodicBoundaryConditionBox<SpringAtom,double>(4));
    agw.setDynamics(0.01,new VerletIntegrator<SpringAtom,double>(&agw,0.01),co);
    while (true){
        f.open("/root/Desktop/d.dat",ios_base::app);
        agw.ElapseInTime(0.01,0.01);
        system("sleep 0.01");
        f<<agw[1].Position<<"\t"<<agw[3].Position<<"\t"<<agw[2].Position<<"\n";
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



