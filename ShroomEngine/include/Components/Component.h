#ifndef SHROOM_ENGINE_COMPONENT_H
#define SHROOM_ENGINE_COMPONENT_H


#include "Define.h"

#include "SDL_events.h"

namespace shroom
{
	class Actor;

	class Component
	{
	public:
		enum ComponentType
		{
			NONE,
			BOX_COLLIDER,
		};


		Component() = delete;
		Component(Actor* pOwner);
		virtual ~Component();

		virtual void OnStart() {}
		virtual void Update() {}
		virtual void OnInputPressed(SDL_Event event) {}
		virtual void OnEnd() {}

		virtual void Destroy();

		virtual Component* Duplicate() = 0;

		virtual void DuplicateValues(Component& out);

	protected:
		bool m_isActive;
		Actor* m_pOwner;
		int16 m_UpdateOrder;

	private:

	};

};
#endif 