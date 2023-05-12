#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <SDL_FontCache.h>
#include <string>


namespace {
	FC_Font* Font = nullptr;
	std::string Input;
}


SDL_Window* SetupSDL() {
	if(SDL_Init(SDL_INIT_VIDEO) < 0) {
		std::cout << "SDL initialization error!" << std::endl;
	} else {
		SDL_Window* const window = SDL_CreateWindow("Test Window Title", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, SDL_WINDOW_SHOWN);
		if(window == nullptr) {
			std::cout << "Failed creating window!" << std::endl;
		} else {
			SDL_Surface* const screen = SDL_GetWindowSurface(window);
			SDL_FillRect(screen, nullptr, SDL_MapRGB(screen->format, 69, 69, 69));
			SDL_UpdateWindowSurface(window);

			SDL_Renderer* const renderer = SDL_CreateRenderer(window, -1, 0);
			SDL_SetRenderDrawColor(renderer, 138, 138, 138, 255);
			SDL_RenderFillRect(renderer, NULL);
			Font = FC_CreateFont();
			FC_LoadFont(Font, renderer, "Fonts/Chivo.ttf", 20, FC_MakeColor(0,0,0,255), TTF_STYLE_NORMAL);
			FC_Draw(Font, renderer, 0, 0, "This is %s.\n It works.", "example text");
			SDL_RenderPresent(renderer);

			return window;
		}
	}

	return nullptr;
}


void Repaint(SDL_Window& window) {
	SDL_Renderer* const renderer = SDL_GetRenderer(&window);
	SDL_RenderFillRect(renderer, NULL);
	FC_Draw(Font, renderer, 0, 0, Input.c_str());
	SDL_RenderPresent(renderer);
}


int main(int argc, char* argv[]) {
	SDL_Window* const window = SetupSDL();
	if(window) {
		SDL_StartTextInput();
		SDL_Event e;
		bool quit = false;
		do {
			while(SDL_PollEvent(&e)) {
				switch(e.type)
				{
				case SDL_QUIT:
					quit = true;
				break;

				case SDL_TEXTINPUT:
					Input += e.text.text;
				break;
				}
			}
			Repaint(*window);
		} while(quit == false);
		
		SDL_DestroyWindow(window);
	}

	SDL_StopTextInput();
	FC_FreeFont(Font);
	SDL_Quit();
	return 0;
}