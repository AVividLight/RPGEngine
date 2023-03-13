#include <iostream>
#include <SDL.h>
#include <SDL_ttf.h>
#include <SDL_image.h>


SDL_Window* SetupSDL() {
	if(SDL_Init(SDL_INIT_VIDEO) < 0) {
		std::cout << "SDL initialization error!" << std::endl;
	} else {
		SDL_Window* window = SDL_CreateWindow("Test Window Title", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, SDL_WINDOW_SHOWN);
		if(window == nullptr) {
			std::cout << "Failed creating window!" << std::endl;
		} else {
			SDL_Surface& screen = *SDL_GetWindowSurface(window);
			SDL_FillRect(&screen, nullptr, SDL_MapRGB(screen.format, 69, 69, 69));
			SDL_UpdateWindowSurface(window);

			return window;
		}
	}

	return nullptr;
}


int main(int argc, char* argv[]) {
	SDL_Window* const window = SetupSDL();
	if(window) {
		SDL_Event e;
		bool quit = false;
		while(quit == false) {
			while(SDL_PollEvent(&e)) {
				if(e.type == SDL_QUIT)
					quit = true;
			}
		}
		
		SDL_DestroyWindow(window);
	}

	SDL_Quit();
	return 0;
}