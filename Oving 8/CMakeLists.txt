cmake_minimum_required(VERSION 3.26)
project(Oving_8)

set(CMAKE_CXX_STANDARD 17)

#set -Wall -Wextra
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17 -Wall -Wextra")

add_executable(Oving_8-1
        equal_functions.cpp
)

add_executable(Oving_8-2
        pair_template.cpp
)
