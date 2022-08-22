cmake_minimum_required(VERSION 3.23)

project(BeginningCpp)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17 -O3")

include_directories(include)
set(SOURCES src/main.cpp)
file(GLOB SOURCES "src/*.cpp")

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
add_executable(BeginningCpp ${SOURCES})
