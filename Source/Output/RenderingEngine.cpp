#include "RenderingEngine.hpp"
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
//#include <SDL_FontCache.h>

#include <iostream>


namespace {
	constexpr unsigned short WINDOW_WIDTH = 1600;
	constexpr unsigned short WINDOW_HEIGHT = 900;
	SDL_Color BACKGROUND_COLOR = {138, 138, 138, 255};
	
	//constexpr const char* const MAIN_FONT_PATH = "Fonts/Chivo.ttf";
	constexpr unsigned char MAIN_FONT_SIZE = 32;
	SDL_Color MAIN_FONT_COLOR = {255,255,255,255};

	constexpr unsigned char SPRITE_SIZE = 32;
	constexpr unsigned char CHARACTER_MARGIN = 4;
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

			//StandardFont = FC_CreateFont();
			//FC_LoadFont(StandardFont, MainRenderer, MAIN_FONT_PATH, MAIN_FONT_SIZE, MAIN_FONT_COLOR, TTF_STYLE_NORMAL);

			SDL_Surface* const rawSheet = IMG_Load("Resources/Font.png");
			SpriteSheet = SDL_CreateTextureFromSurface(MainRenderer, rawSheet);
			SDL_FreeSurface(rawSheet);

			constexpr const char string[7] = "GIBSON";
			for(unsigned char i = 0; i < sizeof(string) - 1; i += 1) {
				const SDL_Rect source = RenderingEngine::CharacterToSpriteIndex(string[i], 10);
				std::cout << string[i] << " (" << (int)i << ") at {" << source.x << ", " << source.y << ']' << std::endl;
				SDL_Rect destination {10 + (i * SPRITE_SIZE) + (i * CHARACTER_MARGIN), 10, SPRITE_SIZE, SPRITE_SIZE};

				if(SDL_RenderCopy(MainRenderer, SpriteSheet, &source, &destination) != 0)
				{
					std::cout << "Render Copy Failed!" << std::endl;
				}
			}

			SDL_RenderPresent(MainRenderer);
		}
	}
}


RenderingEngine::~RenderingEngine() {
	//FC_FreeFont(StandardFont);
	SDL_Quit();
}


void RenderingEngine::UpdateMainText(const char* const text) {
	MainText += text;
}


void RenderingEngine::Repaint() {
	SDL_RenderClear(MainRenderer);
	//FC_Draw(StandardFont, MainRenderer, 0, 0, MainText.c_str());
	SDL_RenderPresent(MainRenderer);
}


constexpr SDL_Rect RenderingEngine::CharacterToSpriteIndex(const unsigned char c, const unsigned char spriteSheetSize) {
	const unsigned short oneDimensionalPosition = (c - 'A');
	return SDL_Rect{(oneDimensionalPosition % spriteSheetSize) * SPRITE_SIZE, (oneDimensionalPosition / spriteSheetSize) * SPRITE_SIZE, SPRITE_SIZE, SPRITE_SIZE};
}