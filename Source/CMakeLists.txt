add_subdirectory(Input)
add_subdirectory(Processing)
add_subdirectory(Output)

target_include_directories(RPGEngine
	PRIVATE Input
	PRIVATE Processing
	PRIVATE Rendering
)