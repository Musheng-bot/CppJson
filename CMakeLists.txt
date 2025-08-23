cmake_minimum_required(VERSION 3.16)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

file(GLOB HEADERS include/*.hpp)
file(GLOB SOURCES src/*.cpp)

add_library(CppJson SHARED ${SOURCES} ${HEADERS})
target_include_directories(CppJson PRIVATE include)