//
// Created by root on 1/6/21.
//

#ifndef MD_OBJECTIVE_DISTRIBUTIONFUNCTIONS_H
#define MD_OBJECTIVE_DISTRIBUTIONFUNCTIONS_H

#include <functional>
#include <cmath>
#include "../BasicObjects/ThreeDimValue.h"

enum DistributionFunction{
    Boltzmann,
    uniform,
};

template<typename T> ThreeDimValue<T> RandomNormalizedVector(){
    ThreeDimValue<T> ans = {1*(double)std::rand()/RAND_MAX,
                1*(double)std::rand()/RAND_MAX,
                1*(double)std::rand()/RAND_MAX };
    return ans.getNormalize();
}

template<typename T>class BoltzmannDist{
public:
    std::function<T(T)> BoltzmannFunction;
    const T Bconst = 1;

    explicit BoltzmannDist(T mass,T temp){
        BoltzmannFunction = [=](T vel)->T{
            T kt = temp*Bconst;
            return std::pow((mass/(2*M_PI*kt)),(float)3/2) * std::exp(-mass*std::pow(vel,2)/(2*kt));
        };
    }

    unsigned int getFraction(T lowerBand,T upperBand,T resolution){ // not implemented yet
        return 0;
    }

};

#endif //MD_OBJECTIVE_DISTRIBUTIONFUNCTIONS_H
