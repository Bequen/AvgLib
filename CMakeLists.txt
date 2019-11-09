cmake_minimum_required(VERSION 3.14.5)

project(AvgLib)

include_directories(lib)
set (CMAKE_CXX_STANDARD 20)

file(GLOB SRC
    "./lib/*.h"
    "./lib/*.cpp"
    "./lib/Math/*.h"
    "./lib/Math/*.cpp"
    "./lib/Random/*.h"
    "./lib/Random/*.cpp"
)

add_library(${PROJECT_NAME}
    ${SRC})

add_executable("${PROJECT_NAME}exe"
    main.cpp
    ${SRC})