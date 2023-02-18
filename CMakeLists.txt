cmake_minimum_required(VERSION 3.20.0)
project(RPGEngine CXX)

if(CMAKE_CURRENT_SOURCE_DIR STREQUAL CMAKE_CURRENT_BINARY_DIR)
	message(FATAL_ERROR "Create a build directory outside of the source tree and run \"cmake -S ${CMAKE_SOURCE_DIR} -B .\" from there.")
endif()

find_package(SDL2 CONFIG REQUIRED)

add_executable(RPGEngine main.cpp)
target_link_libraries(RPGEngine PRIVATE
	SDL2::SDL2
	SDL2::SDL2main
	)
