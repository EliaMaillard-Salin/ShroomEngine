#include "PongScene.h"
#include <Renderer.h>
#include <Drawable2DShapes.h>
#include <Window.h>
#include "PlayerScript.h"
#include "EnemyScript.h"
#include "Components.h"
#include "Time.h"
#include "GameManager.h"
#include "Ball.h"

using namespace shroom;

PongScene::PongScene(const char* name) : Scene(name)
{
	startingPos = { 475,250.0f };

	Actor& player = CreateActor();
	player.GetTransform().SetPosition(startingPos);
	player.GetTransform().SetScale(1.0f,7.0f);
	PlayerScript& script1 = player.AddComponent<PlayerScript>("PlayerScript");
	script1.SetKeyToMove(SDL_KeyCode::SDLK_UP, SDL_KeyCode::SDLK_DOWN);
	BoxCollider& bPlayer = player.AddComponent<BoxCollider>("Box");
	bPlayer.SetTag(0);
	player.SetStatic(false);


	Actor& player2 = CreateActor();
	player2.GetTransform().SetPosition({25.0f,250.0f});
	player2.GetTransform().SetScale(1.0f, 7.0f);
	PlayerScript& script2 = player2.AddComponent<PlayerScript>("PlayerScript");
	script2.SetKeyToMove(SDL_KeyCode::SDLK_z, SDL_KeyCode::SDLK_s);
	BoxCollider& bPlayer2 = player2.AddComponent<BoxCollider>("Box");
	bPlayer2.SetTag(0);
	player2.SetStatic(false);

}

void PongScene::OnUpdate()
{
	return;
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
void PongScene::SetPongScene()
{
	Vector2<uint16> vec = m_pGameManager->GetWindow().GetDimensions();
	Actor& middleBar = CreateActor();
	middleBar.GetTransform().SetPosition({ vec.X() / 2.0f,0.0f });
	middleBar.GetTransform().SetScaleY(vec.Y());
	middleBar.GetTransform().SetScaleX(1.0f);


	Actor& Ball = CreateActor();
	Ball.GetTransform().SetPosition({ 300.0f, 10.0f });
	BallScript& s = Ball.AddComponent<BallScript>("fds");
	s.SetScreenDimensions(vec);
	Ball.AddComponent<BoxCollider>("fdg");
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