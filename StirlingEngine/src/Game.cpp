#include "Game.h"

namespace StirlingEngine
{
	Game::Game() {}

	Game::~Game() {}

	void Game::Run()
	{
		OnStart();

		while (true)
		{
			OnUpdate();
		}

		OnExit();
	}
}