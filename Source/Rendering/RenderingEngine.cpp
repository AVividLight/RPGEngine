#include "RenderingEngine.hpp"
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <SDL_FontCache.h>

#include <iostream>


namespace {
	static constexpr unsigned short WINDOW_WIDTH = 1600;
	static constexpr unsigned short WINDOW_HEIGHT = 900;
	SDL_Color BACKGROUND_COLOR = {138, 138, 138, 255};
	
	static constexpr const char* const MAIN_FONT_PATH = "Fonts/Chivo.ttf";
	static constexpr unsigned char MAIN_FONT_SIZE = 32;
	SDL_Color MAIN_FONT_COLOR = {255,255,255,255};
}


RenderingEngine::RenderingEngine(const char* const title) : MainWindow{nullptr} {
	if(SDL_Init(SDL_INIT_VIDEO) < 0) {
		std::cout << "SDL initialization error!" << std::endl;
	} else {
		MainWindow = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_SHOWN);
		if(!MainWindow) {
			std::cout << "Failed creating window!" << std::endl;
		} else {
			MainSurface = SDL_GetWindowSurface(MainWindow);
			SDL_UpdateWindowSurface(MainWindow);

			MainRenderer = SDL_CreateRenderer(MainWindow, -1, 0);
			SDL_SetRenderDrawColor(MainRenderer, BACKGROUND_COLOR.r, BACKGROUND_COLOR.g, BACKGROUND_COLOR.b, BACKGROUND_COLOR.a);
			SDL_RenderClear(MainRenderer);

			StandardFont = FC_CreateFont();
			FC_LoadFont(StandardFont, MainRenderer, MAIN_FONT_PATH, MAIN_FONT_SIZE, MAIN_FONT_COLOR, TTF_STYLE_NORMAL);

			SDL_RenderPresent(MainRenderer);
		}
	}
}


RenderingEngine::~RenderingEngine() {
	FC_FreeFont(StandardFont);
	SDL_Quit();
}


void RenderingEngine::UpdateMainText(const char* const text) {
	MainText += text;
}


void RenderingEngine::Repaint() {
	SDL_RenderClear(MainRenderer);
	FC_Draw(StandardFont, MainRenderer, 0, 0, MainText.c_str());
	SDL_RenderPresent(MainRenderer);
}