#include <iostream>
#include "SDL.h"

int main(int argc, char* argv[]) {
	std::cout << "Hello, world!" << std::endl;

	SDL_Window* window = nullptr;
	SDL_Surface* screen = nullptr;

	if(SDL_Init(SDL_INIT_VIDEO) < 0) {
		std::cout << "SDL initialization error!" << std::endl;
	} else {
		window = SDL_CreateWindow("Test Window Title", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, SDL_WINDOW_SHOWN);
		if(!window) {
			std::cout << "Failed creating window!" << std::endl;
		} else {
			screen = SDL_GetWindowSurface(window);
			SDL_FillRect(screen, nullptr, SDL_MapRGB(screen->format, 0, 0, 0));
			SDL_UpdateWindowSurface(window);

			SDL_Event e;
			bool quit = false;
			while(quit == false) {
				while(SDL_PollEvent(&e)) {
					if(e.type == SDL_QUIT)
						quit = true;
				}
			}
		}
	}

	SDL_DestroyWindow(window);
	SDL_Quit();

	return 0;
}