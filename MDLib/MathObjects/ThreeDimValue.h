//
// Created by -H on 1/6/21.
//
/*
   i Created this struct to unify a value type to be used in vectoral dynamics
 */


#ifndef MD_OBJECTIVE_THREEDIMVALUE_H
#define MD_OBJECTIVE_THREEDIMVALUE_H
#include <cmath>
#include <ios>

template<typename ValType> struct ThreeDimValue{

    ValType x1;
    ValType x2;
    ValType x3;

    // vector multiplication by const (tricky because it should be even right multiplicity)
    template<typename K> friend ThreeDimValue<ValType> operator*(const K & c ,ThreeDimValue<ValType> v ){
        v.x1 *= c;
        v.x2 *= c;
        v.x3 *= c;
        return v;
    }

    // vector addition
    ThreeDimValue<ValType> operator+(ThreeDimValue<ValType> rightVec){
        rightVec.x1 += x1;
        rightVec.x2 += x2;
        rightVec.x3 += x3;
        return rightVec;
    }

    void operator+=(const ThreeDimValue<ValType> &rightvec){
        x1 += rightvec.x1;
        x2 += rightvec.x2;
        x3 += rightvec.x3;
    }

    // vector subtraction
    ThreeDimValue<ValType> operator-(ThreeDimValue<ValType> rightVec){
        return   operator+((-1)*rightVec);
    }


    // for being printable by cout
    friend std::ostream& operator<<(std::ostream& o, const ThreeDimValue<ValType> v){
        o<<v.x1<<"\t"<<v.x2<<"\t"<<v.x3;
        return o;
    }

    ThreeDimValue<ValType> getNormalize(){
        ThreeDimValue<ValType> ans = *this;
        return (1/getNorm())*ans;
    }

    ValType getDotProduct(const ThreeDimValue<ValType> v) const{
        return x1*(v.x1) + x2*(v.x2) + x3*(v.x3);
    }

    //
    ValType getNorm()const{
        return std::sqrt(getNormSqure());
    }

    // sometimes its good practise to use Square of norm for fast computation
    ValType getNormSqure()const{
        return (std::pow(x1,2) + std::pow(x2,2) + std::pow(x3,2));
    }

};




#endif //MD_OBJECTIVE_THREEDIMVALUE_H
