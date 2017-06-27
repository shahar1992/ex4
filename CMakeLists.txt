cmake_minimum_required(VERSION 3.7)
project(ex4)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
        EscapeRoomWrapper.cpp
        EscapeRoom.c
        tests/EscapeRoomWrapper_test.cpp ScaryRoom.cpp ScaryRoom.h KidsRoom.cpp KidsRoom.h)
add_executable(ex4 ${SOURCE_FILES})