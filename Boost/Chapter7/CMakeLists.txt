cmake_minimum_required(VERSION 3.0.0)
project(lige VERSION 0.1.0)

set(CMAKE_CXX_STANDARD 17)

include_directories(C:/Users/lenovo/Documents/boost_1_80_0)

add_executable(lige main.cpp)
# add_executable(lige1 main1.cpp)

target_link_libraries(lige C:/Users/lenovo/Documents/boost_1_80_0/stage/lib)