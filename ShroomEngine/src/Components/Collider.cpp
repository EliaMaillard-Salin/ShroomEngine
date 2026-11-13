#include "Collider.h"
#include "Actor.h"
#include "PhysicHandler.h"

using namespace shroom;

Collider::Collider(std::string name, Actor* pOwner):
	Component(name,pOwner)
{
	m_pOwner->SetHasCollisions(true);
	pOwner->AddCollider(this);
}

Collider::~Collider()
{
}

void shroom::Collider::AddIgnoredColliderTag(uint8 tag)
{
	m_ignoredtag.push_back(tag);
}
void shroom::Collider::SetTag(uint8 tag)
{
	m_tag = tag;
}

void Collider::RemoveIgnoredColliderTag(uint8 tag)
{
	m_ignoredtag.remove(tag);
}

Transform2D Collider::GetWorldColliderTransform()
{
	Transform2D worldTransform = {};
	Transform2D parentTransform = m_pOwner->GetTransform();
	worldTransform.SetPosition(parentTransform.GetPosition() + m_colliderTransform.GetPosition());
	worldTransform.SetScale(parentTransform.GetScale() * m_colliderTransform.GetScale());

	return worldTransform;
}

Transform2D& Collider::GetRelativeColliderTransform()
{
	return m_colliderTransform;
}

Collider::ColliderShape Collider::GetShape()
{
	return m_shape;
}
void Collider::DuplicateValues(Component& out)
{
	Component::DuplicateValues(out);
	Collider* pCollider = dynamic_cast<Collider*>(&out);
	pCollider->m_shape = m_shape;
	pCollider->m_colliderTransform = m_colliderTransform;
	pCollider->m_types = m_types;
	pCollider->m_tag = m_tag;
	pCollider->m_ignoredtag = m_ignoredtag;
}

void Collider::Destroy()
{
	if (m_pOwner->IsStatic())
		PhysicsHandler::RemoveStaticActor(m_pOwner);
	else
		PhysicsHandler::RemoveDynamicActor(m_pOwner);
	Component::Destroy();
}
