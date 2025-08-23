cmake_minimum_required(VERSION 3.16)
project(CppJson VERSION 1.0)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


file(GLOB HEADERS include/*.hpp)
file(GLOB SOURCES src/*.cpp)

add_library(CppJson SHARED ${SOURCES} ${HEADERS})
target_include_directories(CppJson PRIVATE include)

# 针对所有目标启用调试符号
set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -g -O0")  # GCC/Clang：-g生成调试符号，-O0关闭优化
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -O2")  # 仅Release模式启用优化

add_executable(test test.cpp)
target_link_libraries(test PRIVATE CppJson)
target_include_directories(test PRIVATE include)