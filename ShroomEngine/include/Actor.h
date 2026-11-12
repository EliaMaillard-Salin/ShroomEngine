#ifndef SHROOM_ENGINE_ACTOR_H
#define SHROOM_ENGINE_ACTOR_H

#include "SDL_events.h"

#include <map>
#include "Define.h"
#include "Transform2D.h"
#include "Components/Component.h"
#include <string>
#include <list>

namespace shroom
{
	class Scene;
	class Component;

	class Actor
	{
	
	public:
		enum ActorState
		{
			IN_CREATION,
			ACTIVE,
			PAUSED,
			DEAD,
		};

		Actor();
		Actor(Actor const& other);
		Actor& operator=(Actor const& other);
		~Actor();

		void SetActive(bool active);
		bool IsActive();

		template <typename T>
		T& AddComponent(std::string componentName);
		void RemoveComponent(std::string componentName);

		template <typename T>
		T& GetComponent(std::string componentName);

		Transform2D& GetTransform();

		void Start();

		void Update();
		void OnInputCalled(SDL_Event event);
		void Destroy();

	private:
		void Delete();

	private:
		Scene* m_pScene;
		ActorState m_state;
		std::map<std::string,Component*> m_components;
		Transform2D m_transform;  // TODO Change to Transform3D
		std::list<Actor*>::iterator m_posInSceneList;

		friend Scene;
	};

	template <typename T>
	inline T& Actor::AddComponent(std::string componentName)
	{
		Component* pComponent = new T(this);
		m_components.insert({ componentName,pComponent });
		return *(dynamic_cast<T*>(pComponent));
	}

	template <typename T>
	inline T& Actor::GetComponent(std::string componentName)
	{
		return *(m_components[componentName]);

	}

}

#endif // !SHROOM_ENGINE_ACTOR_H
