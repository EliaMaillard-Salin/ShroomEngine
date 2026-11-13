#ifndef SHROOM_ENGINE_BOX_COLLIDER_H
#define SHROOM_ENGINE_BOX_COLLIDER_H

#include "Collider.h"

#include "Transform2D.h"
#include "Vectors.h"

namespace shroom 
{

	class BoxCollider : public Collider
	{
	public:
		BoxCollider() = delete;
		BoxCollider(std::string name, Actor* pOwner);
		~BoxCollider() = default;
		

		//void SetSize();
		void SetWidth(float w);
		void SetHeight(float h);
		void SetDepth(float d);

		Vector2f& GetSize();

		Component* Duplicate() override;
		virtual void DuplicateValues(Component& out) override;

	private:
		Vector2f m_size; // to vec3
	};
}

#endif // !SHROOM_ENGINE_BOX_COLLIDER_H
