cmake_minimum_required(VERSION 3.17)
project(MD_Objective)

set(CMAKE_CXX_STANDARD 14)

add_executable(MD_Objective
        main.cpp
        MDLib/BasicObjects/BasicBody.h
        MDLib/BasicObjects/ThreeDimValue.h
        MDLib/BasicObjects/BasicWorld.h
        MDLib/Argon/ArgonGasWorld.h
        MDLib/Argon/ArgonAtom.h
        MDLib/PhysicalObjects/BodyWithForceField.h
        MDLib/PhysicalObjects/Lennard_Jones_potential.h
        MDLib/PhysicalObjects/DistributionFunctions.h)