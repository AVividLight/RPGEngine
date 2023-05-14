#include "RenderingEngine.hpp"
#include <SDL.h>


int main(int argc, char* argv[]) {
	RenderingEngine renderer("RPGEngine");

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
					renderer.UpdateMainText(e.text.text);
			break;
			}
		}
		renderer.Repaint();
	} while(quit == false);

	SDL_StopTextInput();
	return 0;
}