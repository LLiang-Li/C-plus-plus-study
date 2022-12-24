cmake_minimum_required(VERSION 3.0.0)
project(lige VERSION 0.1.0)

set(CMAKE_CXX_STANDARD 17)

set(BOOST_ROOT "C:/Users/lenovo/Documents/boost_1_80_0")    # 指定Boost库的根目录
set(Boost_USE_STATIC_LIBS ON)    # 设置使用Boost静态库
set(Boost_ARCHITECTURE "-x64")    # 指定库架构为x64
find_package(Boost COMPONENTS filesystem program_options REQUIRED)    # 查找Boost库
include_directories(${Boost_INCLUDE_DIRS})  

MESSAGE(STATUS "Boost_INCLUDE_DIRS = ${Boost_INCLUDE_DIRS}")
MESSAGE(STATUS "Boost_LIBRARIES = ${Boost_LIBRARIES}")
MESSAGE(STATUS "Boost_LIB_VERSION = ${Boost_LIB_VERSION}")

add_executable(lige main.cpp)
target_link_libraries(lige ${Boost_LIBRARIES})    # 链接Boost库