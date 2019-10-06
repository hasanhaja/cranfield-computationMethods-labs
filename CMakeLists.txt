cmake_minimum_required(VERSION 3.15)
project(cranfield_computationalMethods_labs)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)
#[[include_directories(lab1)]]
include_directories(mock-assessment)

add_executable(cranfield_computationalMethods_labs
        #[[lab1/lab1.cpp]]
        mock-assessment/accuracy.cpp
        mock-assessment/accuracy.h
        mock-assessment/aliases.h
        mock-assessment/main.cpp
        mock-assessment/scheme.cpp
        mock-assessment/scheme.h
        mock-assessment/solution.cpp
        mock-assessment/solution.h
        mock-assessment/utilities.cpp
        mock-assessment/utilities.h
        #[[README.md]])
