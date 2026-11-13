#include "Ball.h"


#include "Actor.h"
#include "Components.h"
#include "Time.h"

BallScript::BallScript(std::string name, shroom::Actor* pOwner) :
	ScriptComponent(name, pOwner), m_speed(2), m_direction(1.0f, 1.0f),m_collisionCD(0.0f)
{
}

void BallScript::Update()
{

	m_pOwner->GetTransform().AddPosition(m_direction*m_speed);

	if (m_pOwner->GetTransform().GetPosition().X() <= 0.0f)
		m_direction.X() = 1.0f;
	if (m_pOwner->GetTransform().GetPosition().X() + 10.0f >= m_screenDimansions.X())
		m_direction.X() = -1.0f;
	if (m_pOwner->GetTransform().GetPosition().Y() <= 0.0f)
		m_direction.Y() = 1.0f;
	if (m_pOwner->GetTransform().GetPosition().Y() + 10.0f >= m_screenDimansions.Y())
		m_direction.Y() = -1.0f;
	m_collisionCD += shroom::Time::deltaTime;

}

void BallScript::OnCollision(shroom::Collider* pOwned, shroom::Collider* pOther)
{
	if (m_collisionCD < 0.5f)
		return;

	m_direction.X() = m_direction.X() * -1.0f;
	//shroom::Vector2f otherPos = pOther->GetActor()->GetTransform().GetPosition();
	//shroom::Vector2f selfPos = m_pOwner->GetTransform().GetPosition();
	//if (std::abs(otherPos.X() - selfPos.X()) >= std::abs(otherPos.Y() - selfPos.Y()))
	//else
	//	m_direction.Y() = m_direction.Y() * -1.0f;
	m_collisionCD = 0.0f;
	m_speed += 0.5f;
}

void BallScript::SetScreenDimensions(shroom::Vector2<shroom::uint16> screenDimansions)
{
	m_screenDimansions = screenDimansions;
}



shroom::Component* BallScript::Duplicate()
{
	return nullptr;
}

void BallScript::DuplicateValues(shroom::Component& out)
{
}