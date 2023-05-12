add_library(SDL2_FontCache OBJECT
    SDL_FontCache.h
    SDL_FontCache.c
)

target_link_libraries(SDL2_FontCache 
	SDL2::SDL2
	SDL2::SDL2main
	SDL2_ttf::SDL2_ttf
)
