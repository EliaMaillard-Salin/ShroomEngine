#include "Scene.h"
#include "Renderer.h"


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
{}

void Scene::Update()
{}

void Scene::Render()
{}

void Scene::CallEvent(SDL_Event event)
{}

void Scene::EndFrame()
{}

void Scene::LoadAssets()
{
	m_isLoaded = true;
}

void Scene::UnloadAssets()
{
	m_isLoaded = false;
}

void Scene::Close()
{}

bool Scene::IsLoaded() { return m_isLoaded; }
std::string Scene::GetName() { return m_name; }