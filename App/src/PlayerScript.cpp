
#include "PlayerScript.h"
#include "Actor.h"

#include "Scene.h"
#include "Components.h"
#include "Bullet.h"

PlayerScript::PlayerScript(std::string name, shroom::Actor* pOwner):
	ScriptComponent(name,pOwner), m_speed(5.0f)
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
	if (event.key.keysym.sym == SDLK_e)
		SpawnBullet();
}

void PlayerScript::OnCollision(shroom::Collider* pOwned, shroom::Collider* pOther)
{
	shroom::Logger::Info("COLLISION DETECTED IN SCRIPT");
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

