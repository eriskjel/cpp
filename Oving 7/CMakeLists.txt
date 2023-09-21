cmake_minimum_required(VERSION 3.26)
project(Oving_7)

set(CMAKE_CXX_STANDARD 17)

add_executable(Fraction fraction/main.cpp
        fraction/Fraction.cpp
        fraction/Fraction.h)

add_executable(Set
        set/Set.cpp
        set/Set.h
        set/main.cpp)
