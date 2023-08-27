cmake_minimum_required(VERSION 3.24.0)
project(RPGEngine CXX)

set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_CXX_STANDARD 17)

if(CMAKE_CURRENT_SOURCE_DIR STREQUAL CMAKE_CURRENT_BINARY_DIR)
	message(FATAL_ERROR "Create a build directory outside of the source tree and run `cmake -S ${CMAKE_SOURCE_DIR} -B .` from there.")
endif()

include(FetchContent)

FetchContent_Declare(SDL2
	GIT_REPOSITORY		https://github.com/libsdl-org/SDL.git
	GIT_TAG				release-2.26.4
	GIT_PROGRESS		TRUE
	OVERRIDE_FIND_PACKAGE)
set(SDL_SHARED_ENABLED_BY_DEFAULT ON CACHE BOOL "" FORCE)
set(SDL_STATIC_ENABLED_BY_DEFAULT OFF CACHE BOOL "" FORCE)

FetchContent_Declare(SDL_Image
	GIT_REPOSITORY		https://github.com/libsdl-org/SDL_image.git
	GIT_TAG				release-2.6.3
	GIT_PROGRESS 		TRUE
	OVERRIDE_FIND_PACKAGE)
set(BUILD_STATIC_LIBS FALSE)
set(SDL2IMAGE_SAMPLES OFF CACHE BOOL "" FORCE)
set(SDL2IMAGE_INSTALL OFF CACHE BOOL "" FORCE)

FetchContent_Declare(SDL_TTF
	GIT_REPOSITORY		https://github.com/libsdl-org/SDL_ttf.git
	GIT_TAG				release-2.20.2
	GIT_PROGRESS 		TRUE
	OVERRIDE_FIND_PACKAGE)
set(SDL2TTF_SAMPLES OFF CACHE BOOL "" FORCE) 
set(SDL2TTF_INSTALL OFF CACHE BOOL "" FORCE)

FetchContent_Declare(nlohmann_json
		GIT_REPOSITORY	https://github.com/nlohmann/json.git
		GIT_TAG			v3.11.2
		GIT_PROGRESS	TRUE
		OVERRIDE_FIND_PACKAGE)
set(JSON_BuildTests OFF CACHE BOOL "" FORCE)

FetchContent_MakeAvailable(SDL2 SDL_Image SDL_TTF nlohmann_json)

add_subdirectory(Libraries)

add_executable(RPGEngine
	${SDL2_FontCache}
	$<TARGET_OBJECTS:SDL2_FontCache>
	main.cpp)

add_subdirectory(Source)

target_include_directories(RPGEngine PRIVATE
	Libraries/SDL_FontCache)

target_link_libraries(RPGEngine PRIVATE
	SDL2::SDL2
	SDL2::SDL2main
	SDL2_image::SDL2_image
	SDL2_ttf::SDL2_ttf
	nlohmann_json::nlohmann_json
	SDL2_FontCache)

add_custom_command(TARGET RPGEngine POST_BUILD
	COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_RUNTIME_DLLS:RPGEngine>
	$<TARGET_FILE_DIR:RPGEngine>
	COMMAND_EXPAND_LISTS)

add_custom_command(TARGET RPGEngine POST_BUILD
	COMMAND ${CMAKE_COMMAND} -E copy_directory ${CMAKE_SOURCE_DIR}/Resources
	$<TARGET_FILE_DIR:RPGEngine>/Resources
	COMMAND_EXPAND_LISTS)
