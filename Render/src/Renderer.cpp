
#include <Renderer.h>
#include <Window.h>
#include <Logger.h>
#include "Drawable2DShapes.h"


using namespace shroom;

Renderer::Renderer() :
	m_pSDLRenderer(nullptr)
{}

bool Renderer::Initialize(Window& rWindow)
{
    m_pSDLRenderer = SDL_CreateRenderer(rWindow.GetSDLWindow(), -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (!m_pSDLRenderer)
    {
        Logger::Error(LogType::VIDEO, "Failed to create Renderer");
        return false;
    }
    return true;

}

void Renderer::BeginDraw()
{
    SDL_SetRenderDrawColor(m_pSDLRenderer, 120, 120, 255, 255);
    SDL_RenderClear(m_pSDLRenderer);
}

void Renderer::EndDraw()
{
    SDL_RenderPresent(m_pSDLRenderer);
}

void Renderer::DrawShape2D(Rectangle& rRect)
{
    SDL_SetRenderDrawColor(m_pSDLRenderer, 255, 255, 255, 255);
    SDL_Rect sdlRect = { static_cast<int32>(rRect.position.X()),static_cast<int32>(rRect.position.Y()),static_cast<int32>(rRect.dimensions.X()),static_cast<int32>(rRect.dimensions.Y()) };
    SDL_RenderFillRect(m_pSDLRenderer, &sdlRect);
}
void Renderer::DrawShape2D(Circle& rCircle)
{
}
void Renderer::DrawShape2D(Ellipse& rEllipse)
{
}


void Renderer::Close()
{
    SDL_DestroyRenderer(m_pSDLRenderer);
}