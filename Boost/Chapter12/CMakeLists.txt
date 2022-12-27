cmake_minimum_required(VERSION 3.0.0)
project(lige VERSION 0.1.0)

set(CMAKE_CXX_STANDARD 17)

include_directories(C:/Users/lenovo/Documents/boost_1_80_0)
link_directories(C:/Users/lenovo/Documents/boost_1_80_0/stage/lib/)

add_executable(lige main.cpp)

# target_link_libraries(lige "boost_program_options-mgw8-mt-x64-1_80.a")
target_link_libraries(lige "boost_chrono-mgw8-mt-d-x64-1_80")
target_link_libraries(lige "boost_thread-mgw8-mt-d-x64-1_80")
target_link_libraries(lige "ws2_32")
