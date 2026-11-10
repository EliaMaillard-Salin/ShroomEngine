#ifndef RENDER_RENDERER_H
#define RENDER_RENDERER_H

#include <SDL.h>
class Window;
struct Rectangle;
struct Circle;
struct Ellipse;

class Renderer
{
public:
	Renderer();
	Renderer(const Renderer&) = delete;
	Renderer& operator= (const Renderer&) = delete;

	bool Initialize(Window& rWindow);
	void BeginDraw();
	void EndDraw();
	void Close();

	void DrawShape2D(Rectangle& rRect);
	void DrawShape2D(Circle& rEllipse);
	void DrawShape2D(Ellipse& rCircle);


private:
	SDL_Renderer* m_pSDLRenderer;
};


#endif // !define RENDER_RENDERER_H
