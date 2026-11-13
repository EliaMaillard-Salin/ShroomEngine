#ifndef SHROOM_ENGINE_COLLIDER_H
#define SHROOM_ENGINE_COLLIDER_H

#include "Component.h"

#include "Transform2D.h"
#include <list>

namespace shroom 
{

	class Collider : public Component
	{
	public:
		enum CollisionType
		{
			BLOCK,
			OVERLAP,
		};
		enum ColliderShape
		{
			BOX,
			SPHERE
		};


		Collider() = delete;
		Collider(std::string name,Actor* pOwner);
		virtual ~Collider();

		void AddIgnoredColliderTag(uint8 tag);
		void SetTag(uint8 tag);
		void RemoveIgnoredColliderTag(uint8 tag);

		Transform2D& GetRelativeColliderTransform();
		Transform2D GetWorldColliderTransform();

		ColliderShape GetShape();

		virtual void OnCollisionEnter(Collider* pOtherCollider) {};
		virtual void OnCollisionExit(Collider* pOtherCollider) {};
		virtual void OnCollision(Collider* pOtherCollider) {};

		virtual Component* Duplicate() = 0;
		virtual void DuplicateValues(Component& out);

		virtual void Destroy() override;

	protected:
		ColliderShape m_shape;
		Transform2D m_colliderTransform;
		CollisionType m_types;
		uint8 m_tag;
		std::list<uint8> m_ignoredtag;
		std::list<Collider*>::iterator m_posInList;

		friend Actor;
		friend class PhysicsHandler;
	};
}

#endif // !SHROOM_ENGINE_BOX_COLLIDER_H
