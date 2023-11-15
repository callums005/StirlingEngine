#pragma once

#include <stdio.h>
#include <string>

#include "Game.h"

extern StirlingEngine::Game *StirlingEngine::CreateGame();

int main()
{
	StirlingEngine::Game *app = StirlingEngine::CreateGame();

	app->SetWindow(1920, 1080, std::string("Default Window Settings - Call SetWindow() in constructor"), false);
	app->Run();
	delete app;
	return 0;
}