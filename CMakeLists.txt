cmake_minimum_required(VERSION 3.20.0)
project(RPGEngine CXX)

if (MSVC)
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /GR-")
elseif (UNIX)
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fno-rtti")
endif()

find_package(SDL2 CONFIG REQUIRED)
set(ULTRALIGHT_DIR "NOTFOUND" CACHE PATH "Path to root Ultralight folder")

add_executable(RPGEngine main.cpp)
target_include_directories(RPGEngine PRIVATE "${ULTRALIGHT_DIR}/include/")
target_link_libraries(RPGEngine PRIVATE
	SDL2::SDL2
	SDL2::SDL2main
	-lUltralight
	-lUltralightCore
	-lWebCore)
