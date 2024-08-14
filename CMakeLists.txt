cmake_minimum_required(VERSION 3.28)
project(algo_suite)


set(CMAKE_CXX_STANDARD 17)

add_library(algo_suite STATIC library.cpp
        fnv1.cpp
        fnv1.h
        )
