cmake_minimum_required(VERSION 3.0.0)
project(main VERSION 0.1.0)

include(CTest)
enable_testing()

include_directories(Headers)

aux_source_directory(. SRC)
add_executable(main ${SRC})

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
