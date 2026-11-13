
#include "EnemyScript.h"
#include "Actor.h"
#include "Components.h"
#include "Scene.h"
#include "Bullet.h"
#include "Time.h"

EnemyScript::EnemyScript(std::string name, shroom::Actor* pOwner):
	ScriptComponent(name,pOwner)
{
}
void EnemyScript::Update()
{
	m_shootCD += shroom::Time::deltaTime;
	if (m_shootCD >= m_shootDelay)
	{
		m_shootCD = 0.0f;
		SpawnBullet();
	}
}

void EnemyScript::SpawnBullet()
{
	shroom::Actor& newBullet = m_pOwner->GetScene()->CreateActor();
	newBullet.SetStatic(false);
	shroom::BoxCollider& b = newBullet.AddComponent<shroom::BoxCollider>("BulletBox");
	BulletScript& s = newBullet.AddComponent<BulletScript>("BulletS");
	s.SetIgnoredTarget(1);
	s.SetSpeed(5.0f);
	newBullet.GetTransform().SetPosition(m_pOwner->GetTransform().GetPosition());
}

shroom::Component* EnemyScript::Duplicate()
{
	return nullptr;
}

void EnemyScript::DuplicateValues(shroom::Component& out)
{
}