#ifndef SHROOM_ENGINE_SCRIPT_COMPONENT_H
#define SHROOM_ENGINE_SCRIPT_COMPONENT_H


#include "Component.h"

namespace shroom
{
	class ScriptComponent : public Component
	{
	public:

		ScriptComponent() = delete;
		ScriptComponent(Actor* pOwner);
		virtual ~ScriptComponent();

		virtual void OnStart() {};
		virtual void Update() {};
		virtual void OnEnd() {};
		virtual void OnInputPressed(SDL_Event event) {};
		virtual void Destroy() {};

		virtual ScriptComponent* Duplicate() = 0;

		virtual void DuplicateValues(Component& out) = 0;

	protected:

	private:

	};

};
#endif 