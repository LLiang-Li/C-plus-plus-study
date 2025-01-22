cmake_minimum_required(VERSION 3.31.0)
project(lige VERSION 0.1.0 LANGUAGES C CXX)
set(CMAKE_CXX_STANDARD 20)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})

add_subdirectory(func_template)

add_subdirectory(class_template)

add_executable(${PROJECT_NAME}  main.cpp)