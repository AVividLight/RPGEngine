#include "RenderingEngine.hpp"
#include "KeyboardInput.hpp"
#include <SDL.h>


int main(int argc, char* argv[]) {
	RenderingEngine renderer("RPGEngine");
	KeyboardInput input;

	input.ToggleKeyboardInput(true);

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

	input.ToggleKeyboardInput(false);

	return 0;
}
