#include "PongScene.h"
#include <Renderer.h>
#include <Drawable2DShapes.h>
#include "PlayerScript.h"
using namespace shroom;

PongScene::PongScene(const char* name) : Scene(name)
{
	startingPos = { 250.0f,475.0f };
	Actor& player = CreateActor();
	player.AddComponent<PlayerScript>("PlayerScript");
}

void PongScene::OnRender()
{
	Rectangle rect = { startingPos,{50.0f,10.0f} };
	m_pRenderer->DrawShape2D(rect);
}

void PongScene::OnInputCalled(SDL_Event event)
{
	if (event.type == SDL_KEYDOWN)
	{
		if (event.key.keysym.sym == SDL_KeyCode::SDLK_q)
			startingPos.X() -= 5.0f;
		if (event.key.keysym.sym == SDL_KeyCode::SDLK_d)
			startingPos.X() += 5.0f;
	}
}
