#include <iostream>
#include <iomanip>
#include "MDLib/BasicObjects/BasicWorld.h"
#include "MDLib/Argon/ArgonGasWorld.h"
int main() {
    using namespace std;

   ArgonGasWorld ag = ArgonGasWorld(10,12);
   ag.RandomizePosition();
   ag.RandomizeVelocity(1);
    return 0;
}



