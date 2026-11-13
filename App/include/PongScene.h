#ifndef APP_PONG_SCENE_H
#define APP_PONG_SCENE_H

#include <Scene.h>
#include <Vectors.h>


class PongScene : public shroom::Scene
{
public:
	PongScene(const char* name);
	void SetPongScene();
	void OnUpdate() override;
	void OnRender() override;

	void SpawnEnemy();

	shroom::Vector2f startingPos;

private:
	float enemyCD = 0.0f;
	float maxEnemy_CD = 5.0f;
};

#endif // !APP_PONG_SCENE_H
