#ifndef RENDER_DRAWABLE_2D_SHAPES_H
#define RENDER_DRAWABLE_2D_SHAPES_H

#include <Vectors.h>


struct Rectangle
{
	Vector2f position = Vector2f::Zero();
	Vector2f dimensions = Vector2f::Zero();
};

struct Circle
{
	Vector2f position = Vector2f::Zero();
	float radius = 0.0f;
};

struct Ellipse
{
	Vector2f position = Vector2f::Zero();
	Vector2f dimensions = Vector2f::Zero();
};

#endif // !RENDER_DRAWABLE_3D_SHAPES_H
