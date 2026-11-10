#ifndef SHROOM_ENGINE_GAME_MANAGER_H
#define SHROOM_ENGINE_GAME_MANAGER_H

#include <string>
#include "Define.h"
#include "Vector2.h"
#include <map>

class Window;
class Renderer;
class Scene;


class GameManager
{
public:
	GameManager(const char* gameTitle, Vector2<uint16> screenSize);
	GameManager(GameManager const&) = delete;
	GameManager& operator=(GameManager const&) = delete;

	void Init();

	void Launch();

	void GameLoop();
	void CloseGame();


	void LoadScene(std::string sceneName);
	void UnloadScene(std::string sceneName);
	void SetActiveScene(std::string sceneName);

	void AddSceneInGameManager(Scene* pScene);
	void RemoveSceneFromGameManager(std::string sceneName);

private:
	void Update();
	void FixedUpdate();
	void Render();
	void Inputs(); // Events ? 

private:
	std::map<std::string,Scene*> m_scenes;
	Scene* m_pActiveScene;
	std::string m_gameTitle;
	Window* m_pWindow;
	Renderer* m_pRenderer;
	bool m_isRunning;
	Vector2<uint16> m_screenSize;
};


#endif // !SHROOM_ENGINE_GAME_MANAGER_H
