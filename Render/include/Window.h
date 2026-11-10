#ifndef RENDER_WINDOW_H
#define RENDER_WINDOW_H

#include <SDL.h>
#include <Vectors.h>
#include "Define.h"

class Window
{
public:
	Window(uint16 width, uint16 height);
	Window(Vector2<uint16> screenSize);
	Window(Window const&) = delete;
	Window& operator=(Window const&) = delete;

	Vector2<uint16> const& GetDimensions();
	SDL_Window* GetSDLWindow();

	bool Open(const char* title);
	void Close();

protected:
	Vector2<uint16> m_dimensions;
	SDL_Window* m_pSDLWindow;
};


#endif // !SHROOM_ENGINE_WINDOW_H
