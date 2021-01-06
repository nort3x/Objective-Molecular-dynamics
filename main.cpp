#include <iostream>
#include <iomanip>
#include "MDLib/Argon//ArgonGasWorld.h"
int main() {

    for (int i = 0; i < 10; ++i) {
        ArgonGasWorld agw(100,std::pow(10,-i));
        agw.RandomizePosition(0);
        std::cout<<std::setprecision(10)<<agw.getTotalPotentialEnergy()<<"\n";
    }
    return 0;
}
