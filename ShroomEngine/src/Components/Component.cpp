#include "Component.h"

using namespace shroom;

Component::Component(Actor* pOwner) :
	m_pOwner(pOwner), m_isActive(true),m_UpdateOrder(0)
{}

Component::~Component()
{
	m_pOwner = nullptr;
}

void Component::Destroy()
{
	m_pOwner = nullptr;
}

void Component::DuplicateValues(Component& out)
{
	out.m_isActive = m_isActive;
	out.m_pOwner = m_pOwner;
	out.m_UpdateOrder = m_UpdateOrder;
}