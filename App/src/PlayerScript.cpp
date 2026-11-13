
#include "PlayerScript.h"
#include "Actor.h"

#include "Scene.h"
#include "Components.h"
#include "Bullet.h"

PlayerScript::PlayerScript(std::string name, shroom::Actor* pOwner):
	ScriptComponent(name,pOwner), m_speed(5.0f), m_move(false)
{
}

void PlayerScript::OnInputPressed(SDL_Event event)
{
	if (event.type == SDL_KEYDOWN)
	{
		if (event.key.keysym.sym == keyUp)	
		{
			dir = -1.0f;
			m_move = true;
		}
		if (event.key.keysym.sym == keyDown)
		{
			dir = 1.0f;
			m_move = true;
		}
		if (event.key.keysym.sym == SDLK_e)
			SpawnBullet();
	}

	if (event.type == SDL_KEYUP)
	{
		if (event.key.keysym.sym == keyUp)
			m_move = false;
		if (event.key.keysym.sym == keyDown)
			m_move = false;
	}
}

void PlayerScript::Update()
{
	if (m_move)
	{
		m_pOwner->GetTransform().AddPositionY(m_speed * dir);
	}
}

void PlayerScript::OnCollision(shroom::Collider* pOwned, shroom::Collider* pOther)
{
	shroom::Logger::Info("COLLISION DETECTED IN SCRIPT");
}

void PlayerScript::SetKeyToMove(SDL_KeyCode up, SDL_KeyCode down)
{
	keyUp = up;
	keyDown = down;
}

void PlayerScript::SpawnBullet()
{
	shroom::Actor& newBullet = m_pOwner->GetScene()->CreateActor();
	newBullet.SetStatic(false);
	shroom::BoxCollider& b = newBullet.AddComponent<shroom::BoxCollider>("BulletBox");
	BulletScript& s = newBullet.AddComponent<BulletScript>("BulletS");
	s.SetIgnoredTarget(0);
	s.SetSpeed(-5.0f);
	newBullet.GetTransform().SetPosition(m_pOwner->GetTransform().GetPosition());
}

shroom::Component* PlayerScript::Duplicate()
{
	shroom::Component* pComp = new PlayerScript(m_name, m_pOwner);
	DuplicateValues(*pComp);
	return pComp;
}

void PlayerScript::DuplicateValues(shroom::Component& out)
{
	ScriptComponent::DuplicateValues(out);

}

