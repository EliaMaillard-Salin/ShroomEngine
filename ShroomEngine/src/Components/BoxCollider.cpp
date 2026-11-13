#include "BoxCollider.h"

using namespace shroom;

BoxCollider::BoxCollider(std::string name, Actor* pOwner):
	Collider(name, pOwner), m_size(10.0f,10.0f)
{
	m_shape = BOX;
}

void BoxCollider::SetWidth(float w)
{
	m_size.X() = w;
}

void BoxCollider::SetHeight(float h)
{
	m_size.Y() = h;
}

void BoxCollider::SetDepth(float d)
{
}

Vector2f& BoxCollider::GetSize()
{
	return m_size;
}

Component* BoxCollider::Duplicate()
{
	Component* pNewComp = new BoxCollider(m_name + "1", m_pOwner);
	DuplicateValues(*pNewComp);
	return pNewComp;
}

void BoxCollider::DuplicateValues(Component& out)
{
	Collider::DuplicateValues(out);
	BoxCollider* pBox = dynamic_cast<BoxCollider*>(&out);
	pBox->m_size = m_size;
}