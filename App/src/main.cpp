


#define SDL_MAIN_HANDLED

#include "Logger.h"
#include "Define.h"
#include <Vectors.h>
#include <GameManager.h>

#include "PongScene.h"

using namespace shroom;

int main()
{
	GameManager GM("AAAA", { 500, 500 });
	GM.Init();
	Scene* scene = new PongScene("PongScene");
	GM.AddSceneInGameManager(*scene);
	GM.SetActiveScene("PongScene");
	GM.Launch();
	return 0;
}