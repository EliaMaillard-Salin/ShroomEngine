#include "GameManager.h"
#include <Window.h>
#include <Renderer.h>
#include "Logger.h"
#include "Drawable2DShapes.h"
#include "Scene.h"
#include "Time.h"

using namespace shroom;


GameManager::GameManager(const char* gameTitle, Vector2<uint16> screenSize): 
	m_gameTitle(gameTitle), m_pWindow(nullptr), m_isRunning(false), 
	m_pRenderer(nullptr), m_screenSize(screenSize), m_pActiveScene(nullptr)
{
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
		Logger::Error(LogType::ERROR, "SDL initialization failed.");
	else
		Logger::Info("SDL initialization succeeded!");
}

shroom::GameManager::~GameManager()
{
	m_pWindow.reset();
	m_pRenderer.reset();

}

void GameManager::Init()
{
	m_pWindow = std::make_unique<Window>(m_screenSize);
	m_pWindow->Open(m_gameTitle.c_str());
	m_pRenderer = std::make_unique<Renderer>();
	m_pRenderer->Initialize(*m_pWindow);
}

void GameManager::Launch()
{
	m_isRunning = true;
	GameLoop();
}


void GameManager::GameLoop()
{
	while (m_isRunning)
	{
		Time::ComputeDeltaTime();
		m_pActiveScene->HandleActorCreation();
		Inputs(); // Event
		m_pActiveScene->FixedUpdate();
		m_pActiveScene->Update();

		Render();
		m_pActiveScene->HandleActorDeletion();

		Time::DelayTime();
	}

	CloseGame();
}

void GameManager::CloseGame()
{
	// TODO : Destroy Actors in Game
	Logger::Info("TODO : Destroy all GameObjects : GameManager::CloseGame");
	for (std::map<std::string,uptr<Scene>>::iterator it = m_scenes.begin(); it != m_scenes.end(); it++)
	{
		uptr<Scene> toDelete = std::move(it->second);
		toDelete->Destroy();
		toDelete.reset();
	}
	m_scenes.clear();
	m_pWindow->Close();
	m_pRenderer->Close();
}

void GameManager::Render()
{
	// TODO : Call Actors Render
	m_pRenderer->BeginDraw();

	m_pActiveScene->Render();
	
	m_pRenderer->EndDraw();
}

void GameManager::Inputs()
{
	// TODO : Check Inputs/Event
	SDL_Event event;
	while (SDL_PollEvent(&event))
	{
		switch (event.type)
		{
		case SDL_QUIT:
			m_isRunning = false;
			break;
		default:
			m_pActiveScene->CallEvent(event);
			break;
		}
	}

}

void GameManager::LoadScene(std::string sceneName)
{
	std::map<std::string, uptr<Scene>>::iterator it = m_scenes.find(sceneName);
	if (it == m_scenes.end())
	{
		Logger::Info("Unable to Load : " + sceneName + ". Scene not in GameManager.");
		return;
	}
	Scene& rScene = *(it->second);
	if (rScene.IsLoaded() == false)
		rScene.LoadAssets();
}
void GameManager::UnloadScene(std::string sceneName)
{
	std::map<std::string, uptr<Scene>>::iterator it = m_scenes.find(sceneName);
	if (it == m_scenes.end())
	{
		Logger::Info("Unable to Unload : "+ sceneName + ". Scene not in GameManager.");
		return;
	}
	Scene& rScene = *(it->second);
	if (rScene.IsLoaded())
		rScene.UnloadAssets();
}
void GameManager::SetActiveScene(std::string sceneName)
{
	std::map<std::string, uptr<Scene>>::iterator it = m_scenes.find(sceneName);
	if (it == m_scenes.end())
	{
		Logger::Info("Unable to Load : " + sceneName + ". Scene not in GameManager.");
		return;
	}
	m_pActiveScene = (it->second).get();
	if (m_pActiveScene->IsLoaded() == false)
		m_pActiveScene->LoadAssets();
}

void GameManager::AddSceneInGameManager(Scene& rScene)
{
	rScene.Init(m_pRenderer.get());
	if (m_scenes.find(rScene.GetName()) != m_scenes.end())
	{
		Logger::Info("A Scene Named " + rScene.GetName() + " already in GameManager");
		return;
	}
	m_scenes.insert({ rScene.GetName(), std::make_unique<Scene>(rScene)});
}

void GameManager::RemoveSceneFromGameManager(std::string sceneName)
{
	if (m_scenes.find(sceneName) == m_scenes.end())
	{
		Logger::Info("Not Scene named " + sceneName + " in GameManager");
		return;
	}
	m_scenes.erase(sceneName);
}