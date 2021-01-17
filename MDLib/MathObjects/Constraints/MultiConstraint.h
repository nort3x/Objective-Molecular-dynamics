//
// Created by root on 1/17/21.
//

#ifndef MD_OBJECTIVE_TEST_MULTICONSTRAINT_H
#define MD_OBJECTIVE_TEST_MULTICONSTRAINT_H

#include "BasicConstraint.h"
#include "vector"
#include "functional"

template <typename T>
class MultiConstraint:public BasicConstraint<T>{
private:
    std::vector<std::function<void(T& )>> listOfConstraints;
    std::vector<BasicConstraint<T>*> constraints;
public:
    MultiConstraint(){

    }
    ~MultiConstraint(){
        for(auto &junk:constraints)
            delete junk;
    }
    // first In first apply
    void Append(const std::function<void(T& )> &constraint){
        listOfConstraints.push_back(constraint);
    }
    void Append(BasicConstraint<T>* constraint){
        constraints.push_back(constraint);
        std::function<void(T&body)> s = [constraint](T& body){constraint->check(body);};
        listOfConstraints.push_back(s);
    }

    void check(T &body) override {
        for(auto& v:listOfConstraints)
            v(body);
    }


};
#endif //MD_OBJECTIVE_TEST_MULTICONSTRAINT_H
