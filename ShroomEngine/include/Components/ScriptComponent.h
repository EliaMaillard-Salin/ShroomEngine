#ifndef SHROOM_ENGINE_SCRIPT_COMPONENT_H
#define SHROOM_ENGINE_SCRIPT_COMPONENT_H


#include "Component.h"
#include <list>

namespace shroom
{
	class ScriptComponent : public Component
	{
	public:

		ScriptComponent() = delete;
		ScriptComponent(std::string name, Actor* pOwner);
		virtual ~ScriptComponent();

		virtual void OnStart() {};
		virtual void Update() {};
		virtual void OnEnd() {};
		virtual void OnInputPressed(SDL_Event event) {};
		virtual void Destroy() {};

		virtual void OnCollisionEnter(Collider* pOwnedCollider, Collider* pOtherCollider) {};
		virtual void OnCollisionExit(Collider* pOwnedCollider, Collider* pOtherCollider) {};
		virtual void OnCollision(Collider* pOwnedCollider, Collider* pOtherCollider) {};


		virtual Component* Duplicate() = 0;

		virtual void DuplicateValues(Component& out);

	private:
		std::list<ScriptComponent*>::iterator m_posInList;

		friend Actor;
	};

};
#endif 