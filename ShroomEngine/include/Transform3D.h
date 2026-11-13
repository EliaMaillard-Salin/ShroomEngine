#ifndef SHROOM_ENGINE_TRANSFORM_2D_H
#define SHROOM_ENGINE_TRANSFORM_2D_H

#include "Vectors.h"


namespace shroom
{

	class Transform2D
	{
	public:
		Transform2D() = default;
		Transform2D(Transform2D const& other);
		Transform2D operator=(Transform2D const& other);

		Transform2D(Vector2f position, Vector2f scale, float rotation);

		// == SET ==

		void SetPosition(Vector2f const& position);
		void SetPosition(float x, float y);
		void SetPositionX(float x);
		void SetPositionY(float y);

		void SetScale(Vector2f const& scale);
		void SetScale(float x, float y);
		void SetScaleX(float x);
		void SetScaleY(float y);

		void SetRotation(float zRotation);

		// == GET ==

		Vector2f GetPosition();
		Vector2f GetScale();
		float GetRotation();

		// == ADD ==

		void AddPosition(Vector2f const& position);
		void AddPosition(float x, float y);
		void AddPositionX(float x);
		void AddPositionY(float y);

		void AddScale(Vector2f const& scale);
		void AddScale(float x, float y);
		void AddScaleX(float x);
		void AddScaleY(float y);

		void AddRotation(float rotation);


	private:
		Vector2f m_position = { 0.0f,0.0f };
		Vector2f m_scale = { 1.0f,1.0f };
		float m_rotation = 0.0f;
	};

}

#endif // !SHROOM_ENGINE_TRANSFORM_2D_H
