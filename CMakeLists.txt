cmake_minimum_required(VERSION 3.27)
project(LeoORM)

set(CMAKE_CXX_STANDARD 11)

add_executable(LeoORM
        main.cpp
        Visitor.cpp
        Visitor.hpp
)
