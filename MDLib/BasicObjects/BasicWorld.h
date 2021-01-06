//
// Created by root on 1/6/21.
//

/*

 a basic BasicWorld class which can inherted to build sophisticated Physical BasicBody with Sophisticated BodyTypes

 */

#ifndef MD_OBJECTIVE_BASICWORLD_H
#define MD_OBJECTIVE_BASICWORLD_H
#include <stdexcept>

template<typename ValType> class BasicWorld {
private:
    unsigned int size;
protected:
    ValType* BodyList;
public:
    explicit BasicWorld(const unsigned int& NumberOfBodies){
        size = NumberOfBodies;
        BodyList = new ValType[size];
    };

    ~BasicWorld(){
        delete [] BodyList;
    };

    // return the size of body can be used in for loops
    unsigned int getSize() const{
        return size;
    };

    // for fast computation, can easily kill the code, unsafe for regular use
    ValType* DirectAccess(){
        return BodyList;
    };


    // operators here we can have more natural feeling in selecting particles (also range safe)
    ValType& operator[](unsigned int pos){
        pos --;
        if(pos>=size || pos<0){
           throw std::out_of_range("[Invalid Selection Request]\n Valid range: 1 (first particle) to "+ std::to_string(size)+" (last particle)");
        }
        return BodyList[pos];
    }


};

#endif //MD_OBJECTIVE_BASICWORLD_H
