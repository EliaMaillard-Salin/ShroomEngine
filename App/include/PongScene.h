#ifndef APP_PONG_SCENE_H
#define APP_PONG_SCENE_H

#include <Scene.h>
#include <Vectors.h>


class PongScene : public shroom::Scene
{
public:
	PongScene(const char* name);

	void OnRender() override;
	void OnInputCalled(SDL_Event event) override;

	shroom::Vector2f startingPos;
};

#endif // !APP_PONG_SCENE_H
