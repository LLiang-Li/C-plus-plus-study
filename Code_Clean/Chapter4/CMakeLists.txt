cmake_minimum_required(VERSION 3.0.0)
project(lige VERSION 1.0.0)

aux_source_directory(. SRC)

add_executable(lige ${SRC})