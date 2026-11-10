#ifndef SHROOM_ENGINE_SCENE_H
#define SHROOM_ENGINE_SCENE_H

#include <SDL_events.h>
#include <string>

class Renderer;

class Scene
{
public:
	Scene(const char* name);
	void Init(Renderer* pRenderer);

	void Start();
	void BeginFrame();
	void EndFrame();
	void LoadAssets();
	void UnloadAssets();
	void Close();	
	bool IsLoaded();
	std::string GetName();

	virtual void OnUpdate() {}
	virtual void OnFixedUpdate() {}
	virtual void OnRender() {}

private:
	void FixedUpdate();
	void Update();
	void Render();
	void CallEvent(SDL_Event event);


private:
	Renderer* m_pRenderer;
	std::string m_name;
	bool m_isLoaded;

	friend class GameManager;
};

#endif // !SHROOM_ENGINE_SCENE_H
