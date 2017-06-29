cmake_minimum_required(VERSION 3.7)
project(ex4)

set(CMAKE_CXX_STANDARD 11)
set(COVERAGE_COMPILE_FLAGS "-Wall -pedantic-errors -Werror")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${COVERAGE_COMPILE_FLAGS}")

set(SOURCE_FILES
        #Enigma.cpp
        #EscapeRoomWrapper.cpp
        #EscapeRoomWrapper.h
        #Enigma.h
        #ScaryRoom.cpp
        #ScaryRoom.h
        #KidsRoom.cpp
        #KidsRoom.h
        #Company.h
        #Company.cpp
        #EscapeRoom.h
        #EscapeRoom.c
        #mtmtest.h
        #tests/Company_tests.cpp
        #main.cpp
        list.h
        tests/list_tests.cpp)
add_executable(ex4 ${SOURCE_FILES})