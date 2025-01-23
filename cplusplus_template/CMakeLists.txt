cmake_minimum_required(VERSION 3.31.0)
project(lige VERSION 0.1.0 LANGUAGES C CXX)
set(CMAKE_CXX_STANDARD 20)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})

add_subdirectory(func_template)

add_subdirectory(class_template)

add_subdirectory(template_all_specific)

add_subdirectory(template_depart_file)

add_subdirectory(fold_expression)

add_subdirectory(template_decision_name)

add_executable(${PROJECT_NAME}  main.cpp)