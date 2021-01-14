cmake_minimum_required(VERSION 3.17)
project(MD_Objective_Test)

set(CMAKE_CXX_STANDARD 14)

add_executable(MD_Objective
        main.cpp

        MDLib/MDLib.h

        MDLib/Argon/ArgonAtom.h
        MDLib/Argon/ArgonGasWorld.h

        MDLib/BasicObjects/BasicBody.h
        MDLib/BasicObjects/ThreeDimValue.h
        MDLib/BasicObjects/BasicWorld.h

        MDLib/PhysicalObjects/BodyWithForceField.h
        MDLib/PhysicalObjects/MultiBodyWorld.h
        MDLib/PhysicalObjects/Lennard_Jones_potential.h

        MDLib/MathObjects/BasicIntegrator.h
        MDLib/MathObjects/VerletIntegrator.h
        MDLib/MathObjects/DistributionFunctions.h

        )

add_executable(MD_Objective_test
        UnitTest/test.cpp
        MDLib/MDLib.h

        MDLib/Argon/ArgonAtom.h
        MDLib/Argon/ArgonGasWorld.h
        MDLib/Argon/SpringAtoms.h
        MDLib/Argon/SpringWorld.h

        MDLib/BasicObjects/BasicBody.h
        MDLib/BasicObjects/ThreeDimValue.h
        MDLib/BasicObjects/BasicWorld.h

        MDLib/PhysicalObjects/BodyWithForceField.h
        MDLib/PhysicalObjects/MultiBodyWorld.h
        MDLib/PhysicalObjects/Lennard_Jones_potential.h

        MDLib/MathObjects/BasicIntegrator.h
        MDLib/MathObjects/VerletIntegrator.h
        MDLib/MathObjects/DistributionFunctions.h
        )