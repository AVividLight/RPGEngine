add_subdirectory(Rendering)
add_subdirectory(Input)

target_include_directories(RPGEngine
	PRIVATE Rendering
	PRIVATE Input)