#include <iostream>
#include "MDLib/MDLib.h"
#include "MDLib/Argon/SpringWorld.h"
int main() {
    using namespace std;
//    ArgonGasWorld agw(2,10);
//    agw.RandomizePosition();
//    agw.RandomizeVelocity(20);
//    agw.setDynamics(0.01);
//    for (int i = 1; i < 10; ++i) {
//        agw.ElapseInTime(1,0.01);
//        cout<<agw.getTotalKineticEnergy()+agw.getTotalPotentialEnergy()<<"\n";
//    }


    SpringWorld agw(2,10);
    for (int i = 1; i < 10; ++i) {
        agw.ElapseInTime(1,0.01);
        cout<<agw.getTotalKineticEnergy()+agw.getTotalPotentialEnergy()<<"\n";
    }
    return 0;
}



