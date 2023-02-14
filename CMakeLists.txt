cmake_minimum_required(VERSION 3.20.0)
project(RPGEngine CXX)

find_package(SDL REQUIRED)

add_executable(main main.cpp)
target_link_libraries(main PRIVATE SDL::SDL)
target_include_directories(main PRIVATE ${CMAKE_CURRENT_BINARY_DIR})
