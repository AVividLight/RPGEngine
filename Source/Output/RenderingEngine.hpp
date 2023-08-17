#ifndef RENDERINGENGINE_HPP
#define RENDERINGENGINE_HPP

#include <string>

struct SDL_Window;
struct SDL_Surface;
struct SDL_Renderer;
struct FC_Font;

class RenderingEngine final {
public:
	explicit RenderingEngine(const char* const title);
	RenderingEngine(const RenderingEngine&) = delete;
	RenderingEngine(RenderingEngine&&) = delete;
	RenderingEngine& operator=(const RenderingEngine&) = delete;
	RenderingEngine& operator=(RenderingEngine&&) = delete;
	~RenderingEngine();

	void UpdateMainText(const char* const text);
	void Repaint();

private:
	SDL_Window* MainWindow;
	SDL_Surface* MainSurface;
	SDL_Renderer* MainRenderer;
	FC_Font* StandardFont;

	std::string MainText;
};

#endif