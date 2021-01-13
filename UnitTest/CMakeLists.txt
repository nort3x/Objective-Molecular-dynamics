cmake_minimum_required(VERSION 3.17)
project(MD_Objective_Test)

set(CMAKE_CXX_STANDARD 14)

add_executable(MD_Objective_test
        test.cpp
        ../MDLib/BasicObjects/BasicBody.h
        ../MDLib/BasicObjects/ThreeDimValue.h
        ../MDLib/BasicObjects/BasicWorld.h
        ../MDLib/Argon/ArgonGasWorld.h
        ../MDLib/Argon/ArgonAtom.h
        ../MDLib/PhysicalObjects/BodyWithForceField.h
        ../MDLib/PhysicalObjects/Lennard_Jones_potential.h
        ../MDLib/MathObjects/DistributionFunctions.h
        ../MDLib/MDLib.h ../MDLib/MathObjects/BasicIntegrator.h ../MDLib/MathObjects/VerletIntegrator.h ../MDLib/PhysicalObjects/GasWorld.h)