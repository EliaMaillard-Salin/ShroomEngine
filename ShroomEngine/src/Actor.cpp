#include "Actor.h"
#include "Components/Component.h"
#include "Scene.h"

#include <typeinfo>

using namespace shroom;

Actor::Actor() : 
	m_transform({}),m_components({}),m_pScene(nullptr),m_state(IN_CREATION)
{}

Actor::Actor(Actor const& other):
	m_transform(other.m_transform), m_components({}), m_pScene(nullptr), m_state(IN_CREATION)
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
	m_state = IN_CREATION;
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
void Actor::Start(){}
void Actor::Update(){}

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

void Actor::Destroy()
{
	m_pScene->DestroyActor(*this);
}

void Actor::Delete()
{
	m_pScene = nullptr;
	for (auto it = m_components.begin(); it != m_components.end(); it++)
	{
		it->second->Destroy();
	}
	m_components.clear();
}