#include "KeyboardInput.hpp"
#include <SDL.h>


KeyboardInput::~KeyboardInput() {
	SDL_StopTextInput();
}

void KeyboardInput::ToggleKeyboardInput(const bool enabled) {
	if(enabled) {
		SDL_StartTextInput();
	} else {
		SDL_StopTextInput();
	}
}