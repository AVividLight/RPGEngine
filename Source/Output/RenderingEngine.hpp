#ifndef RENDERINGENGINE_HPP
#define RENDERINGENGINE_HPP

#include <SDL_rect.h>
#include <string>

struct SDL_Window;
struct SDL_Surface;
struct SDL_Texture;
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
	static constexpr SDL_Rect CharacterToSpriteIndex(const unsigned char c, const unsigned char spriteSheetSize);

	SDL_Window* MainWindow;
	SDL_Surface* MainSurface;
	SDL_Renderer* MainRenderer;
	FC_Font* StandardFont;
	std::string MainText;

	SDL_Texture* SpriteSheet;
};

#endif