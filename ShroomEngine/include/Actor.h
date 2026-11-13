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
	class ScriptComponent;

	class Actor
	{
	
	public:
		enum ActorState
		{
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

		Scene* GetScene();

		void Start();

		void Update();
		void FixedUpdate();
		void OnInputCalled(SDL_Event event);
		void Destroy();

		void SetStatic(bool isStatic);
		bool IsStatic();

		void SetHasCollisions(bool hasCollisions);

		void AddScript(ScriptComponent* pScript);
		void AddCollider(Collider* pCollider);
		void RemoveScript(ScriptComponent* pScript);
		void RemoveCollider(Collider* pCollider);

	private:
		void Delete();
		void OnCollisionEnter(Collider* pOwnedCollider, Collider* pOtherCollider);
		void OnCollisionExit(Collider* pOwnedCollider, Collider* pOtherCollider);
		void OnCollision(Collider* pOwnedCollider, Collider* pOtherCollider);

	private:
		Scene* m_pScene;
		ActorState m_state;
		std::map<std::string,Component*> m_components;
		std::list<Collider*> m_colliders;
		std::list<ScriptComponent*> m_scripts;

		Transform2D m_transform;  // TODO Change to Transform3D
		std::list<Actor*>::iterator m_posInSceneList;

		bool m_isStatic;
		bool m_isColliding;
		bool m_isCreated;

		friend Scene;
		friend class PhysicsHandler;
	};

	template <typename T>
	inline T& Actor::AddComponent(std::string componentName)
	{
		Component* pComponent = new T(componentName,this);
		m_components.insert({ componentName,pComponent });
		return *(dynamic_cast<T*>(pComponent));
	}

	template <typename T>
	inline T& Actor::GetComponent(std::string componentName)
	{
		return *(dynamic_cast<T*>(m_components[componentName]));

	}

}

#endif // !SHROOM_ENGINE_ACTOR_H
