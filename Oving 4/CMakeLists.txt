cmake_minimum_required(VERSION 3.26)
project(Oving_4)

set(CMAKE_CXX_STANDARD 17)

add_executable(Oving_4-1 Task1.cpp)

INCLUDE(FindPkgConfig)

pkg_check_modules(GTKMM gtkmm-3.0 REQUIRED)
include_directories(${GTKMM_INCLUDE_DIRS})
link_directories(${GTKMM_LIBRARY_DIRS})


add_executable(Oving_4-2
        Task2.cpp
        Task2.h)
target_link_libraries(Oving_4-2 ${GTKMM_LIBRARIES})
