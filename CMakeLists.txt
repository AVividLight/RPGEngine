cmake_minimum_required(VERSION 3.24.0)
project(RPGEngine CXX)

if(CMAKE_CURRENT_SOURCE_DIR STREQUAL CMAKE_CURRENT_BINARY_DIR)
	message(FATAL_ERROR "Create a build directory outside of the source tree and run \"cmake -S ${CMAKE_SOURCE_DIR} -B .\" from there.")
endif()

include(FetchContent)
FetchContent_Declare(external-SDL
	GIT_REPOSITORY	https://github.com/libsdl-org/SDL.git
	GIT_TAG			release-2.26.4
	OVERRIDE_FIND_PACKAGE
	)
FetchContent_MakeAvailable(external-SDL)
find_package(external-SDL)

add_executable(RPGEngine main.cpp)

target_link_libraries(RPGEngine PRIVATE
	SDL2::SDL2
	SDL2::SDL2main
	)

add_custom_command(TARGET RPGEngine POST_BUILD
	COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_RUNTIME_DLLS:RPGEngine> $<TARGET_FILE_DIR:RPGEngine>
	COMMAND_EXPAND_LISTS
	)
