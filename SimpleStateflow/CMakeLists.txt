cmake_minimum_required(VERSION 3.6.0)
project(lige VERSION 0.1.0 LANGUAGES C)

include(CTest)
enable_testing()

aux_source_directory(. SRC)
add_executable(lige ${SRC})

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
