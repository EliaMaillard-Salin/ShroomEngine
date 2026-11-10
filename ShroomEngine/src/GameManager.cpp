#include "GameManager.h"
#include <Window.h>
#include <Renderer.h>
#include "Logger.h"
#include "Drawable2DShapes.h"
#include "Scene.h"

GameManager::GameManager(const char* gameTitle, Vector2<uint16> screenSize): 
	m_gameTitle(gameTitle), m_pWindow(nullptr), m_isRunning(false), m_pRenderer(nullptr), m_screenSize(screenSize)
{
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
		Logger::Error(LogType::ERROR, "SDL initialization failed.");
	else
		Logger::Info("SDL initialization succeeded!");
}

void GameManager::Init()
{
	m_pWindow = new Window(m_screenSize);
	m_pWindow->Open(m_gameTitle.c_str());
	m_pRenderer = new Renderer();
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
		// TODO : Object creation
		Inputs(); // Event

		FixedUpdate();

		Update();
		
		Render();

		// TODO : Object deletion
	}

	CloseGame();
}

void GameManager::CloseGame()
{
	// TODO : Destroy Actors in Game
	Logger::Info("TODO : Destroy all GameObjects : GameManager::CloseGame");

	m_pWindow->Close();
}

void GameManager::Update()
{
	// TODO : Call Actors Update
	m_pActiveScene->Update();
}


void GameManager::FixedUpdate()
{
	// TODO : Call Actors Fixed Update
	m_pActiveScene->FixedUpdate();
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
	std::map<std::string, Scene*>::iterator it = m_scenes.find(sceneName);
	if (it == m_scenes.end())
	{
		Logger::Info("Unable to Load : " + sceneName + ". Scene not in GameManager.");
		return;
	}
	Scene* pScene = it->second;
	if (pScene->IsLoaded() == false)
		pScene->LoadAssets();
}
void GameManager::UnloadScene(std::string sceneName)
{
	std::map<std::string, Scene*>::iterator it = m_scenes.find(sceneName);
	if (it == m_scenes.end())
	{
		Logger::Info("Unable to Unload : "+ sceneName + ". Scene not in GameManager.");
		return;
	}
	Scene* pScene = it->second;
	if (pScene->IsLoaded())
		pScene->UnloadAssets();
}
void GameManager::SetActiveScene(std::string sceneName)
{
	std::map<std::string, Scene*>::iterator it = m_scenes.find(sceneName);
	if (it == m_scenes.end())
	{
		Logger::Info("Unable to Load : " + sceneName + ". Scene not in GameManager.");
		return;
	}
	m_pActiveScene = it->second;
	if (m_pActiveScene->IsLoaded() == false)
		m_pActiveScene->LoadAssets();
}

void GameManager::AddSceneInGameManager(Scene* pScene)
{
	pScene->Init(m_pRenderer);
	if (m_scenes.find(pScene->GetName()) != m_scenes.end())
	{
		Logger::Info("A Scene Named " + pScene->GetName() + " already in GameManager");
		return;
	}
	m_scenes.insert({ pScene->GetName(),pScene });
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