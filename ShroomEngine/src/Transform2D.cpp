#include "Transform2D.h"

using namespace shroom;

Transform2D::Transform2D(Transform2D const& other) :
	m_position(other.m_position), m_scale(other.m_scale), m_rotation(other.m_rotation)
{}
Transform2D Transform2D::operator=(Transform2D const& other)
{
	m_position = other.m_position;
	m_scale = other.m_scale;
	m_rotation = other.m_rotation;

	return *this;
}

Transform2D::Transform2D(Vector2f position, Vector2f scale, float rotation):
	m_position(position), m_scale(scale),m_rotation(rotation)
{}

// == SET ==

void Transform2D::SetPosition(Vector2f const& position)
{
	m_position = position;
}
void Transform2D::SetPosition(float x, float y)
{
	m_position = { x,y };
}
void Transform2D::SetPositionX(float x)
{
	m_position.X() = x;
}
void Transform2D::SetPositionY(float y)
{
	m_position.Y() = y;
}

void Transform2D::SetScale(Vector2f const& scale)
{
	m_scale = scale;
}
void Transform2D::SetScale(float x, float y)
{
	m_scale = { x,y };
}
void Transform2D::SetScaleX(float x)
{
	m_scale.X() = x;
}
void Transform2D::SetScaleY(float y)
{
	m_scale.Y() = y;
}
void Transform2D::SetRotation(float zRotation)
{
	m_rotation = m_rotation;
}

// == GET ==

Vector2f Transform2D::GetPosition()
{
	return m_position;
}
Vector2f Transform2D::GetScale()
{
	return m_scale;
}
float Transform2D::GetRotation()
{
	return m_rotation;
}

// == ADD ==

void Transform2D::AddPosition(Vector2f const& position)
{
	m_position += position;
}
void Transform2D::AddPosition(float x, float y)
{
	m_position += {x, y};
}
void Transform2D::AddPositionX(float x)
{
	m_position.X() += x;
}
void Transform2D::AddPositionY(float y)
{
	m_position.Y() += y;
}
void Transform2D::AddScale(Vector2f const& scale)
{
	m_scale += scale;
}
void Transform2D::AddScale(float x, float y)
{
	m_scale += {x, y};
}
void Transform2D::AddScaleX(float x)
{
	m_scale.X() += x;
}
void Transform2D::AddScaleY(float y)
{
	m_scale.Y() += y;
}
void Transform2D::AddRotation(float rotation)
{
	m_rotation += rotation;
}