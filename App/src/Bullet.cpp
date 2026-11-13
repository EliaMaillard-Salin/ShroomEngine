#include "Bullet.h"


#include "Actor.h"
#include "Components.h"

BulletScript::BulletScript(std::string name, shroom::Actor* pOwner):
	ScriptComponent(name,pOwner), m_speed(5.0f),m_target(0)
{
}

void BulletScript::Update()
{
	m_pOwner->GetTransform().AddPositionY(m_speed);
}

void BulletScript::OnCollision(shroom::Collider* pOwned, shroom::Collider* pOther)
{
	m_pOwner->Destroy();
	pOther->GetActor()->Destroy();
	shroom::Logger::Info("KILL");
}

void BulletScript::SetIgnoredTarget(shroom::uint8 t)
{
	shroom::BoxCollider& b = m_pOwner->GetComponent<shroom::BoxCollider>("BulletBox");
	b.SetTag(2);
	b.AddIgnoredColliderTag(t);
	b.AddIgnoredColliderTag(2);
}

void BulletScript::SetSpeed(float speed)
{
	m_speed = speed;
}

shroom::Component* BulletScript::Duplicate()
{
	return nullptr;
}

void BulletScript::DuplicateValues(shroom::Component& out)
{
}