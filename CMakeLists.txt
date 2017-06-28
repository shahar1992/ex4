cmake_minimum_required(VERSION 3.7)
project(ex4)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
        Enigma.cpp
        EscapeRoomWrapper.cpp
        EscapeRoomWrapper.h
        Enigma.h
        ScaryRoom.cpp
        ScaryRoom.h
        KidsRoom.cpp
        KidsRoom.h
        Company.h
        Company.cpp
        EscapeRoom.h
        EscapeRoom.c
        mtmtest.h
        tests/ScaryRoom_tests.cpp)
add_executable(ex4 ${SOURCE_FILES})