cmake_minimum_required(VERSION 3.16)
project(CppJson VERSION 1.0)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


# file(GLOB HEADERS include/*.hpp)
file(GLOB SOURCES src/*.cpp)

add_library(CppJson SHARED ${SOURCES})
target_include_directories(
    CppJson 
PRIVATE 
    src/internal
PUBLIC
    include    
)

# set(INSTALL_PREFIX_PATH "/home/musheng")

add_executable(test test.cpp)
target_link_libraries(test PRIVATE CppJson)
target_include_directories(
    test 
PRIVATE 
    src/internal
PUBLIC
    include
)