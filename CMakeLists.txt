cmake_minimum_required(VERSION 3.24.0)
project(RPGEngine CXX)

set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_CXX_STANDARD 17)

if(CMAKE_CURRENT_SOURCE_DIR STREQUAL CMAKE_CURRENT_BINARY_DIR)
	message(FATAL_ERROR "Create a build directory outside of the source tree and run `cmake -S ${CMAKE_SOURCE_DIR} -B .` from there.")
endif()

include(FetchContent)

find_package(SDL2 QUIET)
if(NOT ${SDL2_FOUND})
	message(STATUS "SDL2 will be fetched.")

	FetchContent_Declare(external-SDL
		GIT_REPOSITORY	https://github.com/libsdl-org/SDL.git
		GIT_TAG			release-2.26.4
		GIT_PROGRESS TRUE
		OVERRIDE_FIND_PACKAGE
	)
	set(SDL_SHARED_ENABLED_BY_DEFAULT ON CACHE BOOL "" FORCE)
	set(SDL_STATIC_ENABLED_BY_DEFAULT OFF CACHE BOOL "" FORCE)
	FetchContent_MakeAvailable(external-SDL)
	find_package(external-SDL)
endif(NOT ${SDL2_FOUND})

find_package(SDL2_image QUIET)
if(NOT ${SDL2_image_FOUND})
	message(STATUS "SDL2_Image will be fetched.")

	FetchContent_Declare(external-SDL_Image
		GIT_REPOSITORY	https://github.com/libsdl-org/SDL_image.git
		GIT_TAG			release-2.6.3
		GIT_PROGRESS TRUE
		OVERRIDE_FIND_PACKAGE
	)
	set(BUILD_STATIC_LIBS FALSE)
	set(SDL2IMAGE_SAMPLES OFF CACHE BOOL "" FORCE)
	set(SDL2IMAGE_INSTALL OFF CACHE BOOL "" FORCE) 
	FetchContent_MakeAvailable(external-SDL_Image)
	find_package(external-SDL_Image)
endif(NOT ${SDL2_image_FOUND})

find_package(SDL2_ttf QUIET)
if(NOT ${SDL2_ttf_FOUND})
	message(STATUS "SDL2_TTF will be fetched.")

	FetchContent_Declare(external-SDL_TTF
		GIT_REPOSITORY	https://github.com/libsdl-org/SDL_ttf.git
		GIT_TAG			release-2.20.2
		GIT_PROGRESS TRUE
		OVERRIDE_FIND_PACKAGE
	)
	set(SDL2TTF_SAMPLES OFF CACHE BOOL "" FORCE) 
	set(SDL2TTF_INSTALL OFF CACHE BOOL "" FORCE)
	FetchContent_MakeAvailable(external-SDL_TTF)
	find_package(external-SDL_TTF)
endif(NOT ${SDL2_ttf_FOUND})

find_package(RapidJSON QUIET)
if(NOT ${RapidJSON_FOUND})
	message(STATUS "RapidJSON will be fetched.")

	FetchContent_Declare(external-RapidJSON
		GIT_REPOSITORY	https://github.com/Tencent/rapidjson.git
		GIT_TAG			476ffa2fd272243275a74c36952f210267dc3088 #Latest commit as of 8/23/2023
		GIT_PROGRESS	TRUE
		OVERRIDE_FIND_PACKAGE
	)
	set(RAPIDJSON_BUILD_DOC OFF CACHE BOOL "" FORCE)
	set(RAPIDJSON_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
	set(RAPIDJSON_BUILD_TESTS OFF CACHE BOOL "" FORCE)
	set(RAPIDJSON_BUILD_THIRDPARTY_GTEST OFF CACHE BOOL "" FORCE)
	set(RAPIDJSON_BUILD_CXX17 ON CACHE BOOL "" FORCE)
	set(RAPIDJSON_BUILD_ASAN OFF CACHE BOOL "" FORCE)
	set(RAPIDJSON_BUILD_UBSAN OFF CACHE BOOL "" FORCE)
	set(RAPIDJSON_ENABLE_INSTRUMENTATION_OPT ON CACHE BOOL "" FORCE)
	set(RAPIDJSON_HAS_STDSTRING ON CACHE BOOL "" FORCE)
	set(RAPIDJSON_USE_MEMBERSMAP OFF CACHE BOOL "" FORCE)
	FetchContent_MakeAvailable(external-RapidJSON)
	find_package(external-RapidJSON)
endif(NOT ${RapidJSON_FOUND})

add_subdirectory(Libraries)

add_executable(RPGEngine
	${SDL2_FontCache}
	$<TARGET_OBJECTS:SDL2_FontCache>
	main.cpp)

add_subdirectory(Source)

target_include_directories(RPGEngine PRIVATE
	Libraries/SDL_FontCache
	)

target_link_libraries(RPGEngine PRIVATE
	SDL2::SDL2
	SDL2::SDL2main
	SDL2_image::SDL2_image
	SDL2_ttf::SDL2_ttf
	RapidJSON
	SDL2_FontCache)

add_custom_command(TARGET RPGEngine POST_BUILD
	COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_RUNTIME_DLLS:RPGEngine>
	$<TARGET_FILE_DIR:RPGEngine>
	COMMAND_EXPAND_LISTS)

add_custom_command(TARGET RPGEngine POST_BUILD
	COMMAND ${CMAKE_COMMAND} -E copy_directory ${CMAKE_SOURCE_DIR}/Resources
	$<TARGET_FILE_DIR:RPGEngine>/Resources
	COMMAND_EXPAND_LISTS)
