#ifndef SHROOM_ENGINE_PHYSICS_HANDLER_H
#define SHROOM_ENGINE_PHYSICS_HANDLER_H

#include <list>

namespace shroom
{
	class Collider;
	class BoxCollider;
	class Actor;
	class PhysicsHandler
	{
	public:

		static void CheckCollision();

		static void AddStaticActor(Actor* pActor);
		static void AddDynamicActor(Actor* pActor);
		static void RemoveStaticActor(Actor* pActor);
		static void RemoveDynamicActor(Actor* pActor);

	private:
		static void CheckActorsCollisions(Actor* pActor1, Actor* pActor2);

		static bool DetectCollisions(Collider* p1, Collider* p2);
		static bool DetectCollisions(BoxCollider* pBox1, BoxCollider* pBox2);

	private:
		static std::list<Actor*> m_staticActor;
		static std::list<Actor*> m_dynamicActor;
	};
}

#endif // !1
