cmake_minimum_required(VERSION 3.17)
project(MD_Objective_Test)

set(CMAKE_CXX_STANDARD 14)

add_executable(MD_Objective
        main.cpp

        MDLib/MDLib.h

        MDLib/PreBuilt/Atoms/ArgonAtom.h
        MDLib/PreBuilt/Worlds/ArgonGasWorld.h

        MDLib/BasicObjects/BasicBody.h
        MDLib/MathObjects/ThreeDimValue.h
        MDLib/BasicObjects/BasicWorld.h

        MDLib/PhysicalObjects/BodyWithForceField.h
        MDLib/PhysicalObjects/MultiBodyWorld.h
        MDLib/PhysicalObjects/Lennard_Jones_potential.h

        MDLib/MathObjects/Integrators/BasicIntegrator.h
        MDLib/MathObjects/Integrators/VerletIntegrator.h
        MDLib/MathObjects/DistributionFunctions.h

        MDLib/MathObjects/Constraints/PeriodicBoundryRect.h)

add_executable(MD_Objective_test
        UnitTest/test.cpp
        MDLib/MDLib.h

        MDLib/PreBuilt/Atoms/ArgonAtom.h
        MDLib/PreBuilt/Worlds/ArgonGasWorld.h
        MDLib/PreBuilt/Atoms/SpringAtoms.h
        MDLib/PreBuilt/Worlds/SpringWorld.h

        MDLib/BasicObjects/BasicBody.h
        MDLib/MathObjects/ThreeDimValue.h
        MDLib/BasicObjects/BasicWorld.h

        MDLib/PhysicalObjects/BodyWithForceField.h
        MDLib/PhysicalObjects/MultiBodyWorld.h
        MDLib/PhysicalObjects/Lennard_Jones_potential.h

        MDLib/MathObjects/Integrators/BasicIntegrator.h
        MDLib/MathObjects/Integrators/VerletIntegrator.h
        MDLib/MathObjects/DistributionFunctions.h
        MDLib/MathObjects/Constraints/MultiConstraint.h


        )