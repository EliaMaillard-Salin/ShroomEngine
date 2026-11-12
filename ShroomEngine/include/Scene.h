#ifndef SHROOM_ENGINE_SCENE_H
#define SHROOM_ENGINE_SCENE_H

#include <SDL_events.h>
#include <string>
#include <list>
#include <Define.h>
#include "Actor.h"

namespace shroom
{
	class Renderer;
	class Actor;

	class Scene
	{
	public:
		Scene(const char* name);
		void Init(Renderer* pRenderer);

		void Start();
		void BeginFrame();
		void EndFrame();
		void Close();
		bool IsLoaded();
		std::string GetName();

		Actor& CreateActor();
		void AddActorInScene(Actor& actor);
		void DestroyActor(Actor& actorTodestroy);

		void Destroy();

		// Virtual Function
		virtual void OnUpdate() {}
		virtual void OnFixedUpdate() {}
		virtual void OnRender() {}
		virtual void OnInputCalled(SDL_Event event) {}
		virtual void OnAssetLoaded() {};
		virtual void OnAssetUnloaded() {};

	private:
		void LoadAssets();
		void UnloadAssets();
		void FixedUpdate();
		void Update();
		void Render();
		void CallEvent(SDL_Event event);

		void HandleActorCreation();
		void HandleActorDeletion();

	protected:
		Renderer* m_pRenderer;

	private:
		std::list<Actor*> m_actorToConstruct;
		std::list<Actor*> m_actorToDestroy;
		std::list<Actor*> m_actorInScene;
		// Physics Actor ?
	
		std::string m_name;
		bool m_isLoaded;

		friend class GameManager;
	};
};

#endif // !SHROOM_ENGINE_SCENE_H
