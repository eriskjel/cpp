cmake_minimum_required(VERSION 3.26)
project(Oving_3)

set(CMAKE_CXX_STANDARD 17)

add_executable(Oving_3 main.cpp
        Circle.cpp
        Circle.h
        )

add_executable(CommodityClient
        CommodityClient.cpp
        Commodity.cpp
        Commodity.h
)

add_executable(Streng
        Streng.cpp
)




