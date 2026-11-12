#include "PlayerScript.h"

#include "Actor.h"

PlayerScript::PlayerScript(shroom::Actor* pOwner):
	ScriptComponent(pOwner), m_speed(5.0f)
{
}

void PlayerScript::OnInputPressed(SDL_Event event)
{
	if (event.type != SDL_KEYDOWN)
		return;

	if (event.key.keysym.sym == SDLK_q)
		m_pOwner->GetTransform().AddPositionX(-m_speed);
	if (event.key.keysym.sym == SDLK_d)
		m_pOwner->GetTransform().AddPositionX(m_speed);
}
