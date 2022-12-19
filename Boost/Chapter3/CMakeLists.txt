cmake_minimum_required(VERSION 3.0.0)
project(lige VERSION 0.1.0)

# include(CTest)
# enable_testing()

include_directories(C:/Users/lenovo/Documents/boost_1_80_0)

add_executable(lige main.cpp)

target_link_libraries(lige C:/Users/lenovo/Documents/boost_1_80_0/stage/lib)

# set(CPACK_PROJECT_NAME ${PROJECT_NAME})
# set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
# include(CPack)
