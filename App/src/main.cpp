


#define SDL_MAIN_HANDLED

#include "Logger.h"
#include "Define.h"
#include <Vectors.h>
#include <GameManager.h>

int main()
{
	GameManager GM("AAAA", { 500, 500 });
	GM.Init();
	GM.Launch();
	
	return 0;
}