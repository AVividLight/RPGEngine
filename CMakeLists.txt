cmake_minimum_required(VERSION 3.21.0)
project(RPGEngine CXX)

if(CMAKE_CURRENT_SOURCE_DIR STREQUAL CMAKE_CURRENT_BINARY_DIR)
	message(FATAL_ERROR "Create a build directory outside of the source tree and run \"cmake -S ${CMAKE_SOURCE_DIR} -B .\" from there.")
endif()

include(FetchContent)
FetchContent_Declare(external-Freetype
	GIT_REPOSITORY	https://github.com/freetype/freetype.git
	GIT_TAG			VER-2-13-0
	)
FetchContent_MakeAvailable(external-Freetype)
set(FREETYPE_LIBRARY ${freetype_SOURCE_DIR}/src)
set(FREETYPE_INCLUDE_DIRS ${freetype_SOURCE_DIR}/include)

include(FetchContent)
FetchContent_Declare(external-RmlUi
	GIT_REPOSITORY	https://github.com/mikke89/RmlUi.git
	GIT_TAG			5.0
	)
FetchContent_MakeAvailable(external-RmlUi)
find_package(RmlUi PATHS ${RmlUi_BUILD_DIR})

find_package(SDL2 CONFIG REQUIRED)

add_executable(RPGEngine main.cpp)

target_link_libraries(RPGEngine PRIVATE
	RmlUi::RmlUi
	SDL2::SDL2
	SDL2::SDL2main
	)
