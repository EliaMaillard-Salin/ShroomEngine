#ifndef SHROOM_ENGINE_GAME_MANAGER_H
#define SHROOM_ENGINE_GAME_MANAGER_H



#include <string>
#include <Define.h>
#include "Vector2.h"
#include <map>

namespace shroom
{
	class Window;
	class Renderer;
	class Scene;


	class GameManager
	{
	public:
		GameManager(const char* gameTitle, Vector2<uint16> screenSize);
		GameManager(GameManager const&) = delete;
		GameManager& operator=(GameManager const&) = delete;
		~GameManager();

		void Init();

		void Launch();

		void GameLoop();
		void CloseGame();


		void LoadScene(std::string sceneName);
		void UnloadScene(std::string sceneName);
		void SetActiveScene(std::string sceneName);

		void AddSceneInGameManager(Scene& rScene);
		void RemoveSceneFromGameManager(std::string sceneName);

	private:
		void Render();
		void Inputs(); // Events ? 

	private:
		uptr<Window>m_pWindow;
		uptr<Renderer> m_pRenderer;
		std::map<std::string, uptr<Scene>> m_scenes;
		Scene* m_pActiveScene;

		std::string m_gameTitle;
		bool m_isRunning;
		Vector2<uint16> m_screenSize;
	};

};

#endif // !SHROOM_ENGINE_GAME_MANAGER_H
