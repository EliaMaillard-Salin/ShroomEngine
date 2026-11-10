
#include <Window.h>

Window::Window(uint16 width, uint16 height) :
	m_dimensions(width,height), m_pSDLWindow(nullptr)
{
}

Window::Window(Vector2<uint16> screenSize):
	m_dimensions(screenSize), m_pSDLWindow(nullptr)
{

}

SDL_Window* Window::GetSDLWindow()
{
	return m_pSDLWindow;
}

bool Window::Open(const char* title)
{
	if (SDL_Init(static_cast<Uint32>(SDL_INIT_VIDEO)) != 0)
	{
		Logger::Error(LogType::ERROR, "Failed To Init SDL_VIDEO");
		return false;
	}
	m_pSDLWindow = SDL_CreateWindow(title, static_cast<int>(SDL_WINDOWPOS_CENTERED), static_cast<int>(SDL_WINDOWPOS_CENTERED),
		m_dimensions.X(), m_dimensions.Y(), static_cast<Uint32>(SDL_WINDOW_OPENGL));
	if (!m_pSDLWindow)
	{
		Logger::Error(LogType::ERROR, "Failed to create Window");
		return false;
	}
	return true;
}

void Window::Close()
{
	SDL_DestroyWindow(m_pSDLWindow);
}