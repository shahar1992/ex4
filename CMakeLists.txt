cmake_minimum_required(VERSION 3.7)
project(ex4)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
        Enigma.cpp
        mtmtest.h
        tests/Enigma_tests.cpp)
add_executable(ex4 ${SOURCE_FILES})