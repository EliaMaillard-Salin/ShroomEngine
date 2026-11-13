#include "PhysicHandler.h"

#include "Components.h"
#include "Actor.h"

using namespace shroom;

std::list<Actor*> PhysicsHandler::m_staticActor = {};
std::list<Actor*> PhysicsHandler::m_dynamicActor = {};

void PhysicsHandler::CheckCollision()
{
	std::list<Actor*>::iterator nextIt2 = m_dynamicActor.begin();
	for (std::list<Actor*>::iterator it1 = m_dynamicActor.begin(); it1 != m_dynamicActor.end(); it1++)
	{
		nextIt2++;
		for (std::list<Actor*>::iterator it2 = nextIt2; it2 != m_dynamicActor.end(); it2++)
		{
			CheckActorsCollisions(*it1, *it2);
		}

		for (std::list<Actor*>::iterator it2 = m_staticActor.begin(); it2 != m_staticActor.end(); it2++)
		{
			CheckActorsCollisions(*it1, *it2);
		}
	}
}

void PhysicsHandler::AddStaticActor(Actor* pActor)
{
	m_staticActor.push_back(pActor);
}

void PhysicsHandler::AddDynamicActor(Actor* pActor)
{
	m_dynamicActor.push_back(pActor);
}

void PhysicsHandler::RemoveStaticActor(Actor* pActor)
{
	m_staticActor.remove(pActor);
}

void PhysicsHandler::RemoveDynamicActor(Actor* pActor)
{
	m_dynamicActor.remove(pActor);
}


void PhysicsHandler::CheckActorsCollisions(Actor* pActor1, Actor* pActor2)
{
	for (Collider* pCollider1 : pActor1->m_colliders)
	{
		for (Collider* pCollider2 : pActor2->m_colliders)
		{
			for (uint8 tagToIgnore : pCollider1->m_ignoredtag)
				if (tagToIgnore == pCollider2->m_tag)
					return;

			for (uint8 tagToIgnore : pCollider2->m_ignoredtag)
				if (tagToIgnore == pCollider1->m_tag)
					return;

			if (DetectCollisions(pCollider1, pCollider2))
			{
				// TODO CollisionEnter CallBack
				pActor1->OnCollision(pCollider1, pCollider2);
				pActor2->OnCollision(pCollider2, pCollider1);
			}
			else
			{
				//TODO CollisionExit CallBack
			}
		}
	}
}

bool PhysicsHandler::DetectCollisions(Collider* p1, Collider* p2)
{
	if ((p1)->GetShape() == Collider::ColliderShape::BOX)
	{
		if ((p2)->GetShape() == Collider::ColliderShape::BOX)
			return DetectCollisions(dynamic_cast<BoxCollider*>(p1), dynamic_cast<BoxCollider*>(p2));
	}

	return false;
}

bool PhysicsHandler::DetectCollisions(BoxCollider* pBox1, BoxCollider* pBox2)
{
	Vector2f pos1 = pBox1->GetWorldColliderTransform().GetPosition();
	Vector2f pos2 = pBox2->GetWorldColliderTransform().GetPosition();

	Vector2f size1 = pBox1->GetWorldColliderTransform().GetScale() * pBox1->GetSize();
	Vector2f size2 = pBox2->GetWorldColliderTransform().GetScale() * pBox2->GetSize();

	if (!(pos1.X() > (pos2.X() + size2.X()) || pos1.X() + size1.X() < pos2.X())
		 || pos1.Y() > pos2.Y() + size2.Y() || pos1.Y() + size1.Y() < pos2.Y())
	{
		return true;
	}
	return false;
}
