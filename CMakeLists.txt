cmake_minimum_required(VERSION 3.16)
project(CppJson VERSION 1.0)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

file(GLOB HEADERS include/*.hpp)
file(GLOB SOURCES src/*.cpp)

add_library(CppJson SHARED ${SOURCES} ${HEADERS})
target_include_directories(CppJson PRIVATE include)

add_executable(test test.cpp)
target_link_libraries(test PRIVATE CppJson)
target_include_directories(test PRIVATE include)