cmake_minimum_required(VERSION 3.0.0)
project(lige VERSION 0.1.0)

include_directories(C:/Users/lenovo/Documents/protobuf_3_21_12/src)
link_directories(C:/Users/lenovo/Documents/PROTOBUF)

add_subdirectory(proto)

 include_directories(${PROTO_GEN_CXX_INCLUDE_DIRS})

aux_source_directory(. SRC)
add_executable(lige ${SRC})

target_link_libraries(lige "libprotobuf.a")
target_link_libraries(lige "proto_gen_cxx")