#include "PongScene.h"
#include <Renderer.h>
#include <Drawable2DShapes.h>
#include "PlayerScript.h"
#include "EnemyScript.h"
#include "Components.h"
#include "Time.h"

using namespace shroom;

PongScene::PongScene(const char* name) : Scene(name)
{
	startingPos = { 250.0f,475.0f };

	Actor& player = CreateActor();
	player.GetTransform().SetPosition(startingPos);
	player.AddComponent<PlayerScript>("PlayerScript");
	BoxCollider& bPlayer = player.AddComponent<BoxCollider>("Box");
	bPlayer.SetTag(0);
	player.SetStatic(false);
}

void PongScene::OnUpdate()
{
	enemyCD += Time::deltaTime;
	if (enemyCD >= maxEnemy_CD)
	{
		enemyCD = 0.0f;
		SpawnEnemy();
	}
}

void PongScene::OnRender()
{
}

void PongScene::SpawnEnemy()
{
	Actor& enemy = CreateActor();
	enemy.GetTransform().SetPosition({ 250.0f,50.0f });
	enemy.AddComponent<EnemyScript>("EnemyScript");
	BoxCollider& bPlayer = enemy.AddComponent<BoxCollider>("Box");
	bPlayer.SetTag(1);
	enemy.SetStatic(false);
}