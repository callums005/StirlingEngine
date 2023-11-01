#include <stdio.h>

#include "Game.h"

extern StirlingEngine::Game* StirlingEngine::CreateGame();

int main()
{
	StirlingEngine::Game* app = StirlingEngine::CreateGame();
	app->Run();
	delete app;
	return 0;
}