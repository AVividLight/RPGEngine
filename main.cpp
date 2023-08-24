#include "RenderingEngine.hpp"
#include "KeyboardInput.hpp"
#include <SDL.h>
//#include <chrono>
#include <rapidjson/document.h>


//using TARGET_FRAME_RATE = std::ratio<1, 30>;


int main(int argc, char* argv[]) {
	RenderingEngine renderer("RPGEngine");
	KeyboardInput input;
	/*std::chrono::steady_clock time;
	std::chrono::time_point<std::chrono::steady_clock> lastFrameTimestamp{};
	std::chrono::time_point<std::chrono::steady_clock> currentFrameTimestamp{};
	std::chrono::duration<long long, std::nano> frameDelta;*/

	input.ToggleKeyboardInput(true);

	SDL_Event e;
	bool quit = false;
	do {
		//currentFrameTimestamp = std::chrono::steady_clock::now();
		//frameDelta = currentFrameTimestamp - lastFrameTimestamp;

		while(SDL_PollEvent(&e)) {
			switch(e.type)
			{
			case SDL_QUIT:
				quit = true;
			break;

			case SDL_TEXTINPUT:
				//renderer.UpdateMainText(e.text.text);
			break;
			}
		}
		//renderer.Repaint();
	} while(quit == false);

	input.ToggleKeyboardInput(false);

	return 0;
}
