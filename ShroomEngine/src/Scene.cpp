#include "Scene.h"
#include <Renderer.h>
#include <Drawable2DShapes.h>
using namespace shroom;

Scene::Scene(const char* name) :
	m_name(name),m_isLoaded(false),m_pRenderer(nullptr)
{}

void Scene::Init(Renderer* pRenderer)
{
	m_pRenderer = pRenderer;
}

void Scene::Start()
{
}

void Scene::BeginFrame()
{}

void Scene::FixedUpdate()
{
	OnFixedUpdate();
	for (auto it : m_actorInScene)
	{
		it->FixedUpdate();
	}
}

void Scene::Update()
{
	OnUpdate();
	for (auto it : m_actorInScene)
	{
		it->Update();
	}
}

void Scene::Render()
{
	OnRender();
	for (auto it : m_actorInScene)
	{
		it->GetTransform().GetPosition();
		Rectangle rect = { it->GetTransform().GetPosition(),{10.0f * it->GetTransform().GetScale().X(),10.0f * it->GetTransform().GetScale().Y()}};
		m_pRenderer->DrawShape2D(rect);
	}
	// TODO Add Draw Actor
}

void Scene::CallEvent(SDL_Event event)
{
	OnInputCalled(event);
	for (auto it : m_actorInScene)
	{
		it->OnInputCalled(event);
	}
	// TODO Call Actor InputCalled
}

void Scene::EndFrame()
{}

void Scene::LoadAssets()
{
	OnAssetLoaded();
	m_isLoaded = true;
}

void Scene::UnloadAssets()
{
	OnAssetUnloaded();
	m_isLoaded = false;
}

void Scene::Close()
{}

bool Scene::IsLoaded() { return m_isLoaded; }
std::string Scene::GetName() { return m_name; }


Actor& Scene::CreateActor()
{
	Actor* pActor = new Actor();
	m_actorToConstruct.push_back(pActor);
	pActor->m_pScene = this;
	return *pActor;
}
void Scene::AddActorInScene(Actor& actor)
{
	m_actorToConstruct.push_back(&actor);
}
void Scene::DestroyActor(Actor& actorTodestroy)
{
	m_actorToDestroy.push_back(&actorTodestroy);
}

void Scene::HandleActorCreation()
{
	for (std::list<Actor*>::iterator it = m_actorToConstruct.begin(); it != m_actorToConstruct.end(); it++)
	{
		Actor* pActor = *it;
		m_actorInScene.push_back(pActor);
		*it = nullptr;
		pActor->m_posInSceneList = (m_actorInScene.end()--);
		pActor->Start();
	}
	m_actorToConstruct.clear();
}

void Scene::HandleActorDeletion()
{
	for (std::list<Actor*>::iterator it = m_actorToDestroy.begin(); it != m_actorToDestroy.end(); it++)
	{
		Actor* pActor = *it;
		m_actorInScene.remove(pActor);
		pActor->Delete();
		delete pActor;
		*it = nullptr;
	}
	m_actorToDestroy.clear();
}

void Scene::Destroy()
{
	for (std::list<Actor*>::iterator it = m_actorToConstruct.begin(); it != m_actorToConstruct.end(); it++)
	{
		Actor* pActor = *it;
		delete pActor;
		*it = nullptr;
	}
	m_actorToConstruct.clear();
	HandleActorDeletion();
	for (std::list<Actor*>::iterator it = m_actorInScene.begin(); it != m_actorInScene.end(); it++)
	{
		Actor* pActor = *it;
		delete pActor;
		*it = nullptr;
	}
	m_actorInScene.clear();
}