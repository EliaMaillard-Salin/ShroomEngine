#include "Actor.h"
#include "Components.h"
#include "Scene.h"
#include "PhysicHandler.h"

#include <typeinfo>

using namespace shroom;

Actor::Actor() : 
	m_transform({}),m_components({}),m_pScene(nullptr),m_state(ACTIVE),
	m_isStatic(false), m_isCreated(false)
{}

Actor::Actor(Actor const& other):
	m_transform(other.m_transform), m_components({}), m_pScene(nullptr), m_state(ACTIVE),
	m_isStatic(false)
{
	for (std::map<std::string, Component*>::const_iterator it = other.m_components.begin(); it != other.m_components.end(); it++)
	{
		m_components.insert({ it->first,it->second->Duplicate()});
	}
}

Actor& Actor::operator=(Actor const& other)
{
	m_transform = other.m_transform;
	m_pScene = nullptr;
	m_state = ACTIVE;
	for (std::map<std::string, Component*>::const_iterator it = other.m_components.begin(); it != other.m_components.end(); it++)
	{
		m_components.insert({ it->first,it->second->Duplicate() });
	}
	return *this;
}

Actor::~Actor()
{
	m_pScene = nullptr;
	m_components.clear();
}

void Actor::SetActive(bool active){}
bool Actor::IsActive() { return m_state == ACTIVE; }

void Actor::RemoveComponent(std::string componentName) {}
void Actor::Start()
{

	if (m_isColliding)
	{
		if (m_isStatic)
			PhysicsHandler::AddStaticActor(this);
		else
			PhysicsHandler::AddDynamicActor(this);
	}
	else
	{
		if (m_isStatic)
			PhysicsHandler::RemoveStaticActor(this);
		else
			PhysicsHandler::RemoveDynamicActor(this);
	}
	m_isCreated = true;
}


void Actor::Update()
{
	for (auto it : m_components)
	{
		it.second->Update();
	}
}
void Actor::FixedUpdate()
{
	for (auto it : m_components)
	{
		it.second->FixedUpdate();
	}
}


void Actor::OnInputCalled(SDL_Event event)
{
	for (auto pComp : m_components)
	{
		pComp.second->OnInputPressed(event);
	}
}

Transform2D& Actor::GetTransform()
{
	return m_transform;
}

Scene* shroom::Actor::GetScene()
{
	return m_pScene;
}

void Actor::Destroy()
{
	if (m_state == ActorState::DEAD)
		return;
	m_pScene->DestroyActor(*this);
	m_state = ActorState::DEAD;
}

void Actor::Delete()
{
	m_pScene = nullptr;
	for (auto it = m_components.begin(); it != m_components.end(); it++)
	{
		Component* pComp = it->second;
		it->second = nullptr;
		pComp->Destroy();
		delete pComp;
	}
	m_components.clear();
}

void Actor::OnCollisionEnter(Collider* pOwnedCollider, Collider* pOtherCollider)
{
	pOwnedCollider->OnCollisionEnter(pOtherCollider);
	for (ScriptComponent* pScripts : m_scripts)
	{
		pScripts->OnCollisionEnter(pOwnedCollider, pOtherCollider);
	}
}
void Actor::OnCollisionExit(Collider* pOwnedCollider, Collider* pOtherCollider)
{
	pOwnedCollider->OnCollisionExit(pOtherCollider);
	for (ScriptComponent* pScripts : m_scripts)
	{
		pScripts->OnCollisionExit(pOwnedCollider, pOtherCollider);
	}
}
void Actor::OnCollision(Collider* pOwnedCollider, Collider* pOtherCollider)
{
	pOwnedCollider->OnCollision(pOtherCollider);
	for (ScriptComponent* pScripts : m_scripts)
	{
		pScripts->OnCollision(pOwnedCollider, pOtherCollider);
	}
}

void Actor::SetStatic(bool isStatic)
{
	if (m_isStatic == isStatic)
		return;
	if (m_isColliding == false)
		return;

	m_isStatic = isStatic;
	if (m_isStatic)
	{
		PhysicsHandler::RemoveDynamicActor(this);
		PhysicsHandler::AddStaticActor(this);
	}
	else 
	{
		PhysicsHandler::AddDynamicActor(this);
		PhysicsHandler::RemoveStaticActor(this);
	}
}
bool Actor::IsStatic()
{
	return m_isStatic;
}

void Actor::SetHasCollisions(bool hasCollisions)
{
	if (m_isColliding == hasCollisions)
		return;
	m_isColliding = hasCollisions;

	if (m_isCreated == false)
		return;

	if (m_isColliding)
	{
		if (m_isStatic)
			PhysicsHandler::AddStaticActor(this);
		else
			PhysicsHandler::AddDynamicActor(this);
	}
	else
	{
		if (m_isStatic)
			PhysicsHandler::RemoveStaticActor(this);
		else
			PhysicsHandler::RemoveDynamicActor(this);
	}
}

void Actor::AddScript(ScriptComponent* pScript)
{
	m_scripts.push_back(pScript);
	pScript->m_posInList = (m_scripts.end()--);
}
void Actor::AddCollider(Collider* pCollider)
{
	m_colliders.push_back(pCollider);
	pCollider->m_posInList = (m_colliders.end()--);
}

void Actor::RemoveScript(ScriptComponent* pScript)
{
	m_scripts.erase(pScript->m_posInList);
}
void Actor::RemoveCollider(Collider* pCollider)
{
	m_colliders.erase(pCollider->m_posInList);
}