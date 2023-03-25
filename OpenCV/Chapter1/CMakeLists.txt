cmake_minimum_required(VERSION 3.0.0)

project(lige VERSION 1.0.0)

set(CMAKE_CXX_STANDARD 11)

# SET(CMAKE_BUILD_TYPE "Debug")
# SET(CMAKE_CXX_FLAGS_DEBUG "$ENV{CXXFLAGS} -O0 -Wall -g2 -ggdb")

set(OpenCV_DIR D:/mingwopencv/install/x64/mingw/lib)

find_package(OpenCV REQUIRED)

include_directories(${OpenCV_INCLUDE_DIRS})

aux_source_directory(. SRC)

add_executable(${CMAKE_PROJECT_NAME} ${SRC})

target_link_libraries(${CMAKE_PROJECT_NAME}  ${OpenCV_LIBS})