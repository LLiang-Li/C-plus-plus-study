cmake_minimum_required(VERSION 3.0.0)
project(lige VERSION 0.1.0)

set(CMAKE_CXX_STANDARD 17)

#include_directories(C:/Users/lenovo/Documents/boost_1_80_0)

# include(CTest)
# enable_testing()

set(BOOST_ROOT "C:/Users/lenovo/Documents/boost_1_80_0")
set(Boost_USE_STATIC_LIBS ON)    # 设置使用Boost静态库
set(Boost_ARCHITECTURE "-x64")    # 指定库架构为x64
find_package(Boost COMPONENTS regex REQUIRED)    # 查找Boost库
include_directories(${Boost_INCLUDE_DIRS}) 

message(Boost\ version: ${Boost_VERSION_STRING})
message(Boost\ include\ dir: ${Boost_INCLUDE_DIRS})
message(Boost\ library\ dir: ${Boost_LIBRARY_DIRS})

add_executable(lige main.cpp)

target_link_libraries(lige ${Boost_LIBRARIES})


# set(CPACK_PROJECT_NAME ${PROJECT_NAME})
# set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
# include(CPack)
