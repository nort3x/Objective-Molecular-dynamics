//
// Created by root on 1/15/21.
//

#ifndef MD_OBJECTIVE_TEST_CONSTRAINT_H
#define MD_OBJECTIVE_TEST_CONSTRAINT_H
template <typename T>
class BasicConstraint{
public:
    virtual void check(T& body)=0;
    virtual ~BasicConstraint()=default;


};
#endif //MD_OBJECTIVE_TEST_CONSTRAINT_H
