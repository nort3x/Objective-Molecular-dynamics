# Objective-Molecular-dynamics
an objective approach to molecular dynamics (Argon Gas simulation)


OOP practice in MolecularDynamics - partially compeleted - any pull will be accpeted \

- check the video https://github.com/nort3x/Objective-Molecular-dynamics/blob/master/Screencast%202021-06-12%2003:08:49.mp4

```cpp
#include <iostream>
#include <fstream>
#include <iomanip>

#include "MDLib/MDLib.h"

int main() {
    using namespace std;

    ArgonGasWorld agw(5,10);  // a free space containing 200 argon atoms
    auto integrator = new VerletIntegrator<ArgonAtom,double>(&agw,0.0000001); // making an integrator
    //auto constraint = new RigidBoxConstraint<ArgonAtom,double>(10);  // making a Constraint
    auto constraint = new PeriodicBoundaryConditionBox<ArgonAtom,double>(10);
    //auto constraint  = new FreeSpace<ArgonAtom>();
    agw.RandomizePosition();
    agw.RandomizeVelocity(100);

    cout<<"Intited....\n";

    fstream  golabi; // golabi means peach :D (please let it be like this in memory of my dear professor)
    golabi.open("/root/Desktop/d.dat",ios::out);
    agw.setDynamics(0.01,integrator,constraint);
    for (int i = 1; i < 1000000; ++i) {
        agw.ElapseInTime(0.1,0.0001);
        //cout<<agw.getTotalKineticEnergy()+agw.getTotalPotentialEnergy()<<"\n";
        golabi<<std::setprecision(15)<<agw.getTime()<<"\t"<<agw.getTotalKineticEnergy()+agw.getTotalPotentialEnergy()<<endl;
        //golabi<<agw[1].Position<<endl;
    }

    return 0;
}
```
