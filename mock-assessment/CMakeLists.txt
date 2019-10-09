cmake_minimum_required(VERSION 3.15)
project(cranfield_computationalMethods_labs)

set(CMAKE_CXX_STANDARD 17)

include_directories(..)
include_directories(.)

add_executable(cranfield_computationalMethods_labs
        accuracy.cpp
        accuracy.h
        aliases.h
        main.cpp
        scheme.cpp
        scheme.h
        solution.cpp
        solution.h
        utilities.cpp
        utilities.h
        solutiontype.h
        schemetype.h)
